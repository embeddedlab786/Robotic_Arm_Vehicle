#include <Servo.h>

Servo motor_1;
Servo motor_2;
Servo motor_3;
Servo motor_4;
Servo motor_5;

#define enA 5  //Enable1 L298 Pin enA 
#define in1 A3 //Motor1  L298 Pin in1 
#define in2 A2 //Motor1  L298 Pin in1 
#define in3 A1 //Motor2  L298 Pin in1 
#define in4 A0 //Motor2  L298 Pin in1 
#define enB 5  //Enable2 L298 Pin enB 

int servo1 = 90;
int servo2 = 110;
int servo3 = 40;
int servo4 = 50;
int servo5 = 90;

int bt_data;
int Speed = 130;

void setup(){
  
Serial.begin(9600); // initialize serial communication at 9600 bits per second:
 
motor_1.attach(8);
motor_2.attach(9);
motor_3.attach(10);
motor_4.attach(11);
motor_5.attach(12); 
 
motor_1.write(servo1); 
motor_2.write(servo2); 
motor_3.write(servo3); 
motor_4.write(servo4); 
motor_5.write(servo5); 

pinMode(enA, OUTPUT); // declare as output for L298 Pin enA 
pinMode(in1, OUTPUT); // declare as output for L298 Pin in1 
pinMode(in2, OUTPUT); // declare as output for L298 Pin in2 
pinMode(in3, OUTPUT); // declare as output for L298 Pin in3   
pinMode(in4, OUTPUT); // declare as output for L298 Pin in4 
pinMode(enB, OUTPUT); // declare as output for L298 Pin enB

delay(1000);
}

void loop(){
//if some date is sent, reads it and saves in state

if(Serial.available() > 0){     
bt_data = Serial.read(); 
Serial.println(bt_data);
if(bt_data > 20){Speed = bt_data;}      
}

analogWrite(enA, Speed); // Write The Duty Cycle 0 to 255 Enable Pin A for Motor1 Speed 
analogWrite(enB, Speed); // Write The Duty Cycle 0 to 255 Enable Pin B for Motor2 Speed 


     if(bt_data == 1){forword(); }  // if the bt_data is '1' the DC motor will go forward
else if(bt_data == 2){backword();}  // if the bt_data is '2' the motor will Reverse
else if(bt_data == 3){turnLeft();}  // if the bt_data is '3' the motor will turn left
else if(bt_data == 4){turnRight();} // if the bt_data is '4' the motor will turn right
else if(bt_data == 5){Stop(); }     // if the bt_data '5' the motor will Stop

else if(bt_data == 6){turnLeft();  delay(400);  bt_data = 5;}
else if(bt_data == 7){turnRight(); delay(400);  bt_data = 5;}   

else if (bt_data == 8){
if(servo1<180){servo1 = servo1+1;}
motor_1.write(servo1);  
}
else if (bt_data == 9){
if(servo1>0){servo1 = servo1-1;} 
motor_1.write(servo1);  
}

else if (bt_data == 10){
if(servo2>0){servo2 = servo2-1;}
motor_2.write(servo2);
}
else if (bt_data == 11){
if(servo2<180){servo2 = servo2+1;}
motor_2.write(servo2);  
}

else if(bt_data == 12){
if(servo3>0){servo3 = servo3-1;}
motor_3.write(servo3);
}
else if (bt_data == 13){
if(servo3<180){servo3 = servo3+1;}
motor_3.write(servo3);
}

else if (bt_data == 14){
if(servo4<180){servo4 = servo4+1;}
motor_4.write(servo4);
}
else if(bt_data == 15){
if(servo4>0){servo4 = servo4-1;}
motor_4.write(servo4);
}

else if (bt_data == 16){
if(servo5>90){servo5 = servo5-1;}
motor_5.write(servo5);
}
else if (bt_data == 17){
if(servo5<150){servo5 = servo5+1;}
motor_5.write(servo5);
}

delay(30);
}


void forword(){  //forword
digitalWrite(in1, HIGH); //Right Motor forword Pin 
digitalWrite(in2, LOW);  //Right Motor backword Pin 
digitalWrite(in3, LOW);  //Left Motor backword Pin 
digitalWrite(in4, HIGH); //Left Motor forword Pin 
}

void backword(){ //backword
digitalWrite(in1, LOW);  //Right Motor forword Pin 
digitalWrite(in2, HIGH); //Right Motor backword Pin 
digitalWrite(in3, HIGH); //Left Motor backword Pin 
digitalWrite(in4, LOW);  //Left Motor forword Pin 
}

void turnRight(){ //turnRight
digitalWrite(in1, LOW);  //Right Motor forword Pin 
digitalWrite(in2, HIGH); //Right Motor backword Pin  
digitalWrite(in3, LOW);  //Left Motor backword Pin 
digitalWrite(in4, HIGH); //Left Motor forword Pin 
}

void turnLeft(){ //turnLeft
digitalWrite(in1, HIGH); //Right Motor forword Pin 
digitalWrite(in2, LOW);  //Right Motor backword Pin 
digitalWrite(in3, HIGH); //Left Motor backword Pin 
digitalWrite(in4, LOW);  //Left Motor forword Pin 
}

void Stop(){ //stop
digitalWrite(in1, LOW); //Right Motor forword Pin 
digitalWrite(in2, LOW); //Right Motor backword Pin 
digitalWrite(in3, LOW); //Left Motor backword Pin 
digitalWrite(in4, LOW); //Left Motor forword Pin 
}
