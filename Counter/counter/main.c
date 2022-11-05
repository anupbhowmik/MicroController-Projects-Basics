/*
 * counter.c
 *
 * Created: 6/12/2022 9:29:22 PM
 * Author : Anup
 */ 

#define F_CPU 1000000
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    DDRD = 0b00001111;
	unsigned char count = 0;
	
    while (1) 
    {
		count++;
		if (count == 16)
		{
			count = 0;
		}
		PORTD = count;
		_delay_ms(1000);
    }
}

