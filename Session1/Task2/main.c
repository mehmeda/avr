/*
 * Task2.c
 *
 * Created: 11.02.2017 23:39:47
 * Author : Petter
 */ 

#define F_CPU 3333333UL //3.33... MHz

/*
* System headers bellow
*/

#include <avr/io.h>
#include <util/delay.h>

/*
 * Take a look at the Atmega4809 Curiosity Nano board and locate "SW0" and "LED0".
 * Right below each of them you can see which pin they are connected to. For example, if it said PD5, this would mean Port D and Pin 5.
 * This info can also be found in the ATmega4809 Curiosity Nano Hardware User Guide here: http://ww1.microchip.com/downloads/en/DeviceDoc/ATmega4809-Curiosity-Nano-HW-UG-DS50002804A.pdf to find the correct ports and pins 
 */

//Fill in the defines with the information you found on the board/in the user guide.

// LED
#define LED0 5 //Fill in pin number

// Button
#define SW0 6 //Fill in pin number

int main(void)
{
	/*
	 * We want to send signals to the LEDs, in order to turn it off and on.
	 * We also want to be able to read the switches.
	 * This is done by setting bits in the PORTx.DIR register (in this case PORTF.DIR)
	 * PORTx.DIR: 1 is output, 0 is input
	 * LED: 1 LED is off, 0 LED is on
	 * Button: 1 Button is open, 0 button is pressed
	 * Bit set logic:
	 * Set to 1: REG |= ( 1 << BIT_POS )
	 * Set to 0: REG &= ~( 1 << BIT_POS )
	 */
	PORTF.DIR |= (1 << LED0);
	PORTF.DIR |= (0 << SW0);
	/**
	 * In order to read from the switches, we need to give it a ground reference, via a pull-up resistor.
	 * If we don't, the switch will have a floating ground, and hence its value will be undefined.
	 * On the ATmega4809, we enable pull-up by setting the "PORT_PULLUPEN" flag in "PORTx.PINnCTRL" high.
	 * See datasheet section 15 (I/O-ports).
	 */
    
	/* 
	 * It's your time to do some stuff! Do the following:
	 * 1 - Set LED0 as output
	 * 2 - Set SW0 as input
	 * 3 - Enable pull-up on button SW0
	 */
	
    while (1) 
    {
    	/*
		 * Here, you want to check if a button is pressed, and if yes, turn on the LED.
		 * If no, then do the opposite.
		 * Similar to setting pins with PORTx.OUT, we can read pins with PORTx.IN
		 * In order to check a pin value, mask out that particular bit. (use bitwise AND)
		 * Bit masking is done like this:
		 * (REGISTER & (1 << BIT_POS)), which selects bit BIT_POS from register.
		 * If that bit is 0, the result will be 0. If it is 1, the result will be other than 0 (depending on bit pos).
		 */
		if (!(PORTF.IN & (1 << SW0))) {
			PORTF.OUT ^= (1 << LED0);
			_delay_ms(500);
		}
		
		/* 
		* Do the following:
		* 1 - check if button SW0 is pressed
		* 2 - if so, turn the LED on
		* 3 - if not, turn the LED off
		*/
		
    }
}
