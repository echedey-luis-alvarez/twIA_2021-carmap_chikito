/*  Main-mapeador.c : This file contains the 'main' function. Program execution begins and ends here.
*/


#include <stdio.h> // Standard I/O
#include <stdlib.h>
#include <string.h>
#include <wchar.h> // Para usar los caracteres amplios (modificaci�n y paso de valores a SerialClass.h)
#include <iso646.h> // "||" se puede escribir como "or" y "&&" como "and" - legibilidad: https://cplusplus.com/reference/ciso646/
#include <math.h> // Funciones matem�ticas
#include <stdbool.h>// Usamos variables booleanas para el tipo de movimiento y su sentido
#include <conio.h>
#include <windows.h> // Para hacer el mapeador con la funcion gotoxy junto con la libreria conio.h

#include "libs/vector.h" // Custom library to create and operate vectors easily
#include "libs/SerialClass.h" // Retrieved from: https://github.com/Gmatarrubia/LibreriasTutoriales (modified local resources)
#include "libs/waypoints_filehandler.h" // Librer�a para almacenar la trayectoria del robot en archivos binarios
#include "libs/robot.h"
#include "libs/mapper.h"
#include "libs/gotoxy.h"

// Bluetooth definitions
#define PORT_SZ 15 // Port wide character string size
#define BUF 200
//Commands
#define MOV_lineal true
#define MOV_haciaDelante true
#define MOV_haciaAtras false

#define MOV_rotacion false
#define MOV_haciaIzq true
#define MOV_haciaDer false

// Alternatives
#define MOVE_forward (char)1
#define MOVE_backward (char)2

#define MOVE_left (char)3
#define MOVE_right (char)4

// Keys numbers
#ifndef KeyBrdLIB
#define KeyBrdLIB

#define Key_TAB 9
#define Key_ENTER 13
#define Key_ESC 27
#define Arrow_UP 72
#define Arrow_LEFT 75
#define Arrow_RIGHT 77
#define Arrow_DOWN 80

#endif // !Key numbers

// File handling definitions
#define NAME_SZ 50
// #define WP_PATH "WAYPOINTS" // Unused: in case files are saved into specific folder, use this folder name

// Math definitions
#define M_PI 3.14159265358979323846 // Pi
#define DEF_PRECISION 5 // Default precision to use when printing decimals

//// Program functions ////

// Bluetooth oriented
void getCOM_port_s(wchar_t*, size_t);
    /* Obtiene puerto COM desde stdin; args.:
    * puntero a cadena de caracteres anchos donde se guarda el puerto a utilizar
    * tama�o max de la cadena
    */

int command_Arduino_time_s(char* buffer, size_t sz, bool tipoMovimiento, bool sentido, unsigned int tiempoMilis);
    /* Genera comando con formato "t:tipo_movimiento,sentido,tiempo;"
    *   -tipo_movimiento: lin o rot
    *   -sentido: del, atr, izq o der
    *   -tiempo: <= 32767 millis
    * el tama�o m�nimo de buffer (sz) es 18
    * tipoMovimiento: MOV_lineal o MOV_rotacion
    * sentido: MOV_haciaDelante, MOV_haciaAtras, MOV_haciaIzq o MOV_haciaDer
    * tiempoMillis: max 5 cifras
    */

// GUI functions
void clearScreen(int numberofCharactersYouWantToClearInConsole); // Self-explanatory

// Robot functions
int rb_moveByDefs(robot* rb, char move, char* buffer, size_t sz, unsigned int* calculatedDuration);

int main() // Main function
{
    // This is where fun BEGINS

    // Bluetooth conection variables
    Serial* Arduino;
    wchar_t puerto[PORT_SZ];
    char BufferSalida[BUF] = "\0", BufferEntrada[BUF] = "\0", cadena[BUF] = "\0";
    unsigned int contador = 0, millisWait = 0;

    // Filehandling variables
    FILE* fp_puntos = NULL;
    char* nombreArchivoPuntos = (char*)calloc(NAME_SZ, sizeof(char));

    // Robot properties
    robot* rb = (robot*)calloc(1, sizeof(robot));
    if (!rb) return 20;
    rb->position = { 0, 0 };
    rb->angle = 0;
    rb->physical.vel.lineal = 0.2;
    rb->physical.vel.angular = 1;
    rb->defMoves.linMove = 0.10;
    rb->defMoves.rotAngle = M_PI / 2;
    robot_print_all(rb, DEF_PRECISION);

    // User-input, GUI and general purpouse vars
    int puls = 0;
    char status = 0;
    mapGrid map = { 25, 30 };
    COORD bufOutPos = { map.originX, map.originY };

    // Begin getting port number to use
    getCOM_port_s(puerto, PORT_SZ); // Men� que obtiene el nombre del puerto a usar
    printf("\nLa comunicacion se realizara a traves del puerto %ws\n", puerto); // Imprime en pantalla el puerto que se est� usando

    Arduino = new Serial(puerto); // Intentamos conectar el Arduino por el puerto Bluetooth que especifica el usuario

    if ( Arduino->IsConnected() ) { // Solo si el Arduino se puede conectar, se crea un archivo para guardar el progreso
        // Initializing file to be written
        int error = waypts_bcreate_file(&fp_puntos, NAME_SZ, MODE_TIMESTAMP, nombreArchivoPuntos);

        if (error == 100) { // Fallo asignando memoria din�mica
            printf("Error in memory assignment. Big oof for the programmer trying to figure this out.");
            return 31;
        }
        else if (error == 150) { // Indica que el nombre especificado es inapropiado. Definido en funci�n local
            printf("Error creating file: name is not supported in source code.");
            return 32;
        }
        else if (error != 0) {
            printf("Unexpected error creating file.");
            return 30;
        }

        if (!fp_puntos) { // fp_puntos es NULL si hubo alg�n error
            printf("Error creating/opening file. File might already exist. Error number: %d", error);
            return 35;
        }
        else { // Arduino est� conectado y el fichero fue creado sin errores
            printf("Arduino conectado\n");
            printf("Fichero con trayectoria: %s\n", nombreArchivoPuntos);
        }
    }
    else { // No se pudo conectar
        printf("Couldn't connect to Arduino.");
        return 40;
    }

    // Imprimir controles
    printf("Controls:\nMove Forward and Backward with Up and Down arrows\nRotate with Left and Right arrows\nPress any key to continue...\n");
    
    // Esperamos pulsacion para continuar
    (void)_getch();

    // Limpieza de lo escrito previamente
    for (register unsigned int i = 0; i < 35; i++) {
        gotoxy(0, i);
        clearScreen(70);
    }

    // Dibujar ejes del mapa
    map_mapAxisPrint(&map);

    // Procesamiento de todo el algoritmo: entrada, procesamiento, salida en bucle
    while ( Arduino->IsConnected() and status != 255) // Mientras el Arduino est� conectado se puede proceder
    {
        // Entrada de datos - pulsaciones del teclado
        puls = _getch();

        switch (puls) {
        case EOF:
        case Key_ESC:
            fclose(fp_puntos);
            Arduino->~Serial();
            (puls == Key_ESC) ? exit(EXIT_SUCCESS) : exit(EXIT_FAILURE);

        case 224: // Special key
            switch (_getch())
            {
            case Arrow_UP:
                status = MOVE_forward;
                break;
            case Arrow_DOWN:
                status = MOVE_backward;
                break;
            case Arrow_LEFT:
                status = MOVE_left;
                break;
            case Arrow_RIGHT:
                status = MOVE_right;
                break;
            default:
                break;
            }
            break;

        case 'n':
        case 's':
        case 'o':
        case 'e':
            gotoxy(0, 2);
            printf("The use of the key '%c' is deprecated.", puls);
        default:
            status = 0;
            break;
        }

        if (rb_moveByDefs(rb, status, BufferSalida, BUF, &millisWait) == 0) {
            // Enviar comando al robot
            Arduino->WriteData(BufferSalida, BUF);

            // Guardar vector posición
            waypts_bappend_vect(fp_puntos, &rb->position);

            // Imprimir información por pantalla
            gotoxy(0, 0);
            robot_print_summary(rb, DEF_PRECISION);

            // Esperamos a que se mueva el robot
            gotoxy(0, 3);
            printf("Waiting...");
            gotoxy_coord(&bufOutPos);
            Sleep(millisWait);
            gotoxy(0, 3);
            clearScreen(12);

            // Mostrar robot en la nueva posición
            map_rbPrintFromRobot(&map, rb);
            getCursorPos(&bufOutPos);
        }
        
        contador++;
    }

    // Cerramos el archivo
    fclose(fp_puntos);

    return 0; // Exit without errors
}

void getCOM_port_s(wchar_t* dest, size_t max) {
    unsigned char status = 0, portNumber = 0;

    do { // Menu para indicar el puerto
        printf("Escriba nombre del puerto serie a conectar: COM");
        fseek(stdin, 0, SEEK_END);
        status = scanf_s("%hhu", &portNumber);
    } while (status == 0 or portNumber == 0);

    swprintf_s(dest, PORT_SZ, L"\\\\.\\COM%hhu", portNumber);

    return; // Fin de obtener puerto.
}

int command_Arduino_time_s(char* buffer, size_t sz, bool tipoMovimiento, bool sentido, unsigned int tiempoMilis) {
    if (sz < 18) return STRUNCATE; // El tama�o del comando es m�nimo 17 contando el car�cter terminador, ej. "t:rot,izq,02035;\0"
    if (tiempoMilis > 32767) return EDOM; // El tama�o de un int en el Arduino ocupa 2 bytes. Sobrepasar este n�mero produce un comportamiento indefinido en el Arduino
    char mov[4], sent[4]; // Aqu� se almacenan los cachos de texto que luego se mandan al Robot
    if (tipoMovimiento) { // Es desplazamiento
        strcpy_s(mov, "lin");
        if (sentido) { // Hacia delante
            strcpy_s(sent, "del");
        }
        else { // Hacia atr�s
            strcpy_s(sent, "atr");
        }
    }
    else { // Es rotacion
        strcpy_s(mov, "rot");
        if (sentido) { // Hacia la izquierda
            strcpy_s(sent, "izq");
        }
        else { // Hacia la derecha
            strcpy_s(sent, "der");
        }
    }
    sprintf_s(buffer, sz, "t:%s,%s,%5u;", mov, sent, tiempoMilis);
    return 0;
}

int rb_moveByDefs(robot* rb, char move, char* buffer, size_t sz, unsigned int *duration) {
    if (move == MOVE_forward or move == MOVE_backward) {
        vector2D movement = vector2D_productByScalar(vector2D_rotate({ 1, 0 }, rb->angle), rb->defMoves.linMove);
        if (move == MOVE_forward) {
            rb->position = vector2D_add(rb->position, movement);
        }
        else {
            rb->position = vector2D_substract(rb->position, movement);
        }

        command_Arduino_time_s(buffer, sz, MOV_lineal, 
            (move == MOVE_forward) ? MOV_haciaDelante : MOV_haciaAtras, (*duration = (unsigned int) rint(rb->defMoves.linMove / rb->physical.vel.lineal * 1000) ) );
    }
    else if (move == MOVE_left or move == MOVE_right) {
        if (move == MOVE_left) {
            rb->angle += rb->defMoves.rotAngle;
        }
        else {
            rb->angle -= rb->defMoves.rotAngle;
        }
        if (fabs(rb->angle) == 2 * M_PI) rb->angle = 0;

        command_Arduino_time_s(buffer, sz, MOV_rotacion, 
            (move == MOVE_left) ? MOV_haciaIzq : MOV_haciaDer, (*duration = (unsigned int) rint(rb->defMoves.rotAngle / rb->physical.vel.angular * 1000) ) );
    }
    else {
        return -1;
    }
    return 0;
}

void clearScreen(int spaces) {
    for (long i = 0; i < spaces; i++) {
        putchar(' ');
    }
    return;
}
