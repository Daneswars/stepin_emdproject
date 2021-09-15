#include <avr/io.h>
#include<util/delay.h>
#include "Activity1.h"
#include "Activity2.h"
#include"Activity3.h"
int main(void)
{
    SEAT_CHECKING();
    ADC_INITIALIZATION();
    TIMER_INITIALIZATION();
    LCD_Init();			/* Initialization of LCD*/

    uint16_t temp;

	while(1)
    {
        if(SEAT_CHECK)
        {
            PORTD|=(1<<PD2);
            if(HEATER_ON){
                LED_ON;
                _delay_ms(200);
                LCD_Clear();
                temp=SENSE_ADC(0);
                PWM_OUPUT(temp);

            }
            else
                {
                    LED_OFF;
                     _delay_ms(200);
                    HEATER_OFF;
                    _delay_ms(200);
                    LCD_Clear();
                }
        }
        else{
            LED_OFF;
            _delay_ms(200);
            HEATER_OFF;
            _delay_ms(200);
            LCD_Clear();
        }
    }
    return 0;
}
