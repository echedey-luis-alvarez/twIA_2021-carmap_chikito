
/*  Project: CarMap - Chikito
 *  This file is the main program for the macro keyboard.
 */

#include <Keyboard.h>

/*"north/south/east/west" buttons: press to move robot*/
#define N 7
#define S 8
#define E 9
#define O 10

/*initializes Serial and sets button pins as input*/
void setup() {
  Serial.begin(9600); while(!Serial){;}
  const int arrowpad[]={N,S,E,O}; int i;
  for(i=0;i<(sizeof(arrowpad)/sizeof(int));i++){ pinMode(arrowpad[i],INPUT_PULLUP); }
  Keyboard.begin();
  }

/*push buttons trigger the corresponding Macros when pressed*/
void loop(){
  const int buttons[]={N,S,E,O};
  int buttons_states[]={HIGH,HIGH,HIGH,HIGH},buttons_now=HIGH,i;
  for(i=0;i<(sizeof(buttons_states)/sizeof(int));i++){
    buttons_now=digitalRead(buttons[i]);
    if(buttons_now==LOW&&buttons_states[i]==HIGH) {
      delay(50); buttons_now=digitalRead(i);
      if(buttons_now==LOW) key(i+1);
      }
    }
  }

void key(int i){
  switch(i){
    case 1:north();break;
    case 2:south();break;
    case 3:east();break;
    case 4:west();break;
    default:break;
    }
  }
void north(){
  Keyboard.press('N');
  delay(500);
  Keyboard.release('N');
  }
void south(){
  Keyboard.press('S');
  delay(500);
  Keyboard.release('S');
  }
void east(){
  Keyboard.press('E');
  delay(500);
  Keyboard.release('E');
  }
void west(){
  Keyboard.press('O');
  delay(500);
  Keyboard.release('O');
}
