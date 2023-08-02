#include <Arduino.h>
#include <Wire.h>
#include"ADS1X15.h"

ADS1115 ADS(0x48);

void setup (){
    Serial.begin(115200);
    ADS.begin();
}

void loop (){
    readPH();
    Serial.printf("Nilai pH = %f\t", pHvalue);
}

int motorPin = A0;            //pin that turns on pump motor
int pHpin = A3;               //pin that sends signals to pH meter
int blinkPin = 13;            //LED pin
float offset = 2.97;          //the offset to account for variability of pH meter
float offset2 = 0;            //offset after calibration
float slope = 0.59;           //slope of the calibration line
int fillTime = 10;            //time to fill pump tubes with acid/base after cleaning... pumps at 1.2 mL/sec
int delayTime = 10;           //time to delay between pumps of acid/base in seconds
int smallAdjust = 1;          //number of seconds to pump in acid/base to adjust pH when pH is off by 0.3-1 pH
int largeAdjust = 3;          //number of seconds to pump in acid/base to adjust pH when pH is off by > 1 pH
int negative = 0;             //indicator if the calibration algorithm should be + or - the offset (if offset is negative or not)


float pHvalue;                //reads the voltage of the pH probe
float pHregulate;             //holds value that the user wants the pH to stay at throughout reaction
float deltaPH;                //holds the value of the difference between pHregulate and pHvalue
float pH4val;                 //value for calibration at pH4
float pH7val;                 //value for calibration at pH7
float pH10val;                //value for calibration at pH10
byte incomingByte;            //reads the user's selection during the menu state
byte wasteByte;               //used to clear Serial input when the user's selection doesn't matter
int statusValue;              //indicates if the user wants a regulator or just a pH reading
int pHavg[10];                //array to find an average pH of 10 meter readings
int temp;                     //temporary place holder used to sort array from small to large
unsigned long int avgValue;   //stores the average value of the 6 middle pH array readings


/////////////////////////////
void readPH()     /*--(Subroutine, reads current value of pH Meter)-----------------------------------------------------------------*/
{
  for(int i=0; i<10; i++)                   //get 10 sample values from the sensor to smooth the value
    { 
    ADS.setGain(1); // setGain set to 1 to more precission
    int16_t nilai_pH = ADS.readADC(0);
    pHavg[i] = nilai_pH;         //get reading from pH sensor and put in array
    delay(10);                            //short delay between readings
    }
    
  for(int i=0; i<9; i++)                    //sort the analog values from small to large
    {
      for(int j=i+1; j<10; j++)             
        {
          if(pHavg[i] > pHavg[j])           //if "i" value of array is bigger than "j" value
            {
              temp = pHavg[i];              //assign "i" to temporary variable
              pHavg[i] = pHavg[j];          //switch "j" to "i" location
              pHavg[j] = temp;              //switch "i" to "j" location
            }
        }
    }
  avgValue = 0;
  for(int i=2; i<8; i++)                    //take the value total of 6 center array values
    {
      avgValue += pHavg[i];                 //get total
    }
  pHvalue = (float)avgValue*3.3/65536.0/6;     //map the analog (0-1023) into millivolt (0-5).. division by 6 for average

  if (negative == 0)                        //if the offset is positive... see calibration subroutine.. negative is initialized as 0
    {
      pHvalue = (slope*3.5*pHvalue + offset + offset2); //convert the millivolt into pH value, with positive offset and slope from calibration
    }
  else
    {
      pHvalue = (slope*3.5*pHvalue - offset + offset2); //convert the millivolt into pH value, with negative offset and slope from calibration
    }
}
/////////////////////////////////////////