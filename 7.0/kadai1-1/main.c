/* 3pi_app1 - an application for the Pololu 3pi Robot
 *
 * This application uses the Pololu AVR C/C++ Library.  For help, see:
 * -User's guide: http://www.pololu.com/docs/0J20
 * -Command reference: http://www.pololu.com/docs/0J18
 *
 * Created: 4/14/2016 2:20:17 PM
 *  Author: student-a2
 */

#include <pololu/3pi.h>
char namespace[100]="H.yukiya";
const char beep_button_b[] PROGMEM = "!e32";
char wait_for_250_ms_or_button_b();
const char bar_graph_characters[10] = {' ',0,0,1,2,3,3,4,5,255};


void bat_test()
{
	int bat = read_battery_millivolts();

	print_long(bat);
	print("mV");

	delay_ms(100);
}


int main()
{
	play_from_program_space(PSTR(">g32>>c32"));  // Play welcoming notes.

	int i = 0;
	while(1)
	{
		if(button_is_pressed(BUTTON_A))
		{
			play_from_program_space(beep_button_b);
			if(i==0){
				clear();
				print(namespace);
				delay_ms(100);
				i=1;
			} else if(i==1){
				clear();
				bat_test();
				i=0;
			}	
		wait_for_button_release(BUTTON_A);
		}
	}			
}






