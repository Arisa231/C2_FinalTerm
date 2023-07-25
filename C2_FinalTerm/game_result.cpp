#include "setting.h"

// �v���C���ʂ̏o��
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

	fprintf_s(stdout, u8"�D���ȃL�[�������ƁA���[�h�I���ɖ߂�܂��B\n");
	system("pause");

	fprintf_s(stdout, u8"-------------------------------------------------------\n");
	fprintf_s(stdout, u8"-------------------------------------------------------\n\n");
}

// �v���C���ʂ�"result.txt"�ɏ�������
void writeResult(const char* fileName, char name[10], int correct, std::chrono::seconds playTime) {
	std::ofstream writingFile(fileName, std::ios::app);
	writingFile <<  name << "," << correct << "," << playTime.count() << std::endl;
	writingFile.close();
}

// �v���C������"result.txt"����ǂݍ���ŁA�R���\�[����ʂɏo��
void readResult(const char* fileName) {
	std::cout << u8"-------------------------------------------------------" << std::endl;
	std::ifstream ifs(fileName);
	std::string str;
	if (ifs.fail()) {
		std::cerr << "�t�@�C�����J�����Ƃ��ł��܂���ł����B" << std::endl;
	}
	while (getline(ifs, str)) {
		std::cout << str << std::endl;
	}
	std::cout << u8"-------------------------------------------------------\n" << std::endl;
	fprintf_s(stdout, u8"�D���ȃL�[�������ƁA���[�h�I���ɖ߂�܂��B\n");
	system("pause");
}