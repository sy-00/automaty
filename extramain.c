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
#include "led.h"
#include "keyboard.h"

int iTimeDelay;
int iStepCounter = 0;

// tylko 2 stany
enum LedState {STOP, RIGHT_DIRECTION};

void Delay(int iMiliseconds)
{
    int iLoopIteration;
    iTimeDelay = (iMiliseconds * 5456);
    for(iLoopIteration = 0 ; iLoopIteration < iTimeDelay ; iLoopIteration++) {}
}

int main()
{
    // stan poczatkowy - punkt swietlny stoi w miejscu
    enum LedState eLedState = STOP;
    
    LedInit();
    KeyboardInit();

    while(1)
    {
        switch(eLedState)
        {
            case STOP:
                // warunek przejscia - nacisniecie S0/button0
                if(eKeyboardRead() == BUTTON_0)
                {
                    eLedState = RIGHT_DIRECTION; // zmiana stanu na ruch
                    iStepCounter = 0;            // reset licznika przed startem
                }
                // przejscie wsobne: jesli przycisk nie jest wcisniety - zostan w stop
                else 
                {
                    eLedState = STOP; 
                }
                break;

            case RIGHT_DIRECTION:
                // waruenk przejścia wsobnego: wykonaliśmy mniej niż 3 kroki
                if(iStepCounter < 3)
                {
                    LedStepRight();   // zrob krok
                    iStepCounter++;  // zwieksz licznik
                    eLedState = RIGHT_DIRECTION; // zostan w tym samym stanie
                }
                // warunek przejścia: wykonano 3 kroki - zatrzymaj sie
                else
                {
                    eLedState = STOP; 
                }
                break;
        }

        Delay(250);
    }
}










//ZAD5
#include "led.h"
#include "keyboard.h"

int iTimeDelay;

// 2 stany
enum LedState {STOP, RIGHT_DIRECTION};

void Delay(int iMiliseconds)
{
    int iLoopIteration;
    iTimeDelay = (iMiliseconds * 5456);
    for(iLoopIteration = 0 ; iLoopIteration < iTimeDelay ; iLoopIteration++) {}
}

int main()
{
    // stan poczatkowy: PUNKT PRZESUWA SIE W PRAWO
    enum LedState eLedState = RIGHT_DIRECTION;
    
    LedInit();
    KeyboardInit();

    while(1)
    {
        switch(eLedState)
        {
            case STOP:
                // jesli juz zstoi a nacisnieto button1 - idz w prawo
                if(eKeyboardRead() == BUTTON_1)
                {
                    eLedState = RIGHT_DIRECTION;
                }
                // przejscie wsobne: jeśli nie S1 stój dalej
                else 
                {
                    eLedState = STOP;
                }
                break;

            case RIGHT_DIRECTION:
                //jesli nacisnieto button0 - zatrzymaj ruch
                if(eKeyboardRead() == BUTTON_0)
                {
                    eLedState = STOP;
                }
                // przejscie wsobne: jeśli nie kazemy stac - rob krok i zostan w tym stanie
                else 
                {
                    LedStepRight();
                    eLedState = RIGHT_DIRECTION; 
                }
                break;
        }

        Delay(250);
    }
}







//ZAD6
#include "led.h"
#include "keyboard.h"

int iTimeDelay;

// Definicja 3 stanów zgodnie z poleceniem
enum LedState {STOP, LEFT_DIRECTION, RIGHT_DIRECTION};

void Delay(int iMiliseconds)
{
    int iLoopIteration;
    iTimeDelay = (iMiliseconds * 5456);
    for(iLoopIteration = 0 ; iLoopIteration < iTimeDelay ; iLoopIteration++) {}
}

int main()
{
    // stan poczatkowy - punkt stoi
    enum LedState eLedState = STOP;
    
    LedInit();
    KeyboardInit();

    while(1)
    {
        switch(eLedState)
        {
            case STOP:
                if(eKeyboardRead() == BUTTON_0)
                {
                    eLedState = LEFT_DIRECTION;  // start w lewo (S0)
                }
                else if(eKeyboardRead() == BUTTON_2)
                {
                    eLedState = RIGHT_DIRECTION; // start w prawo (S2)
                }
                else 
                {
                    eLedState = STOP;            // przejscie wsobne
                }
                break;

            case LEFT_DIRECTION:
                if(eKeyboardRead() == BUTTON_1)
                {
                    eLedState = STOP;            // stop (S1)
                }
                else if(eKeyboardRead() == RELASED)
                {
                    LedStepLeft();               // ruch w lewo tylko gdy puszczony przycisk
                    eLedState = LEFT_DIRECTION;  // przejscie wsobne
                }
                else 
                {
                    eLedState = LEFT_DIRECTION;  // przejscie wsobne (trzymanie przycisku)
                }
                break;

            case RIGHT_DIRECTION:
                if(eKeyboardRead() == BUTTON_1)
                {
                    eLedState = STOP;            // stop (S1)
                }
                else if(eKeyboardRead() == RELASED)
                {
                    LedStepRight();              // ruch w prawo tylko gdy puszczony przycisk
                    eLedState = RIGHT_DIRECTION; // przejscie wsobne
                }
                else 
                {
                    eLedState = RIGHT_DIRECTION; // przejscie wsobne (trzymanie przycisku)
                }
                break;
        }

        // wywoalnie 10 razy na sekuned = 1000ms / 10 = 100ms
        Delay(100); 
    }
}
