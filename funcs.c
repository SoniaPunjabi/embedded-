#include<avr/io.h>
#include<util/delay.h>
/** InitADC function
 *
 * \param
 * \param
 * \returns
 *
 */

void InitADC()
{
ADMUX=(1<<REFS0);

ADCSRA=(1<<ADEN)|(1<<ADPS0);
}
/** \brief ReadADC takes analog values quantizes it and returns it
 *
 * \param input parameter unit8_t
 * \return returns unit16_t
 *
 */

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
/** \brief turn_on_led turns the led on
 *
 *
 */

void turn_on_led()
{
    PORTB|=(1<<PB0);
    _delay_ms(20);
}
