#include "Activity1.h"

void SEAT_CHECKING(){
    DDRD|=(1<<PD3); //Set D3= 1
    DDRD&=~(1<<PD0); //Clear bit
    PORTD|=(1<<PD0); //Set bit
    DDRD&=~(1<<PD1); //Clear bit
    PORTD|=(1<<PD1); //Set bit
}
