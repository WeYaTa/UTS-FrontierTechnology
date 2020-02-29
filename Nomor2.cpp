#include<Arduino.h>

    long LEDmillis = 0;
    long Serialmillis = 0;
    int LED_Period = 1000;
    int Serial_Period = 5000;
    bool LED_State = HIGH;

    int previousButton_A = 0;
    int previousButton_B = 0;
    int currentButton_A = 0;
    int currentButton_B = 0;
    #define Button_A 0
    #define Button_B 4

    long startA, endA = 0;
    long startB, endB = 0;

    bool printA = false;
    bool printB = false;

void setup(){
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(Button_A, INPUT);
    pinMode(Button_B, INPUT);
    Serial.begin(115200);

}


void loop(){
// Task 1 : Blink LED Every LED_Period
    if(millis()-LEDmillis>=LED_Period){
        LEDmillis = millis();
        LED_State = !LED_State;
        digitalWrite(LED_BUILTIN, LED_State);
    }



    if (currentButton_A == previousButton_A) currentButton_A = digitalRead(Button_A);
    if (currentButton_B == previousButton_B) currentButton_B = digitalRead(Button_B);


    

    
    if (currentButton_A != previousButton_A)
    {
        if (currentButton_A == 0)
        {
            if(LED_Period < 2500){
                LED_Period += 100;
                Serial.println("I - "+String(LED_Period));
            }else
            {
                Serial.println("Cannot exceed 2500");
            }
            
        }
        previousButton_A = currentButton_A;
    }

   
    if (currentButton_B != previousButton_B)
    {
        if (currentButton_B == 0)
        {
            if(LED_Period >0){
                LED_Period -= 100;
                Serial.println("D - "+String(LED_Period));
            }else
            {
                Serial.println("Cannot get below 0");
            }
        }
        previousButton_B = currentButton_B;
    }
    

}