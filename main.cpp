#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include "Action.hpp"
#include "Sequence.hpp"

using namespace std;

void printTime(string t, int total_time) {
	cout << t << endl;
	int hours = total_time / 3600000;
	int next_time = total_time - (hours * 3600000);
	int minutes = next_time / 60000;
	next_time = next_time - (minutes * 60000);
	int seconds = next_time / 1000;
	cout << hours << ":" << minutes << ":" << seconds << endl;
}
int nextSwitchTimer(int total_time, int last_seconds) {
	return  last_seconds - (total_time / 1000);
}

int main() {

	int between = 0;

	int total_time = 0;

	bool slow_down = false;
	int time_left = 0;
	int i = 0;

	int running_time = 2*3600000;

	bool run = false;
	
	Action click("lmb");


	Sequence current;
	current.addAction(click, 25000, 45000);
	current.disableFatigue();


	while (true) {
		if (!run) {
			run = GetKeyState(VK_SCROLL);
		}
		else {
			run = GetKeyState(VK_SCROLL);
			printTime("Time Passed:",current.getRunTime());
			printTime("Time to next switch:",current.getRestDelay());
			current.runSequence();
			if (run) {
				system("CLS");
			}
		}
	}
	system("PAUSE");
	return 0;
};