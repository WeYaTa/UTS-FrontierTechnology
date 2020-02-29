#include<Arduino.h>

    long LEDmillis = 0;
    long Serialmillis = 0;
    int LED_Period = 500;
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
            startA = millis();
            Serial.println("You pressed button A");  
            printA = true;  
        }
        else
        {
            endA = millis();
            Serial.println("You released button A after "+String((endA-startA)/1000)+ " seconds\n");
            printA = false;
        }
        previousButton_A = currentButton_A;
    }

   
    if (currentButton_B != previousButton_B)
    {
        if (currentButton_B == 0)
        {
            startB = millis();
            Serial.println("You pressed button B");    
            printB = true;
        }
        else
        {
            endB = millis();
            Serial.println("You released button B after "+String((endB-startB)/1000)+ " seconds\n");
            printB = false;
        }
        previousButton_B = currentButton_B;
    }


    if(currentButton_A == 0 && (millis() - startA >= 10000)){
        if(printA == true) {
            Serial.println("It's time for you to release Button A, it's been 10 seconds");
            printA = false;
        }
    }

    if(currentButton_B == 0 && (millis() - startB >= 10000)){
        if(printB == true) {
            Serial.println("It's time for you to release Button B, it's been 10 seconds");
            printB = false;
        }
    }
    

}