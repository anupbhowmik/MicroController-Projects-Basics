/*
 * LED_matrix.c
 *
 * Created: 6/17/2022 6:16:41 PM
 * Author : Anup
 */ 

#include <avr/io.h>
#include <stdio.h>
#define F_CPU 1000000
#include <util/delay.h>

// create your image here and don't worry about anything else
void resetRows(unsigned char rowSetup[]){
	rowSetup [0] = 0b00000001;
	rowSetup [1] = 0b00000010;
	rowSetup [2] = 0b00000100;
	rowSetup [3] = 0b00001000;
	rowSetup [4] = 0b00010000;
	rowSetup [5] = 0b00100000;
	rowSetup [6] = 0b01000000;
	rowSetup [7] = 0b00000000;
}

void resetCols(unsigned char colSetup[]){
	colSetup [0] = 0b00111100;
	colSetup [1] = 0b00000100;
	colSetup [2] = 0b00000100;
	colSetup [3] = 0b00111100;
	colSetup [4] = 0b00000100;
	colSetup [5] = 0b00000100;
	colSetup [6] = 0b00111100;
	colSetup [7] = 0b00000000;
}

void renderImage(int shift){
	// shift = 0	no shift
	// shift = 1	left shift
	// shift = 2	right shift
	// shift = 3	up shift
	// shift = 4	down shift
	// shift = 5	diagonal shift
	
	unsigned char delayMS = 6;
	
	unsigned char rowSetup [8];
	unsigned char colSetup [8];
	resetCols(colSetup);
	resetRows(rowSetup);

	
	while (1)
	{
		for(int i = 0; i < 7; i++){
			for(int j=0; j<50; j++){
				PORTB = rowSetup[i];
				PORTD = ~colSetup[i];
			}
			_delay_ms(delayMS);
		}

		if(shift == 1){
			for(int i = 0; i < 7; i++){
				colSetup[i] = (colSetup[i] << 1 | colSetup[i] >> 7);
			}
		}
		
		if(shift == 2){
			for(int i = 0; i < 7; i++){
				colSetup[i] = (colSetup[i] >> 1 | colSetup[i] << 7);
			}
		}
		
		if(shift == 3){
			for(int i = 0; i < 7; i++){
				rowSetup[i] = (rowSetup[i] >> 1 | rowSetup[i] << 7);
			}
		}
		
		
		if(shift == 4){
			for(int i = 0; i < 7; i++){
				rowSetup[i] = (rowSetup[i] << 1 | rowSetup[i] >> 7);
			}
		}
		
		if(shift == 5){
			for(int i = 0; i < 7; i++){
				rowSetup[i] = (rowSetup[i] << 1 | rowSetup[i] >> 7);
				colSetup[i] = (colSetup[i] << 1 | colSetup[i] >> 7);
			}
		}
	}
	
}



int main(void)
{
    	DDRD = 0xFF;
	DDRB = 0xFF;

	renderImage(1);
	while (1){

	}
	
	
}