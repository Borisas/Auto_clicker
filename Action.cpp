#include "Action.hpp"

Action::Action(WORD k) {
	send.type = INPUT_KEYBOARD;
	send.ki.wScan = k;
	send.ki.time = 0;
	send.ki.dwExtraInfo = 0;
	send.ki.wVk = 0;
	send.ki.dwFlags = KEYEVENTF_SCANCODE;
}
Action::Action(string k) {
	is_mouse = true;
	std::transform(k.begin(), k.end(), k.begin(), ::tolower);
	if (k == "lmb") {
		mouse_action = 1;
	}
	else if (k == "rmb") {
		mouse_action = 2;
	}
	else {
		is_mouse = false;
	}
}
Action::~Action() {

}

void Action::runAction() {
	if (is_mouse) {
		switch (mouse_action) {
		case 1:
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			break;
		case 2:
			mouse_event(MOUSEEVENTF_RIGHTDOWN| MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
			break;
		}
	}
	else {
		SendInput(1, &send, sizeof(INPUT));

		send.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;

		Sleep(getRandom(5, 20));

		SendInput(1, &send, sizeof(INPUT));

		send.ki.dwFlags = KEYEVENTF_SCANCODE;
	}
}