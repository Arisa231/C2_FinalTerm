#include "setting.h"

void result(char name[10], int correct, std::chrono::seconds playTime) {
	fprintf_s(stdout, u8"\n\n");
	fprintf_s(stdout, u8"-------------------------------------------------------\n");
	fprintf_s(stdout, u8"--------------------GAME-RESULT------------------------\n");
	fprintf_s(stdout, u8"-------------------------------------------------------\n\n");
	fprintf_s(stdout, u8"%s�̃X�R�A�F\n", name);
	fprintf_s(stdout, u8"���𐔁F%d, �����������ԁF", correct);
	std::cout << playTime.count() << u8"�b\n\n" << std::endl;

	fprintf_s(stdout, u8"�D���ȃL�[�������ƁA���[�h�I���ɖ߂�܂��B\n");
	system("pause");

	fprintf_s(stdout, u8"-------------------------------------------------------\n");
	fprintf_s(stdout, u8"-------------------------------------------------------\n\n");
}
