/*
 * Code to perform various types of turns.  The delays here had to be
 * calibrated for the 3pi's motors.
 */

#include <pololu/3pi.h>

// Turns according to the parameter dir, which should be 'L', 'R', 'S'
// (straight), or 'B' (back).
void turn(char dir)
{
	switch(dir)
	{
	case 'L':
		// Turn left.
		set_motors(-120,120); //80
		delay_ms(130);        //200
		set_motors(100,100);
		delay_ms(20);        
		break;
	case 'R':
		// Turn right.
		set_motors(120,-120);  //80
		delay_ms(130);
		set_motors(100,100);
		delay_ms(20);
		break;
	case 'B':
		// Turn around.
		set_motors(120,-120);  //80
		delay_ms(260);         //400
		set_motors(100,100);
		delay_ms(20);
		break;
	case 'S':
		// Don't do anything!
		break;
	}
}

// Local Variables: **
// mode: C **
// c-basic-offset: 4 **
// tab-width: 4 **
// indent-tabs-mode: t **
// end: **
