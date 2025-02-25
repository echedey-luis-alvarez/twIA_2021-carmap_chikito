/*  Project: CarMap - Chikito
 *  This file is the main program for the robot Chikito.
 */

// Definiciones tipos movimientos
#define MOVE_forward (char)1
#define MOVE_backward (char)2
#define MOVE_left (char)3
#define MOVE_right (char)4

//Motor 1 es el motor de la derecha
#define motor1_IZQ 6
#define motor1_DER 7

//Motor 2 es el motor de la izquierda
#define motor2_IZQ 8
#define motor2_DER 9

void setup()
{
  // Tareas de configuración 
  Serial.begin(9600);

  pinMode(motor1_IZQ,OUTPUT);
  pinMode(motor1_DER,OUTPUT);
  
  pinMode(motor2_IZQ,OUTPUT);
  pinMode(motor2_DER,OUTPUT);
}

//Prototipos de función de movimiento
void parar();
void delante();
void atras();
void derecha();
void izquierda();

//Prototipos de función de motores
void motor1DER();
void motor1IZQ();

void motor2DER();
void motor2IZQ();

void motor1PARA();
void motor2PARA();

void loop()
{
  if (Serial.available() > 0)  // Si hay mensajes procedentes del PC  
    procesar_accion();
    
  delay(50);
} 

// Resto de acciones
int procesar_accion(void)
{
  String cadena = Serial.readStringUntil('\n'); // Lee mensaje, formateado como línea de un archivo CSV
  cmd = strtok(cadena, ",");
  if(!strcmp(cmd, "t"))
  {
    // Proto is time
    unsigned int tiempoMilis = 0;
    char moveType = 0;
    cmd = strtok(NULL, ",");
    if(!strcmp(cmd, "lin"))
    {
      // Movimiento lineal
      moveType = 2;
    }
    else if(!strcmp(cmd, "rot"))
    {
      // Movimiento rotacional
      moveType = 4;
    }
    else
      return 2;

    cmd = strtok(NULL, ",");
    if(!strcmp(cmd, "del") or !strcmp(cmd, "izq")) // Warning: this doesn't verify whether del/atr or izq/der are consistent with types lin and rot respectively
      moveType--;
    else if(strcmp(cmd, "atr") and strcmp(cmd, "der")) // Second argument is not any of these or previous, so return an error
      return 4;

    cmd = strtok(NULL, ",");
    tiempoMilis = atoi(cmd);

    switch (moveType) // Realizamos el movimiento
    {
      case MOVE_forward:
        delante();
        break;
      case MOVE_backward:
        detras();
        break;
      case MOVE_left:
        izquierda();
        break;
      case MOVE_right:
        derecha();
        break;
    }
    delay(tiempoMilis);
    parar();
  }
  else
    return 1;
  /* if(cadena[0]=='t' && cadena[1]==':') 
  {
    for(int i=0;i<3;i++)
    {
      movimiento[i]=cadena[i+2];
    }
    movimiento[3]=0;
    for(int j=0;j<3;j++)
    {
      sentido[j]=cadena[j+6];
    }
    sentido[3]=0;
    for(int k=0;k<5;k++)
    {
      tiempo[k]=cadena[k+11];
    }
    tiempo[5]=0;
    tiempoMilis= atoi(tiempo);
    if(strcmp(movimiento,"lin")==0)
    {
      if(strcmp(sentido,"del")==0){
        delante(); //Movimiento lineal hacia delante
      }
      else if(strcmp(sentido,"atr")==0){
        atras(); //Movimiento lineal hacia atrás
        
      }
      else{
      //Error
      return 20;  
      }
    }
    else if(strcmp(movimiento,"rot")==0){
      if(strcmp(sentido,"der")==0){
        derecha(); //Movimiento rotacional hacia la derecha
      }
      else if(strcmp(sentido,"izq")==0){
        izquierda(); //Movimiento rotacional hacia la izquierda
      }
      else{
        //Error
        return 15;
      }
    }
    else{
      //Error
      return 10;
    }
  }
  else{
    //Error
    return 1;
  }
  delay(tiempoMilis);
  parar(); //Parar*/
  return 0;
}

//Cuerpos de funciones de movimiento
void parar()
{
  motor1PARA();  
  motor2PARA();
}

void delante()
{
  motor1DER();
  motor2IZQ();
}

void atras()
{
  motor1IZQ();
  motor2DER();
}

void derecha()
{
  motor1DER();  
  motor2DER();
}

void izquierda()
{
  motor1IZQ();
  motor2IZQ();
}

//Cuerpos de funciones de motores
void motor1DER()
{
  digitalWrite(motor1_IZQ,LOW);
  digitalWrite(motor1_DER,HIGH);
}

void motor1IZQ()
{
  digitalWrite(motor1_IZQ,HIGH);
  digitalWrite(motor1_DER,LOW);
}

void motor2DER()
{
  digitalWrite(motor2_IZQ,LOW);
  digitalWrite(motor2_DER,HIGH);
}

void motor2IZQ()
{
  digitalWrite(motor2_IZQ,HIGH);
  digitalWrite(motor2_DER,LOW);
 
}

void motor1PARA()
{
  digitalWrite(motor1_IZQ,LOW);
  digitalWrite(motor1_DER,LOW);
}

void motor2PARA()
{
  digitalWrite(motor2_IZQ,LOW);
  digitalWrite(motor2_DER,LOW); 
}
