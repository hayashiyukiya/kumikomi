/* kadai1-2 - an application for the Pololu 3pi Robot
 *
 * This application uses the Pololu AVR C/C++ Library.  For help, see:
 * -User's guide: http://www.pololu.com/docs/0J20
 * -Command reference: http://www.pololu.com/docs/0J18
 *
 * Created: 4/20/2016 4:37:55 PM
 *  Author: student-a1
 */

#include <pololu/3pi.h>

#define TURN 38
#define STRAIGHT 20

int main()
{
	char flag = 0;
	//flag = 0 -> TURN
	//flag = 1 -> SQUARE
	
	char freq = 0; // it use when write square
	// freq 0 to 9 straight
	// freq 10 turn
	play_from_program_space(PSTR(">g32>>c32"));  // Play welcoming notes.

	clear();
	print("WAITING");
	wait_for_button_press(BUTTON_B);  //wait B
	clear();
	print("START");
	delay_ms(1000);

	while(1)
	{
	
		clear();
	
		// Print battery voltage (in mV) on the LCD.
		print_long(read_battery_millivolts_3pi());
	
		if (get_single_debounced_button_press(BUTTON_B)){
			freq = 0;
			set_motors(0, 0);
			if(flag == 0){
				play_note(E(5), 50, 10);  //play music
				flag = 1;
			}
			else{  //when flag == 1
				play_note(C(5), 50, 10);  //play music
				flag = 0;
			}
		}
		
		if(flag == 0){
			print(" C");    // print C
			set_motors(50, 20);  //turn
		}
		else{  //when flag == 1
			print(" S");   // print S
		
			if(freq >= 0 && freq < STRAIGHT){
				set_motors(60, 60);  //straight
				freq++;
			}
			if(freq >= STRAIGHT && freq < TURN){
				set_motors(10, 60);  //turn
				freq++;
			}
			if(freq == TURN){
				freq = 0;
			}
		}
	
		delay_ms(30);  // Wait for 30 ms.
	
	}
}