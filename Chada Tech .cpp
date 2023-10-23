
// Name        : CS 210 Project One Chada Tech Clocks
// Author      : Asr ra
// Copyright   : None
// Description : CS 210 Project One: 24 hr and 12hr clocks utilizing C++


#include <iostream>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

// 12 hr clock 
int hr = 12; 

// mins in relation to both 24 hr and 12 hr clocks
int minute = 0; 

// secs in relation to both 24 hr and 12 hr clocks
int sec = 0; 


// 24 hr circadian format
int hr24 = 0; 



// menu input field
int menuInput; 

// program is exited, if 4 is selected 
bool exitChecker = true; 

// i is utilized used to distinguish between am and pm,  switching to 1 if hr 24 >= 12
int i = 0;


// displays time
void printTime(){
	cout<< "***************************  ***************************" << endl;
	cout<< "*       12-Hour Clock     *  *        24-Hour Clock    *" << endl;
	cout<< "*       "; if(hr < 10) cout << "0"; cout << hr << ":"; if(minute < 10) cout << "0"; cout << minute << ":"; if(sec < 10) cout << "0"; cout << sec << " "; if(i==0)cout<<"AM"; else if(i==1)cout<<"PM"; cout<< "       *  *        "; if(hr24 < 10) cout << "0"; cout << hr24 << ":"; if(minute < 10) cout << "0"; cout << minute << ":"; if(sec < 10) cout << "0"; cout << sec << "         *" << endl;
	cout<< "***************************  ***************************" << endl;
}
// displays menu
void displayMenu() {

			cout << "***************************\n";
			cout << "* 1 - Add One Hour        *\n";
			cout << "* 2 - Add One Minute      *\n";
			cout << "* 3 - Add One Second      *\n";
			cout << "* 4 - Exit Program        *\n";
			cout << "***************************\n";
		}

void menuAction(){ // monitors user-input and responds, accordingly
	switch (menuInput){
			case 1:
				hr24++;
				hr++;
				if(hr24 == 24){
					hr24 = 0;
				}
				if(hr24 < 12){
					i = 0;
				}
				if(hr == 13){
					hr = 1;
				}
				if(hr24 >= 12){
					i = 1;
				}
				break;
			case 2:
				minute++;
				if(minute==60){
				hr++;
				hr24++;
				minute = 0;
					if(hr24 < 12){
						i = 0;
					}
					if(hr24 >= 12){
						i = 1;
					}
					if(hr == 13){
						hr = 1;
					}
					if(hr24 == 24){
						hr24 = 0;
					}
				}
				break;
			case 3:
				sec++;
				if(sec==60){
				minute++;
				sec = 0;
				if(minute==60){
					hr++;
					hr24++;
					minute = 0;
					if(hr24 < 12){
						i = 0;
					}
					if(hr == 13){
						hr = 1;
					}
					if(hr24 >= 12){
						i = 1;
					}
					if(hr24 == 24){
						hr24 = 0;
					}
				}}
				break;
			case 4:
				cout << "Program Ended" << endl;
				exitChecker = false;
				break;
			default:
				cout << "Please Enter A Valid Menu Input" << endl;
			}

		}

int main() { // displays menu, user-input, time, and clocks; alters time; and exits program

	while(exitChecker){
		

		
		displayMenu();
		printTime();
		cin >> menuInput;
		menuAction();
	}
	return 0;
}

