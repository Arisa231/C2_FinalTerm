#include "setting.h"

void result(char name[10], int correct, time_t playTime) {
	char s[26];
	ctime_s(s, sizeof s, &playTime);
	fprintf_s(stdout, u8"\n\n");
	fprintf_s(stdout, u8"-------------------------------------------------------\n");
	fprintf_s(stdout, u8"--------------------GAME-RESULT------------------------\n");
	fprintf_s(stdout, u8"%s�̃X�R�A�F\n", name);
	fprintf_s(stdout, u8"���𐔁F%d, �����������ԁF%s\n", correct, s);
	fprintf_s(stdout, u8"-------------------------------------------------------\n");
}
