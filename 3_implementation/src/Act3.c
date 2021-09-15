#include "Activity2.h"
#include "Activity3.h"

void ADC_INITIALIZATION()
{
    ADMUX=(1<<REFS0);   //AVCC = +5V
    ADCSRA=(1<<ADEN)|(7<<ADPS0);
}

uint16_t SENSE_ADC(uint8_t channel)
{
    //Select ADC Channel(channel_0) which must be from 0-7
    ADMUX&=0xf8;
    channel=channel&0b00000111;
    ADMUX|=channel;

    //start single Conversion
    ADCSRA|=(1<<ADSC);

    //wait for conversion to complete
    while(!(ADCSRA & (1<<ADIF)));

    //Clear ADIF by writing one to it
    ADCSRA|=(1<<ADIF);
    return(ADC);
}

void TIMER_INITIALIZATION(void){

    TIMER1_FAST_PWM; //setting timer1 for PWM
    TIMER_PRESCALER_AS_64; //8 prescalar
    PWM_OUTPUT_PIN; //Setting PB1 as output pin

}

void PWM_OUPUT(uint16_t ADC_READING){
    char Temp[20];
    char start[]="Temperature :)";

    if(ADC_READING>0 && ADC_READING<=200){

        OCR1A = 195; //20% duty cycle
        Temp[0] = '2';
        Temp[1] = '0';
        Temp[2] = '*';
        Temp[3] = 'C';
        Temp[4] = ' ';
        Temp[5] = '\0';
        LCD_String(start);
        LCD_Command(0xC0);
        LCD_String(Temp);
        _delay_ms(20);
    }
    else if((ADC_READING>=210) && (ADC_READING<=500)){

        OCR1A = 495; //40% duty cycle
        Temp[0] = '2';
        Temp[1] = '5';
        Temp[2] = '*';
        Temp[3] = 'C';
        Temp[4] = ' ';
        Temp[5] = '\0';
        LCD_String(start);
        LCD_Command(0xC0);
        LCD_String(Temp);
        _delay_ms(20);
    }
    else if((ADC_READING>=501) && (ADC_READING<=700)){

        OCR1A = 695;//70% duty cycle
        Temp[0] = '2';
        Temp[1] = '9';
        Temp[2] = '*';
        Temp[3] = 'C';
        Temp[4] = ' ';
        Temp[5] = '\0';
        LCD_String(start);
        LCD_Command(0xC0);
        LCD_String(Temp);
        _delay_ms(20);
    }
    else if((ADC_READING>=701) && (ADC_READING<=1024)){

        OCR1A = 1019; //95% duty cycle
        Temp[0] = '3';
        Temp[1] = '3';
        Temp[2] = '*';
        Temp[3] = 'C';
        Temp[4] = ' ';
        Temp[5] = '\0';
        LCD_String(start);
        LCD_Command(0xC0);
        LCD_String(Temp);
        _delay_ms(20);
    }
    else{
        OCR1A = 0; //0% output
        Temp[0] = 'O';
        Temp[1] = 'F';
        Temp[2] = 'F';
        Temp[3] = ' ';
        Temp[4] = ' ';
        Temp[5] = '\0';
        LCD_String(start);
        LCD_Command(0xC0);
        LCD_String(Temp);
        _delay_ms(20);
    }

}
