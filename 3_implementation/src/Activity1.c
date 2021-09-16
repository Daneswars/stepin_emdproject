#include "Activity1.h"

void SEAT_CHECKING(){
    DDRD|=(1<<PD3); //Set D3= 1
    DDRD&=~(1<<PD0); //Clear bit
    PORTD|=(1<<PD0); //Set bit
    DDRD&=~(1<<PD1); //Clear bit
    PORTD|=(1<<PD1); //Set bit
}
while(1)
    {
        if  ( (!(PIND & (1<<PD0))) & (!(PIND & (1<<PD1))) )
    {
        PORTD |= (1<<PD3);   //Turns on the LED if both the switches are turned on by the user
        _delay_ms(200);
    }
    else
    {
       PORTD &= ~(1<<PD3);  //Turns Off the LED
        _delay_ms(200);
    }
    }
    return 0;
}

