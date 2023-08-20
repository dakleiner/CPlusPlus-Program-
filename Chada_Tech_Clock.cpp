//  Dan Kleiner
//  07/17/2023
//  CS210
//  Project 1

#include <iostream>
#include <iomanip>



using namespace std; // using standard namespace to save typing std:: 



int hour;  // all of the global variables tha will be needed to function the clock
int minute;
int second;
char border = '*';
string mornAfter = "PP";

int getHour() { // setup functtion to get the hour from user
	cout << "What hour is it? (24 hour)" << endl; //setting up with 24 hour clock since most of the work uses that
	cin >> hour;

	return hour;

}

int getMinute() { // setup function for minutes
	cout << "What minute is it?" << endl;
	cin >> minute;

	return minute;
}

int getSecond() { // setup function for seconds
	cout << "What second is it?" << endl;
	cin >> second;

	return second;
}


int addOneHour() { // funciton to add one hour
	hour = hour++;

	if (hour > 24) { // if statement to restart clock at midnight
		hour = 00;
	}

	return hour; //  returns the hour

}

int addOneMinute() { // funtion to add one minute
	minute++;

	if (minute > 59) { //if statement resets to zero and runs addOneHour function at 60 seconds
		minute = 00;
		addOneHour();
	}

	if (hour > 23 && minute > 00) { // if statment adds hour in case of midnight being 24:00 and 12:01 being 00:01
		addOneHour();
	}

	return minute; //  returns the minute
}

int addOneSecond() {//  function adds one second
	second++;

	if (second > 59) { // if statement to reset counter to zero
		second = 00;
		addOneMinute();
		
	}

	return second; // returnst he second
}


void displayBoarder() { // function to display border of menu and clocks
	
	
	cout << setw(20) << setfill(border); // sets the size of the border

	cout << border; // prints border to screen.
}

void getUserMenu() { // function to display the menu to the user
	

	displayBoarder(); //prints the borders

	cout << endl; //user options
	cout << "1-Add Hour" << endl;
	cout << endl;
	cout << "2-Add Minute" << endl;
	cout << endl;
	cout << "3-Add Second" << endl;
	cout << endl;
	cout << "4-Exit Clock" << endl;
	cout << endl;

	displayBoarder();



	return;

}




void twentyFourHourTime(int hour, int minute, int second) { // funciton to format the time for the 24 hour clock


	cout << setw(2) << setfill('0') << hour; // set fill to ad leading 0's
	cout << " : ";
	cout << setw(2) << setfill('0') << minute;
	cout << " : ";
	cout << setw(2) << setfill('0') << second;

}
	

void twelveHourTime(int hour, int minute, int second) { // function to display 12 hour clock
	string amPm = "AM"; //local varibales needed to complete funciton
	int hourTwelve = hour;


	if (hour == 00) { // if statements to handle if time should be AM or PM
		hourTwelve = 12;
		amPm = "AM";
	}
	else if (hour < 12) {
		amPm = "AM";
	}
	else if (hour == 12) {
		hourTwelve = 12;
		amPm = "PM";

	}
	else if (hour > 12 && hour < 24) {
		hourTwelve = hour - 12;
		amPm = "PM";
	}
	else if (hour = 24) {
		hourTwelve = 12;
		amPm = "AM";
	}
	
	
	cout << setw(2) << setfill('0') << hourTwelve; // SetW to add leading 
	cout << " : ";
	cout << setw(2) << setfill('O') << minute;
	cout << " : ";
	cout << setw(2) << setfill('0') << second;
	cout << " " << amPm;





}

void displayClock() { // funciton to output the clock to the user
	

	displayBoarder(); // I think I probably should hvae changed the variables to strings to save some space in the code.
	cout << "\t\t";
	displayBoarder();
	cout << endl;
	cout << "* ";
	twelveHourTime(hour, minute, second);
	cout << "  *\t     \   *   ";
	twentyFourHourTime(hour, minute, second);
	cout << "   *";
	cout << endl;
	displayBoarder();
	cout << "\t\t";
	displayBoarder();
	cout << endl;




}







	int main() {
		
		bool runClock = true; // boolean varible to run while loop
		int userChoice; // local in variable to help with loop

		getHour(); //inital setup funcitons
		getMinute();
		getSecond();
	
		while (runClock) { // enter main while loop
			
			
			displayClock(); // show clock to user
			
				
			

			getUserMenu(); // display menu to user
			cout << endl;
			cin >> userChoice; // get user input to run the loop

			

			switch (userChoice) { // use a switch to operater the main function of the program

			case 1:
				addOneHour(); // each case will go to the listed functions
				break;
			case 2:
				addOneMinute();
				break;
			case 3:
				addOneSecond();
				break;
			case 4: // case 4 is to quit the program and 
				runClock = false; 
				cout << "Goodbye" << endl; // just some output to show we left the program
				break;
			default: // default case to validate input
				cout << "Your choice is invalid";
			

			}
		}


		return 0;
	}


