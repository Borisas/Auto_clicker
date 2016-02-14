#pragma once
#include <Windows.h>
#include <iomanip>
#include <string>
#include <algorithm>
#include <random>
#include <iostream>

using namespace std;

class Action {

public:
	
	Action(WORD);
	Action(string);
	~Action();

	void runAction();

private:
	INPUT send;
	bool is_mouse = false;
	int mouse_action = 0;

	int getRandom(int min, int max) {

		std::random_device rd;     // only used once to initialise (seed) engine
		std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
		std::uniform_int_distribution<int> uni(min, max); // guaranteed unbiased

		auto random_integer = uni(rng);

		return random_integer;
	}
};