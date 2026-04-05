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
