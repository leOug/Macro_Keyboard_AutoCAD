#include "Keyboard.h"

#define BUTTON_1 3
#define BUTTON_2 4
#define BUTTON_3 5
#define BUTTON_4 6
#define BUTTON_5 7
#define BUTTON_6 10
#define BUTTON_7 14
#define BUTTON_8 15
#define BUTTON_9 16
#define BUTTON_10 2
#define BUTTON_11 8
int POTENTIOMETER_1 = A0;
int potentiometer_value;
#define SELECTOR_A1 A1
int selector_switch_value = 0; //The selector switch controls the functions of the arcade and the 3d printer buttons

int state = 1; // The initial state of the buttons

// 3 LED pins for the RGB LED, used as a visual indicator
#define LED_1 9
#define LED_2 A2
#define LED_3 A3

void setup()
{
  Serial.begin(9600); // Beging Serial Comunication
  //Define the pinMode for each pin.
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(10, INPUT);
  pinMode(14, INPUT);
  pinMode(15, INPUT);
  pinMode(16, INPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(9, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  
  

  //Sets the value of the pin on start up.
 
  digitalWrite(BUTTON_1, HIGH);
  digitalWrite(BUTTON_2, HIGH);
  digitalWrite(BUTTON_3, HIGH);
  digitalWrite(BUTTON_4, HIGH);
  digitalWrite(BUTTON_5, HIGH);
  digitalWrite(BUTTON_6, HIGH);
  digitalWrite(BUTTON_7, HIGH);
  digitalWrite(BUTTON_8, HIGH);
  digitalWrite(BUTTON_9, HIGH);
  digitalWrite(POTENTIOMETER_1, HIGH);
  digitalWrite(BUTTON_10, HIGH);
  digitalWrite(BUTTON_11, HIGH);
  digitalWrite(LED_1, LOW);
  digitalWrite(LED_2, LOW);
  digitalWrite(LED_3, LOW);
  
  Keyboard.begin(); //Turns the keyboard input on.
  delay(200); //Wait before continuing on with the code.

}

void loop()

{
  
selector_switch_value = analogRead(SELECTOR_A1);
// If the button is pressed the state variable changes indicating a push
  state = digitalRead(BUTTON_8);
  // The selector switch is treated a potentiometer with two values, 0 and maximum
  // So i put a check for a median value to indicate the open and closing of the switch
  if(state != 1 && selector_switch_value < 500)
  {
    Keyboard.press(KEY_ESC);
    digitalWrite(LED_1, HIGH);
    delay(200);
    digitalWrite(LED_1, LOW);
    delay(50);
    Keyboard.releaseAll();
  }
  else if (state != 1 && selector_switch_value > 500)
  {
    Keyboard.print("qsave");
    digitalWrite(LED_3, HIGH);
    delay(200);
    Keyboard.press(KEY_RETURN);
    digitalWrite(LED_3, LOW);
    delay(50);
    Keyboard.releaseAll();
  }
 state = digitalRead(BUTTON_11);
  if(state != 1 && selector_switch_value < 550)
  {
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
    digitalWrite(LED_3, HIGH);
    delay(200);
    digitalWrite(LED_3, LOW);
    delay(50);
    ;
  }
  else if (state != 1 && selector_switch_value > 500)
  {
    delay(200);
    Keyboard.press(KEY_DELETE);
    //Keyboard.press(KEY_LEFT_SHIFT);
    //Keyboard.press(KEY_LEFT_GUI);
   digitalWrite(LED_2,HIGH);
    //Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
    digitalWrite(LED_2, LOW);
  }
//BEGIN FIRST PRESET
  potentiometer_value = analogRead(POTENTIOMETER_1);
  // The actual potentiometer is used to change between the presets.
  //By reading the potentiometer value (between 15 and 1023 for the B100k) i create 5 distinct "zones"
  //For each zone the 9 push buttons are assigned a function.
  //When the potentiometer is within the boundaries of the assigned zone, the LED changes colour
  if (potentiometer_value < 350 && potentiometer_value > 0) {
  //When the potentiometer is within the boundaries of the assigned zone, the LED changes colour
  digitalWrite(LED_2, LOW);
  digitalWrite(LED_3, HIGH);
  digitalWrite(LED_1, LOW);
  
  state = digitalRead(BUTTON_1);
  if(state != 1 && potentiometer_value < 350 && potentiometer_value>0)
  //FIRST PRESET
  {
  
    Keyboard.print("startcenter");
    delay(100);
    Keyboard.releaseAll();
    Keyboard.print("direction");
    Keyboard.releaseAll();
    delay(50);
    Keyboard.print("arc");
    delay(50);
    Keyboard.press(KEY_RETURN);
    delay(100);
    Keyboard.releaseAll();
  }
//FIRST PRESET
  state = digitalRead(BUTTON_2);
  if(state != 1 && potentiometer_value < 350 && potentiometer_value>0)
  {
    Keyboard.print("circle"); 
    delay(200);
    Keyboard.press(KEY_RETURN);
    delay(200);
    Keyboard.releaseAll();
  }
//FIRST PRESET

  state = digitalRead(BUTTON_3);
  if(state != 1 && potentiometer_value < 350 && potentiometer_value>0)
  {
    Keyboard.print("rectangle"); 
    delay(200);
    Keyboard.releaseAll();
    delay(300);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
    
  }
//FIRST PRESET

  state = digitalRead(BUTTON_4);
  if(state != 1 && potentiometer_value < 350 && potentiometer_value>0)
  {
    delay(100);
    Keyboard.print("scale"); 
    Keyboard.press(KEY_RETURN);
    delay(200);
    Keyboard.releaseAll();
  }
//FIRST PRESET

  state = digitalRead(BUTTON_5);
  if(state != 1 && potentiometer_value < 350 && potentiometer_value>0)
  {
    Keyboard.print("polygon"); 
    Keyboard.press(KEY_RETURN);
    delay(200);
    Keyboard.releaseAll();
  }
//FIRST PRESET

  state = digitalRead(BUTTON_6);
  if(state != 1 && potentiometer_value < 350 && potentiometer_value>0)
  {
    Keyboard.print("copy"); 
    Keyboard.press(KEY_RETURN); 
    delay(200);
    Keyboard.releaseAll();
  }
//FIRST PRESET

  state = digitalRead(BUTTON_7);
  if(state != 1 && potentiometer_value < 350 && potentiometer_value>0)
  {
    Keyboard.print("move");
    Keyboard.press(KEY_RETURN);
    delay(200);
    Keyboard.releaseAll();
  }
//FIRST PRESET

  state = digitalRead(BUTTON_10);
  if(state != 1 && potentiometer_value < 350 && potentiometer_value>0)
  {
    Keyboard.print("line"); 
    Keyboard.press(KEY_RETURN);
    delay(200);
    Keyboard.releaseAll();
  }
//FIRST PRESET

  state = digitalRead(BUTTON_9);
  if(state != 1 && potentiometer_value < 350 && potentiometer_value>0)
  {
     Keyboard.print("default");
    delay(100);
    Keyboard.print("gizmo");
    delay(100);
    Keyboard.press(KEY_RETURN);
    delay(300);
    Keyboard.releaseAll();
    Keyboard.press('0');
    delay(50);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
  }
  
//END OF FIRST PRESET
  }
//BEGIN SECOND PRESET 
  else if (potentiometer_value < 600 && potentiometer_value>401) {

  digitalWrite(LED_2, HIGH);
  digitalWrite(LED_3, LOW);
  digitalWrite(LED_1, LOW);
  
  state = digitalRead(BUTTON_1);
  if(state != 1 && potentiometer_value < 600 && potentiometer_value>401)
//SECOND PRESET   
  {
    Keyboard.print("join");
    delay(100);
    Keyboard.releaseAll();
    Keyboard.press(KEY_RETURN);
    delay(200);
    Keyboard.releaseAll();
  }
//SECOND PRESET   

  state = digitalRead(BUTTON_2);
  if(state != 1 && potentiometer_value < 600 && potentiometer_value>401)
  {
    Keyboard.print("array"); 
    delay(200);
    Keyboard.press(KEY_RETURN);
    delay(200);
    Keyboard.releaseAll();
  }
//SECOND PRESET  
  state = digitalRead(BUTTON_3);
 if(state != 1 && potentiometer_value < 600 && potentiometer_value>401)
  {
    Keyboard.print("trim"); 
    delay(200);
    Keyboard.releaseAll();
    delay(100);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
    
  }
//SECOND PRESET  
  state = digitalRead(BUTTON_4);
 if(state != 1 && potentiometer_value < 600 && potentiometer_value>401)
  {
    Keyboard.print("pedit"); 
    delay(300);
    Keyboard.press(KEY_RETURN); 
    delay(200);
    Keyboard.releaseAll();
  }
//SECOND PRESET  
  state = digitalRead(BUTTON_5);
  if(state != 1 && potentiometer_value < 600 && potentiometer_value>401)
  {
    Keyboard.print("explode"); 
    Keyboard.press(KEY_RETURN);
    delay(200);
    Keyboard.releaseAll();
  }
//SECOND PRESET  
  state = digitalRead(BUTTON_6);
 if(state != 1 && potentiometer_value < 600 && potentiometer_value>401)
  {
    Keyboard.print("copy"); 
    Keyboard.press(KEY_RETURN); 
    delay(200);
    Keyboard.releaseAll();
  }
//SECOND PRESET  
  state = digitalRead(BUTTON_7);
  if(state != 1 && potentiometer_value < 600 && potentiometer_value>401)
  {
    Keyboard.print("move");
    Keyboard.press(KEY_RETURN);
    delay(200);
    Keyboard.releaseAll();
  }
//SECOND PRESET  
  state = digitalRead(BUTTON_10);
  if(state != 1 && potentiometer_value < 600 && potentiometer_value>401)
  {
    Keyboard.print("offset"); 
    Keyboard.press(KEY_RETURN);
    delay(200);
    Keyboard.releaseAll();
  }
//SECOND PRESET  
  state = digitalRead(BUTTON_9);
  if(state != 1 && potentiometer_value < 600 && potentiometer_value>401)
  {
    Keyboard.print("default");
    delay(100);
    Keyboard.print("gizmo");
    delay(100);
    Keyboard.press(KEY_RETURN);
    delay(300);
    Keyboard.releaseAll();
    Keyboard.press('1');
    delay(50);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
  }
  //END OF SECOND PRESET
  }
  //BEGIN THIRD PRESET
  else if (potentiometer_value < 800 && potentiometer_value > 601  ) {
   digitalWrite(LED_2,LOW);
  digitalWrite(LED_3, LOW);
  digitalWrite(LED_1, HIGH);
// THIRD PRESET
  state = digitalRead(BUTTON_1);
  if(state != 1 && potentiometer_value < 800 && potentiometer_value>601)
  
  {
    Keyboard.print("extrude");
    delay(100);
    Keyboard.press(KEY_RETURN);
    delay(200);
    Keyboard.releaseAll();
  }
// THIRD PRESET

  state = digitalRead(BUTTON_2);
 if(state != 1 && potentiometer_value < 800 && potentiometer_value>601)
  {
    delay(100);
    Keyboard.print("measuredistance"); 
    delay(200);
    Keyboard.press(KEY_RETURN);
    delay(200);
    Keyboard.releaseAll();
  }
// THIRD PRESET

  state = digitalRead(BUTTON_3);
  if(state != 1 && potentiometer_value < 800 && potentiometer_value>601)
  {
    Keyboard.print("cylinder"); 
    delay(200);
    Keyboard.press(KEY_RETURN);
    delay(200);
    Keyboard.releaseAll();
    
  }
// THIRD PRESET

  state = digitalRead(BUTTON_4);
  if(state != 1 && potentiometer_value < 800 && potentiometer_value>601)
  {
    Keyboard.print("sweep"); 
    delay(300);
    Keyboard.press(KEY_RETURN); 
    delay(200);
    Keyboard.releaseAll();
  }
// THIRD PRESET

  state = digitalRead(BUTTON_5);
  if(state != 1 && potentiometer_value < 800 && potentiometer_value>601)
  {
    
    Keyboard.print("presspull");
    delay(100); 
    Keyboard.press(KEY_RETURN);
    delay(200);
    Keyboard.releaseAll();
  }
// THIRD PRESET

  state = digitalRead(BUTTON_6);
  if(state != 1 && potentiometer_value < 800 && potentiometer_value>601)
  {
    Keyboard.print("copy"); 
    Keyboard.press(KEY_RETURN); 
    delay(200);
    Keyboard.releaseAll();
  }
// THIRD PRESET

  state = digitalRead(BUTTON_7);
  if(state != 1 && potentiometer_value < 800 && potentiometer_value>601)
  {
    Keyboard.print("move");
    Keyboard.press(KEY_RETURN);
    delay(200);
    Keyboard.releaseAll();
  }
// THIRD PRESET

  state = digitalRead(BUTTON_10);
  if(state != 1 && potentiometer_value < 800 && potentiometer_value>601)
  {
    Keyboard.print("box"); 
    Keyboard.press(KEY_RETURN);
    delay(200);
    Keyboard.releaseAll();
  }
// THIRD PRESET

  state = digitalRead(BUTTON_9);
  if(state != 1 && potentiometer_value < 800 && potentiometer_value>601)
  {
    Keyboard.print("default");
    delay(100);
    Keyboard.print("gizmo");
    delay(100);
    Keyboard.press(KEY_RETURN);
    delay(300);
    Keyboard.releaseAll();
    Keyboard.press('0');
    delay(50);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
  }
 
  }

  //BEGIN FOURTH PRESET 
  else if (potentiometer_value < 1000 && potentiometer_value > 801) {

  digitalWrite(LED_2, HIGH);
  digitalWrite(LED_3, HIGH);
  digitalWrite(LED_1, LOW);
  
  state = digitalRead(BUTTON_1);
  if(state != 1 && potentiometer_value < 1000 && potentiometer_value > 801)
  
  {
    
    Keyboard.print("union");
    delay(100);
    Keyboard.releaseAll();
    Keyboard.press(KEY_RETURN);
    delay(200);
    Keyboard.releaseAll();
  }
// FOURTH PRESET 
  state = digitalRead(BUTTON_2);
  if(state != 1 && potentiometer_value < 1000 && potentiometer_value > 801)
  {
    delay(100);
    Keyboard.print("measuredistance");
    delay(100);
    Keyboard.releaseAll();
    Keyboard.press(KEY_RETURN);
    delay(200);
    Keyboard.releaseAll();
  }
// FOURTH PRESET 

  state = digitalRead(BUTTON_3);
 if(state != 1 && potentiometer_value < 1000 && potentiometer_value > 801)
  {
     Keyboard.print("substract");
    delay(200);
    Keyboard.releaseAll();
  }
// FOURTH PRESET 

  state = digitalRead(BUTTON_4);
 if(state != 1 && potentiometer_value < 1000 && potentiometer_value > 801)
  {
    Keyboard.print("slice"); 
    delay(300);
    Keyboard.press(KEY_RETURN); 
    delay(200);
    Keyboard.releaseAll();
  }
// FOURTH PRESET 

  state = digitalRead(BUTTON_5);
  if(state != 1 && potentiometer_value < 1000 && potentiometer_value > 801)
  {
    Keyboard.print("filletedge"); 
    Keyboard.press(KEY_RETURN);
    delay(200);
    Keyboard.releaseAll();
  }
// FOURTH PRESET 

  state = digitalRead(BUTTON_6);
 if(state != 1 && potentiometer_value < 1000 && potentiometer_value > 801)
  {
    Keyboard.print("copy"); 
    Keyboard.press(KEY_RETURN); 
    delay(200);
    Keyboard.releaseAll();
  }
// FOURTH PRESET 

  state = digitalRead(BUTTON_7);
  if(state != 1 && potentiometer_value < 1000 && potentiometer_value > 801)
  {
    Keyboard.print("move");
    Keyboard.press(KEY_RETURN);
    delay(200);
    Keyboard.releaseAll();
  }
// FOURTH PRESET 

  state = digitalRead(BUTTON_10);
  if(state != 1 && potentiometer_value < 1000 && potentiometer_value > 801)
  {
    Keyboard.print("intersect"); 
    Keyboard.press(KEY_RETURN);
    delay(200);
    Keyboard.releaseAll();
  }
// FOURTH PRESET 

  state = digitalRead(BUTTON_9);
  if(state != 1 && potentiometer_value < 1000 && potentiometer_value > 801)
  {
    Keyboard.print("default");
    delay(100);
    Keyboard.print("gizmo");
    delay(100);
    Keyboard.press(KEY_RETURN);
    delay(300);
    Keyboard.releaseAll();
    Keyboard.press('1');
    delay(50);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
  }
  //END OF FOURTH PRESET
  
  } 

   //BEGIN FIFTH PRESET 
  else if (potentiometer_value <= 1023 && potentiometer_value > 1001) {

  digitalWrite(LED_2, LOW);
  digitalWrite(LED_3, HIGH);
  digitalWrite(LED_1, HIGH);
  
  state = digitalRead(BUTTON_1);
  if(state != 1 && potentiometer_value <= 1023 && potentiometer_value > 1001)
//FIFTH PRESET  
  {
    Keyboard.print("visual");
    delay(50);
    Keyboard.print("styles");
    delay(50);
    Keyboard.releaseAll();
    Keyboard.press(KEY_RETURN);
    delay(200);
    Keyboard.releaseAll();
  }
//FIFTH PRESET
  state = digitalRead(BUTTON_2);
  if(state != 1 && potentiometer_value <= 1023 && potentiometer_value > 1001)
  {
    Keyboard.print("measure"); 
    delay(200);
    Keyboard.print("distance");
    delay(200);
    Keyboard.press(KEY_RETURN);
    delay(200);
    Keyboard.releaseAll();
  }
//FIFTH PRESET
  state = digitalRead(BUTTON_3);
 if(state != 1 && potentiometer_value <= 1023 && potentiometer_value > 1001)
  {
    Keyboard.print("measure"); 
    delay(200);
    Keyboard.print("distance");
    delay(200);
    Keyboard.releaseAll();
    delay(100);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
    
  }
//FIFTH PRESET
  state = digitalRead(BUTTON_4);
 if(state != 1 && potentiometer_value <= 1023 && potentiometer_value > 1001)
  {
    Keyboard.print("align"); 
    delay(300);
    Keyboard.press(KEY_RETURN); 
    delay(200);
    Keyboard.releaseAll();
  }
//FIFTH PRESET
  state = digitalRead(BUTTON_5);
  if(state != 1 && potentiometer_value <= 1023 && potentiometer_value > 1001)
  {
    Keyboard.print("txtexp"); 
    Keyboard.press(KEY_RETURN);
    delay(200);
    Keyboard.releaseAll();
  }
//FIFTH PRESET
  state = digitalRead(BUTTON_6);
 if(state != 1 && potentiometer_value <= 1023 && potentiometer_value > 1001)
  {
    Keyboard.print("export"); 
    Keyboard.press(KEY_RETURN); 
    delay(200);
    Keyboard.releaseAll();
  }
//FIFTH PRESET
  state = digitalRead(BUTTON_7);
  if(state != 1 && potentiometer_value <= 1023 && potentiometer_value > 1001)
  {
    Keyboard.print("mtext");
    Keyboard.press(KEY_RETURN);
    delay(200);
    Keyboard.releaseAll();
  }
//FIFTH PRESET
  state = digitalRead(BUTTON_10);
  if(state != 1 && potentiometer_value <= 1023 && potentiometer_value > 1001)
  {
    Keyboard.print("visual");
    delay(50);
    Keyboard.print("styles");
    delay(50);
    Keyboard.print("close");
    delay(100);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
  }
//FIFTH PRESET
  state = digitalRead(BUTTON_9);
  if(state != 1 && potentiometer_value <= 1023 && potentiometer_value > 1001)
  {
    Keyboard.print("default");
    delay(100);
    Keyboard.print("gizmo");
    delay(100);
    Keyboard.press(KEY_RETURN);
    delay(300);
    Keyboard.releaseAll();
    Keyboard.press('0');
    delay(50);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
  }
  //END OF FIFTH PRESET
  
  }
}

  
