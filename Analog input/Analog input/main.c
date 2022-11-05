/*
 * Analog input.c
 *
 * Created: 7/18/2022 11:10:42 AM
 * Author : Anup
 */ 

#include <avr/io.h>


int main(void)
{
    // if temp is >=20 deg celseus, turn on the LED (PORTB = 0x1)
	DDRB = 0xFF;
	
	ADMUX	=	0b11000000;
	ADCSRA	=	0b10000000;
    while (1) 
    {
		// take input
		ADCSRA |= (1 << ADSC);
		while(ADCSRA & (1 << ADSC)) 
		{
			// after conversion is done, ADSC bit will be 0, so, until then, we wait and do nothing
		} 
		
		// convert to voltage
		//float volt = ADC * (2.56/1024);
		//float milivolt = volt * 1000;
		//float tempDeg = milivolt / 10;
		
		float tempDeg = ADC / 4.0;
		// ADC will hold the entire 10 bit of converted data
		
		// convert to temperature
		if (tempDeg >= 20){
			PORTB = 0x1;
		} else	PORTB = 0x00;
    }
}

