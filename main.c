/*
 */

#include <avr/io.h>
#include<util/delay.h>
#include"uart.h"
int main(void)
{
USARTInit(103);
    // Insert code

    while(1)
    {
        USARTWriteChar('A');
    }

    return 0;
}
