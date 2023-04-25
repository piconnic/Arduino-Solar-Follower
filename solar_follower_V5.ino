#include <Servo.h> 
//   :)  :skull: frfr ong

Servo horizontal; // horizontal servo
int ServoH = 90; 
int ServoHLimitHigh = 175;
int ServoHLimitLow = 5;
// 65 degrees MAX

///Servo horizontal2; // horizontal servo 2
///the above code can be deleted/cloned/enabled to add/remove more solar followers
///this one is for horizontal servo

Servo vertical; // vertical servo
int ServoV = 90; 
int ServoVLimitHigh = 135;
int ServoVLimitLow = 45;

///Servo vertical2; // vertical servo
///the above code can be deleted/cloned/enabled to add/remove more solar followers
///this one is for verticle servo


// LDR pin connections
// name = analogpin;
int ldrTopLeft = A0; //LDR top left, connect to pin A0 
int ldrTopRight = A2; //LDR top rigt - connect to pin A2
int ldrBottomLeft = A1; //LDR bottom left - connect to pin A1
int ldrBottomRight = A3; //ldr bottom rigt - connect to pin A3

void setup(){
horizontal.attach(9); ///connect bottom servo signal pin to pin 9
vertical.attach(10);  ///connect top servo signal pin to pin 10
 
///horizontal2.attach(11); ///optional to add more followers
///vertical2.attach(12);  ///optional to add more followers
 
horizontal.write(90); //set inital H servo angle to 90
vertical.write(90); //set inital V servo angle to 90
 
///horizontal2.write(90); ///optional to add more followers
///vertical2.write(90); ///optional to add more followers
 
delay(500);
}

///Gets Values from the LDR sensors
void loop() {
int TopLeft = analogRead(ldrTopLeft); // top left
int TopRight = analogRead(ldrTopRight); // top right
int BottomLeft = analogRead(ldrBottomLeft); // down left
int BottomRight = analogRead(ldrBottomRight); // down right


int dtime = 50; int tollerance = 90; // dtime=diffirence time, 

///take raw data from LDR sensors and average them
int AverageTopValue = (TopLeft + TopRight) / 2; // average value top
int AverageBottomValue = (BottomLeft + BottomRight) / 2; // average value down
int AverageLeftValue = (TopLeft + BottomLeft) / 2; // average value left
int AverageRightValue = (TopRight + BottomRight) / 2; // average value right
int VerticleDifference = AverageTopValue - AverageBottomValue; // Gets verticle Difference
int HorizontalDifference = AverageLeftValue - AverageRightValue;// Gets Horizontal Difference


///Moves servo based on LDR sensorss


//Verticle movement
if (-1*tollerance > VerticleDifference || VerticleDifference > tollerance) // If the verticle difference is within the TOLERANCE variable it moves. If it isnt, dont move.
 {
 if (AverageTopValue > AverageBottomValue)
 {
 ServoV = ++ServoV; // ++ means start counting up. eg: ServoV = 1. ServoV = ++ServoV = 1,2,3,4,5,6,7,8
 if (ServoV > ServoVLimitHigh)
 {ServoV = ServoVLimitHigh;} //makes sure it does not go over the limit
 }
 else if (AverageTopValue < AverageBottomValue)
 {ServoV= --ServoV;
 if (ServoV < ServoVLimitLow) //if ServoV value is bigger than the ServoV Limit
 { ServoV = ServoVLimitLow;} //makes sure it does not go over the limit
 }
 
  
}


//Horizontal Movement (most of the stuff here is the exact same as Verticle movement.)
if (-1*tollerance > HorizontalDifference || HorizontalDifference > tollerance) 
 {
 if (AverageLeftValue > AverageRightValue)
 {
 ServoH = --ServoH;
 if (ServoH < ServoHLimitLow)
 {ServoH = ServoHLimitLow;}
 }
 else if (AverageLeftValue < AverageRightValue)
 {ServoH = ++ServoH;
 if (ServoH > ServoHLimitHigh)
 {ServoH = ServoHLimitHigh;}
 }
 else if (AverageLeftValue = AverageRightValue)
   
 {delay(5000);}

}
  

//makes the servo move  
vertical.write(ServoV);
horizontal.write(ServoH);  
 
///vertical2.write(ServoV); ///<optional to add more followers
///horizontal2.write(ServoH); ///<optional to add more followers
 
//How long the program should wait before doing it all over again.
  delay(dtime);
 
} 
  
