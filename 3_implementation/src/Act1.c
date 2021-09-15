#include "Activity1.h"

void SEAT_CHECKING(){
    DDRD|=(1<<PD0); //Set B0= 1
    DDRD&=~(1<<PD1); //Clear bit
    PORTD|=(1<<PD1); //Set bit
    DDRD&=~(1<<PD2); //Clear bit
    PORTD|=(1<<PD2); //Set bit
}
