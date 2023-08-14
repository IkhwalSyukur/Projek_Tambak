#include <Arduino.h>
#include <RBDdimmer.h>
// #include "fuzzy_motor.h"
#include "fuzzy_speed.h"

const int zeroCrossPin  = 15;
const int acdPin  = 4;
//Variables
int power=10;
//Objects
dimmerLamp acd(acdPin,zeroCrossPin);

#define relay 13

FuzzyHandler fz;

int hasil;
int state=1;
int motor;
int inputFuzzy;

void fz_task(void *pvParameters);
void bt_task(void *pvParameters);
void mn_task(void *pvParameters);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  fz.begin();
  acd.begin(NORMAL_MODE, ON);

  pinMode(23, INPUT_PULLUP);
  pinMode(22, INPUT_PULLUP);
  pinMode(relay, OUTPUT);


  xTaskCreatePinnedToCore(fz_task, "Fuzzy Task", 1024 * 2, NULL, 10, NULL, 1);
  // xTaskCreatePinnedToCore(bt_task, "Button Task", 1024 * 2, NULL, 5, NULL, 1);
  // xTaskCreatePinnedToCore(mn_task, "Manual Task", 1024 * 2, NULL, 10, NULL, 1);
}

void loop() {
  // Serial.print(digitalRead(23));
  // Serial.println(digitalRead(22));
  // delay(10);
vTaskDelete(NULL);
}

void fz_task(void *pvParameters){
  (void) pvParameters;
  while (1) {
    if (state==1){
      int dataDO = Serial.parseInt();
      if (dataDO > 0){
        inputFuzzy = dataDO;
      }
      fz.setinput(1, inputFuzzy); // Mengatur input untuk logika fuzzy
      fz.fuzify(); // Menghitung keluaran logika fuzzy
      hasil = fz.output(); // Mendapatkan nilai keluaran logika fuzzy
      Serial.printf("output Fuzzy: %d\n", hasil);
      // digitalWrite(relay,hasil);
      acd.setPower(hasil);
    // Serial.println(dataDO);
      vTaskDelay(10);
    }
  }
}

void bt_task(void *pvParameters){
  (void) pvParameters;
  for(;;){
    Serial.printf("State = %d\n",state);
    Serial.printf("tombol = %d\n", digitalRead(23));
    if (digitalRead(23)==0 && state==0){
      state=1;
    }

    else if (digitalRead(23)==0 && state==1){
      state=0;
    }
    vTaskDelay(10);
  }
}

void mn_task(void *pvParameters){
  (void) pvParameters;
  for(;;){
    Serial.printf("motor = %d\n",motor);
    Serial.printf("button motor = %d\n", digitalRead(22));
    if (state == 0){
      if (digitalRead(22)==0 && motor == 0){
        digitalWrite(relay,LOW);
        vTaskDelay(10);
        motor=1;
      }
      if(digitalRead(22)==0 && motor == 1){
        digitalWrite(relay,HIGH);
        vTaskDelay(10);
        motor=0;
      }
    }
    vTaskDelay(10);
  }
}


