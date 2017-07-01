#include <IRremote.h>
#include <IRremoteInt.h>
#include <Servo.h>

//defining values of the pressed button:
//seems a single button throws out 2 different values randomly
#define code1 2534850111 //decimal value of button 1
#define code3 16724175   //another decimal value of button 1
#define code2 16738455   //decimal value of button 0
#define code4 3238126971   //another decimal value of button 0
#define code5 16718055    //decimal value of button 2
#define code6 1033561079   //another decimal value of button 2
#define code7 16743045    //decimal value of button 3
#define code8 1635910171   //another decimal value of button 3


Servo myservo; // servo object
int RECV_PIN = 11; //receiveing pin IR remote

//possible modes for servo
const int SERVO_MODE_1 = 1;
const int SERVO_MODE_2 = 2;
const int SERVO_MODE_3 = 3;
const int SERVO_STOP = 0;

int pos = 0;    //position for servo

int servomode;  //initial state of  servo

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();  //start the receiver
  myservo.attach(9);    //servo connected to pin 9
  pinMode(2, OUTPUT);   //LED connected to pin 2
}


void loop()
{
  if (irrecv.decode(&results))
  {
    irrecv.resume();
    Serial.println(results.value, DEC); //show the decimal value of the pressed button
    irrecv.resume();  //receive the next value
  }

  switch(results.value)
  {
    case code1: 
      servomode = SERVO_MODE_1;
      break;

    case code3:
      servomode = SERVO_MODE_1;
      break;

    case code2:
      servomode = SERVO_STOP;
      break;

    case code4:
      servomode = SERVO_STOP;
      break;

   case code5:
      servomode = SERVO_MODE_2;
      break;

   case code6:
      servomode = SERVO_MODE_2;
      break;

   case code7:
      servomode = SERVO_MODE_3;

   case code8:
      servomode = SERVO_MODE_3;

    default:
      break;
  }

  switch(servomode)
  {
    case SERVO_MODE_1:
      digitalWrite(2, HIGH); //turn the led on

      //servo goes form 0 to 180 degrees in steps of 1 degree
      for (pos = 0; pos <= 180; pos += 1)
      {
        myservo.write(pos);
        delay(2);     //delay for 2 millisecond
      }

      //servo goes back from 180 to 0 degrees with 1 degree step
      for (pos = 180; pos >= 0; pos -= 1)
      {
        myservo.write(pos);
        delay(2);   //delay for 2 millisecond
      }
      break;

    case SERVO_MODE_2:
      digitalWrite(2, HIGH); //turn the led on

      //servo goes form 0 to 180 degrees in steps of 1 degree
      for (pos = 0; pos <= 180; pos += 1)
      {
        myservo.write(pos);
        delay(4);   //delay for 4 millisecond
      }

      //servo goes back from 180 to 0 degrees with 1 degree step
      for (pos = 180; pos >= 0; pos -= 1)
      {
        myservo.write(pos);
        delay(4);    //delay for 4 millisecond
      }
      break;

    case SERVO_MODE_3:
      digitalWrite(2, HIGH); //turn the led on

      //servo goes form 0 to 180 degrees in steps of 1 degree
      for (pos = 0; pos <= 180; pos += 1)
      {
        myservo.write(pos);
        delay(6);     //delay for 6 millisecond
      }

      //servo goes back from 180 to 0 degrees with 1 degree step
      for (pos = 180; pos >= 0; pos -= 1)
      {
        myservo.write(pos);
        delay(6);   //delay for 6 millisecond
      }
      break;
      
    case SERVO_STOP:
        digitalWrite(2, LOW);  // turn the led off
        myservo.write(pos);    // Servo goes back to 0 degree
        delay(5);
        break;
        
   default:
     break;
  } 
}  


 /*
 
 	FAILED MEHTOD

 switch(results.value)
     {
      case code1:
      digitalWrite(2,HIGH); //turn the led on
      for(pos = 0; pos <= 180; pos += 1){ //servo goes form 0 to 180 degrees in steps of 1 degree
      myservo.write(pos);
      delay(15);
      }
      for(pos = 180; pos >= 0; pos -= 1){ //servo goes back from 180 to 0 degrees with 1 degree step
      myservo.write(pos);
      delay(15);
      }
      

      case code3:
      digitalWrite(2,HIGH); //turn the led on
      for(pos = 0; pos <= 180; pos += 1){ //servo goes form 0 to 180 degrees in steps of 1 degree
      myservo.write(pos);
      delay(15);
      }
      for(pos = 180; pos >= 0; pos -= 1){ //servo goes back from 180 to 0 degrees with 1 degree step
      myservo.write(pos);
      delay(15);
      }
      
      //if(results.value == code2 || results.value == code4){
      case code2:
         digitalWrite(2, LOW);  // turn the led off
         myservo.write(pos);
         delay(15);
         break;

      case code4:
         digitalWrite(2, LOW);  // turn the led off
         myservo.write(pos);
         delay(15);
         break;
         
      default:
      break;
*/
