#define WEISHI_INTERVAL   25200000            //定义舵机旋转时间

#define WEISHI_OFF_INTERVAL 500000          //定义舵机关闭时间

#include <Servo.h> 

unsigned long duojitime = millis();

Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position

void setup() 
{ 
    Serial.begin(115200);    //串口初始化

    myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}


void loop() 
{
  duojixuanchuan();
} 
void duojixuanchuan(){
  if (millis() - duojitime > WEISHI_INTERVAL){
    for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees 
    {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                      // waits 15ms for the servo to reach the position 
    }
    duojitime=millis();
  }
  
  if(millis() - duojitime > WEISHI_OFF_INTERVAL) {
    for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
    {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                  // waits 15ms for the servo to reach the position 
    duojitime=millis();

    }
  }
}
