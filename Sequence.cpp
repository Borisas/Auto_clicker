#include "Sequence.hpp"

Sequence::Sequence() {
	restDelay += getRandom(defaultRestingDelay.min, defaultRestingDelay.max);
}
Sequence::~Sequence() {}
void Sequence::addAction(Action n) {
	ac_array.push_back(n);
	dl_array.push_back(defaultDelay);
}
void Sequence::addAction(Action n, int min, int max) {
	ac_array.push_back(n);
	dl_array.push_back({ min, max });
}
void Sequence::setDefaultDelay(int min, int max) {
	defaultDelay = { min, max };
}

void Sequence::runSequence() {
	if (!slowDown) {
		cout << "!!! NORMAL !!!" << endl;
	}
	else {
		cout << "!!! SLOW !!!" << endl;
	}
	for (unsigned int i = 0; i < ac_array.size(); i++) {
		int timeForThis = getRandom(dl_array[i].min, dl_array[i].max);
		if (slowDown)
			timeForThis *= 1.75f;
		cout << "Current Delay [" << i << "]:" << timeForThis << endl;
		ac_array[i].runAction();
		Sleep(timeForThis);
		runTime += timeForThis;
	}
	checkRestDelay();
}
int Sequence::getRestDelay() {
	return restDelay-runTime;
}
int Sequence::getRunTime() {
	return runTime;
}
void Sequence::checkRestDelay() {
	if (restDelay <= runTime && fatigue) {
		restDelay += getRandom(defaultRestingDelay.min, defaultRestingDelay.max);
		slowDown = !slowDown;
	}
}