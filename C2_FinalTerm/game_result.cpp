#include "setting.h"

void result(char name[10], int correct, std::chrono::seconds playTime) {
	fprintf_s(stdout, u8"\n\n");
	fprintf_s(stdout, u8"-------------------------------------------------------\n");
	fprintf_s(stdout, u8"--------------------GAME-RESULT------------------------\n");
	fprintf_s(stdout, u8"-------------------------------------------------------\n\n");
	fprintf_s(stdout, u8"%s�̃X�R�A�F\n", name);
	fprintf_s(stdout, u8"���𐔁F%d, �����������ԁF", correct);
	std::cout << playTime.count() << u8"�b\n\n" << std::endl;

	// �v���C���ʂ��t�@�C���ɏo��
	char fileName1[BUFFSIZE] = "result.txt";
	writeResult(fileName1, name, correct, playTime);

	// �����L���O�̃f�[�^�X�V
	playData* firstData = NULL;
	playData* previous = NULL;
	char fileName2[BUFFSIZE] = "ranking.csv";
	CSV2struct(fileName2, firstData);
	updateRanking(fileName1, firstData);

	fprintf_s(stdout, u8"�D���ȃL�[�������ƁA���[�h�I���ɖ߂�܂��B\n");
	system("pause");

	fprintf_s(stdout, u8"-------------------------------------------------------\n");
	fprintf_s(stdout, u8"-------------------------------------------------------\n\n");
}

void writeResult(const char* fileName, char name[10], int correct, std::chrono::seconds playTime) {
	std::ofstream writingFile;
	std::string fileName1 = fileName;
	writingFile.open(fileName1, std::ios::out);
	
	writingFile << "�ŐV�̃v���C����\n" << std::endl;
	writingFile << "���O,����������萔,������������(s)\n" << std::endl;
	writingFile << name << "," << correct << "," << playTime.count() << "\n" << std::endl;
	writingFile.close();
}