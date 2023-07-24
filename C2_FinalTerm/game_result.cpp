#include "setting.h"

void result(char name[10], int correct, std::chrono::seconds playTime) {
	fprintf_s(stdout, u8"\n\n");
	fprintf_s(stdout, u8"-------------------------------------------------------\n");
	fprintf_s(stdout, u8"--------------------GAME-RESULT------------------------\n");
	fprintf_s(stdout, u8"-------------------------------------------------------\n\n");
	fprintf_s(stdout, u8"%s�̃X�R�A�F\n", name);
	fprintf_s(stdout, u8"���𐔁F%d, �����������ԁF", correct);
	std::cout << playTime.count() << u8"�b\n\n" << std::endl;

	// �����L���O�̃f�[�^�X�V
	playData* firstData = NULL;
	playData* previous = NULL;
	char fileName[BUFFSIZE] = "ranking.csv";
	CSV2struct(fileName, firstData);
	updateRanking(name, correct, playTime, firstData);

	fprintf_s(stdout, u8"�D���ȃL�[�������ƁA���[�h�I���ɖ߂�܂��B\n");
	system("pause");

	fprintf_s(stdout, u8"-------------------------------------------------------\n");
	fprintf_s(stdout, u8"-------------------------------------------------------\n\n");
}
