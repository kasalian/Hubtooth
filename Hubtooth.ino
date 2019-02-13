#include <Servo.h>

 
char junk;

const int relay1 = 13;
const int relay2 = 12;
const int relay3 = 11;
const int relay4 = 10;


String inputString="";

void setup()                    // run once, when the sketch starts
{

  pinMode(9, OUTPUT);
 Serial.begin(9600);            // set the baud rate to 9600, same should be of your Serial Monitor
 pinMode(relay1, OUTPUT);
 pinMode(relay2, OUTPUT);
 pinMode(relay3, OUTPUT);
 pinMode(relay4, OUTPUT);

 digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
   digitalWrite(relay3, HIGH);
    digitalWrite(relay4, HIGH);
     digitalWrite(9, HIGH);
 
 
}

void loop()
{
  if(Serial.available()){
  while(Serial.available())
    {
      char inChar = (char)Serial.read(); //read the input
      inputString += inChar;        //make a string of the characters coming on serial
    }
    Serial.println(inputString);
    while (Serial.available() > 0)  
    { junk = Serial.read() ; }      // clear the serial buffer
    if(inputString == "B"){         //in case of 'A' turn the bulb On
      digitalWrite(relay1, HIGH);
       
    }
     else if(inputString == "A"){   //in case of 'B' turn the bulb off
       digitalWrite(relay1, LOW);
     }
      
       else if(inputString == "D"){   //in case of 'D' turn the bulb off
          digitalWrite(relay2, HIGH);
       }
       else if(inputString == "C"){   //in case of 'C' turn the bulb off
          digitalWrite(relay2, LOW);
       }

       
       else if(inputString == "F"){   //in case of 'F' turn the switch off
           digitalWrite(relay3, HIGH);
       }
       else if(inputString == "E"){   //in case of 'E' turn the switch off
          digitalWrite(relay3, LOW);
       }

       
       else if(inputString == "H"){   //in case of 'H' turn the switch off
          digitalWrite(relay4, HIGH);
       }
       else if(inputString == "G"){   //in case of 'G' turn the switch off
          digitalWrite(relay4, LOW);
       }

    inputString = "";
  }
  }

