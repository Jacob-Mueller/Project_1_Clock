//seen these top includes included on everything I've seen so far, 
//gets rid of red lines on commonly included names like cout or endl
//would probably have to reference stack overflow, search terms 
//cout undefined c++.
#include<iostream>
#include<string>
#include<iomanip> //setwidth on display
using namespace std;
//=========================
//Jacob Mueller 11-14-2021
//=========================

class Clock { //class
	private: //private variables
		int clockHours;

		string clockMeridian = "A M";

		int clockMinutes;

		int clockSeconds;
		int clockHours12 = clockHours;
		int clockHours24 = clockHours;

	public: //accessible variables and methods
		//initiates clock time
		void Init(int Hour, int Minute, int Second) {
			clockHours = Hour;
			clockMinutes = Minute;
			clockSeconds = Second;
		}

		//produces desired clear screen white space
		void ClearScreen(void) {
			for (int i = 0; i < 40; i++) {
				cout << endl;
			}
		}
		//produces document specific menu
		void displayMenu(void) {
			cout << "*************************" << endl <<
				"* 1 - Add One Hour      *" << endl <<
				"* 2 - Add One Minute    *" << endl <<
				"* 3 - Add One Second    *" << endl <<
				"* 4 - Exit              *" << endl <<
				"*************************" << endl;
		}
		//time constraints left me less time than I would have liked to spend on this portion
		//the return types are giving me some trouble and the hours aren't exaclty right, but
		//they do turn over once they get to 12 and 24 respectively
		//this was the setup that worked best for providing the right numbers and changing the pm am.
		//definite FIXME once I get some more hands on time with classes.
		void time12(void) {
			clockHours12 += 1;
			if (clockHours12 > 12 && clockHours12 < 25) {
				clockHours12 -= 12;
				clockMeridian = "P M";
			}
		}

		void time24(void) {
			clockHours24 += 1;
			if (clockHours24 == 25) {
				clockHours24 = 0;
			}
		}



		//gotta review formatting to make sure I'm not having to waste so much time nitpicking it into place
		void displayTimes(void) {
			cout.fill('0'); //fills width space in case of single digit
			cout << "*************************" << "\t" << "*************************" << endl <<
				"*" << "     12-Hour Clock     " << "*" << "\t" << "*" << "     24-Hour Clock     " << "*" << endl <<
				"*" << "      " << setw(2) << clockHours12 << ":" << setw(2) << clockMinutes << ":" << setw(2) << clockSeconds << " " << clockMeridian << "     " << "*" << "\t" <<
				"*" << "         " << setw(2) << clockHours24 << ":" << setw(2) << clockMinutes << ":" << setw(2) << clockSeconds << "      " << "*" << endl <<
				"*************************" << "\t" << "*************************" << endl;
		}

		void addHour(void) {
			clockHours += 1; //adds hour
			time12();//calls independent times for the clocks
			time24();

		}

		int addMinute(void) {
			clockMinutes += 1; //adds minute and turns over hour
			if (clockMinutes == 60) {
				addHour();
				clockMinutes -= 60;
				return clockMinutes;
			}

			else {
				return clockMinutes;
			}
		}

		int addSecond(void) {
			clockSeconds += 1; //adds second and turns over minutes
			if (clockSeconds == 60) {
				addMinute();
				clockSeconds -= 60;
				return clockSeconds;
			}

			else {
				return clockSeconds;
			}
		}

};

int main(void) {
	int userInput; //initiates user inputs
	userInput = 0;

	Clock clock1; //builds class in main

	clock1.Init(23, 12, 59); //initiates the clock, used primarily to check work,
	//could be unnecessary in future iterations using time

	while (userInput != 4) { //breaks on user input 4

		clock1.ClearScreen(); //prints 40 white space lines

		clock1.displayTimes(); // displays clocks
		clock1.displayMenu(); // displays menu options for user

		cin >> userInput; //gets user input for menu

		if (userInput == 1) {
			clock1.addHour();//reads input and calls add hour form above
			
		}

		else if (userInput == 2) {
			clock1.addMinute();
			
		}

		else if (userInput == 3) {
			clock1.addSecond();
			
		}

		else if (userInput == 4) {
			cout << "Goodbye.";
			break;
		}

		else {
			cout << "Invalid Selection."; //lets user know that an invalid choice was made,
			//not visible FIXME, add exception throw or something instead when possible.
			
		}

	}

	return 0;
}
