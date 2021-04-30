#include <avr/io.h>
#include<util/delay.h>
#include"acts.h"
int main(void)
{   uint16_t temp;
    DDRB|=(1<<PB0); //B0=1
    DDRD&=~(1<<PD0);
    PORTD|=(1<<PD0);
    DDRD&=~(1<<PD1);
    PORTD|=(1<<PD1);
     TCCR1A|=(1<<COM1A1)|(1<<WGM11)|(1<<WGM10);
     TCCR1B|=(1<<WGM12)|(1<<CS11)|(1<<CS10);// 64 prescalar

DDRB|=(1<<PB1);



    while(1)
    {

    if(!(PIND&(1<<PD0))&&!(PIND&(1<<PD1)))// pressing switch

{
    turn_on_led();
    temp=ReadADC(0);//gets the adc value and quantizes it
      _delay_ms(200);
    if(temp>=0&&temp<=200)
{OCR1A = 204.8;// displays on the CRO

_delay_ms (200);}

if(temp>=210&&temp<=500)
{OCR1A = 409.6;

_delay_ms (200);}
if(temp>=510&&temp<=700)
{OCR1A=716.8;

_delay_ms (200);}
if(temp>=710&&temp<=1024)
{OCR1A = 972.8;

_delay_ms (200);}


    }
    else
    {PORTB&=~(1<<PB0);
    _delay_ms(20);}}

    return 0;
}

