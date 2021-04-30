#include <avr/io.h>
#include<util/delay.h>
void InitADC()
{
    ADMUX=(1<<REFS0);

ADCSRA=(1<<ADEN)|(1<<ADPS0);
}
uint16_t ReadADC (uint8_t ch)
{

//Select ADC Channel ch must be

ADMUX&=0xf8;

ch=ch&0b00000111;

ADMUX|=ch;

//Start Single conversion

ADCSRA|=(1<<ADSC);

//Wait for conversion to complete

while (!(ADCSRA&(1<<ADIF)));

//Clear ADIF.by writing one to it

ADCSRA|=(1<<ADIF);

return (ADC);}


int main(void)
{InitADC();
uint16_t temp;
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
    PORTB|=(1<<PB0);
    _delay_ms(20);
    temp=ReadADC(0);
      _delay_ms(200);
    if(temp>=0&&temp<=200)
{OCR1A = 204.8;

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

