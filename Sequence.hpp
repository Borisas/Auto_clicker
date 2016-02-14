#pragma once

#include "Action.hpp"
#include <vector>
#include <Windows.h>

class Sequence {

public:

	Sequence();
	~Sequence();

	void addAction(Action);
	void addAction(Action, int, int);
	void setDefaultDelay(int min, int max);

	void runSequence();
	int getRestDelay();
	int getRunTime();
	void disableFatigue() { fatigue = false; };

private:
	void checkRestDelay();
	struct RDelay {
		int min;
		int max;
	};
	RDelay defaultDelay = { 100,500 };
	RDelay defaultRestingDelay = { 25000,50000 };

	int restDelay = 0;
	int runTime = 0;
	bool slowDown = false;

	bool fatigue = true;

	vector<Action> ac_array;
	vector<RDelay> dl_array;

	int getRandom(int min, int max) {

		std::random_device rd;     // only used once to initialise (seed) engine
		std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
		std::uniform_int_distribution<int> uni(min, max); // guaranteed unbiased

		auto random_integer = uni(rng);

		return random_integer;
	}
};