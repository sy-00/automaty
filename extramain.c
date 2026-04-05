//ZAD1
#include "led.h"
#include "keyboard.h"

// definicja typów stanów dla Zadania 1
enum LedState {LED_LEFT, LED_RIGHT};

// funkcja opóźniająca
void Delay(int iMiliseconds)
{
    int iTimeDelay = (iMiliseconds * 5456);
    int iLoopIteration;
    for(iLoopIteration = 0; iLoopIteration < iTimeDelay; iLoopIteration++)
    {
        // pusta pętla generująca opóźnienie
    }
}

int main()
{
    // inicjalizacja stanu początkowego
    enum LedState eLedState = LED_LEFT;
    
    // inicjalizacja modułów sprzętowych
    LedInit();
    KeyboardInit();

    while(1)
    {
        switch(eLedState)
        {
            case LED_LEFT:
                LedStepLeft();       //krok w lewo
                eLedState = LED_RIGHT; //zmiana stanu na przeciwny
                break;

            case LED_RIGHT:
                LedStepRight();      //krok w prawo
                eLedState = LED_LEFT;  //stan na przeciwny
                break;
        }

        // jedno wywolanie delay
        Delay(250);
    }
}







//ZAD2
#include "led.h"
#include "keyboard.h"

// Ddefinicja 6 stanow
enum LedState {STATE0, STATE1, STATE2, STATE3, STATE4, STATE5};

void Delay(int iMiliseconds)
{
    int iTimeDelay = (iMiliseconds * 5456);
    int iLoopIteration;
    for(iLoopIteration = 0; iLoopIteration < iTimeDelay; iLoopIteration++) {}
}

int main()
{
    // Zaczynamy od STATE0
    enum LedState eLedState = STATE0;
    
    LedInit();
    KeyboardInit();

    while(1)
    {
        switch(eLedState)
        {
            // 3 kroki w LEWO
            case STATE0:
                LedStepLeft();
                eLedState = STATE1;
                break;
            case STATE1:
                LedStepLeft();
                eLedState = STATE2;
                break;
            case STATE2:
                LedStepLeft();
                eLedState = STATE3;
                break;

            // trzy kroki w PRAWO
            case STATE3:
                LedStepRight();
                eLedState = STATE4;
                break;
            case STATE4:
                LedStepRight();
                eLedState = STATE5;
                break;
            case STATE5:
                LedStepRight();
                eLedState = STATE0; // powrot na poczatek cyklu
                break;
        }

        Delay(250); // jedyne wywolanie delay
    }
}









//ZAD3
#include "led.h"
#include "keyboard.h"

// Zmienne globalne zgodnie z Twoim wzorem
int iTimeDelay;
int iStepCounter = 0; // Licznik wykonanych kroków

// Definicja stanów dla Zadania 3
enum LedState {RIGHT_DIRECTION, LEFT_DIRECTION};

void Delay(int iMiliseconds)
{
    int iLoopIteration;
    iTimeDelay = (iMiliseconds * 5456);

    for(iLoopIteration = 0 ; iLoopIteration < iTimeDelay ; iLoopIteration++)
    {
        // Pusta pętla generująca opóźnienie
    }
}

int main()
{
    // inicjalizacja - na poczatek ruch w lewo
    enum LedState eLedState = LEFT_DIRECTION;
    
    LedInit();
    KeyboardInit(); 

    while(1)
    {
        switch(eLedState)
        {
            case LEFT_DIRECTION:
                // sprawdzamy czy nie wykonaliśmy już 3 kroków (0, 1, 2)
                if(iStepCounter < 3)
                {
                    LedStepLeft();   // wykonaj krok w lewo
                    iStepCounter++;  // zwieksz licznik kroków
                }
                else
                {
                    // jeśli licznik dobil 3 - zmień stan na ruch w prawo
                    eLedState = RIGHT_DIRECTION;
                    iStepCounter = 0; // reset licznik dla nowego stanu
                }
                break;

            case RIGHT_DIRECTION:
                // Sprawdzamy czy nie wykonaliśmy już 3 kroków
                if(iStepCounter < 3)
                {
                    LedStepRight();  // zrob krok w prawo
                    iStepCounter++;  // zwieksz licznik kroków
                }
                else
                {
                    // jak licznik osiągnął 3, wróć do ruchu w lewo
                    eLedState = LEFT_DIRECTION;
                    iStepCounter = 0; // reset licznik
                }
                break;
        }

        Delay(250); // jedno delay w petli (0.25s)
    }
}









//ZAD4
