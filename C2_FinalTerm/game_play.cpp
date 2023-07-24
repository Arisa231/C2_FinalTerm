#include "setting.h"

// �Q�[�����v���C
int playGame(std::chrono::seconds playTime) {
	char char1[BUFFSIZE];
	char char2[BUFFSIZE];
	int answer = 0;
	int size = 0;
	int correct = 0;

	fprintf_s(stdout, u8"-------------------------------------------------------\n");
	fprintf_s(stdout, u8"----------------------GAME-START-----------------------\n");
	
	auto startTime = std::chrono::high_resolution_clock::now();	// �v���C���Ԍv���J�n

	// 5���E���h
	for (int i = 1; i < 6; i++) {
		// ���쐬
		answer = 0;
		size = i * 4;
		answer = makeQuestion(char1, char2, size);

		// ���\��
		fprintf_s(stdout, u8"-------------------------------------------------------\n");
		fprintf_s(stdout, u8"-------------------------------------------------------\n\n");
		fprintf_s(stdout, u8"��%d��F\n\n", i);
		printQuestion(char1, char2, size, answer);
		fprintf_s(stdout, "\n\n");

		// �𓚓���
		int playersAnswer = getAnswer(size, answer);
		fprintf_s(stdout, "\n");

		// �������킹
		if (answer == playersAnswer) {
			fprintf_s(stdout, u8"-------------------�����ł��I-------------------\n\n");
			correct += 1;
		}
		else 
			fprintf_s(stdout, u8"-------------------�s�����ł�.-------------------\n\n");

		if (i != 5) {
			// Enter�L�[�����͂��ꂽ��A���̖���
			fprintf_s(stdout, u8"���̖��֐i�ނɂ́A�D���ȃL�[�������Ă��������B\n");
			system("pause");
			fprintf_s(stdout, "\n\n");
		}
		else {
			auto endTime = std::chrono::high_resolution_clock::now();							// �v���C���Ԍv���I��
			playTime = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime);	// �v���C���ԋL�^
			fprintf_s(stdout, u8"----------------------GAME-FINISH----------------------\n");
			fprintf_s(stdout, u8"-------------------------------------------------------\n");
		}
	}
	return correct;
}