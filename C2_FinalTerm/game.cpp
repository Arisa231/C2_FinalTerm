#include "setting.h"

// �Q�[�����v���C
int playGame(time_t startTime, time_t endTime) {
	char char1[BUFFSIZE];
	char char2[BUFFSIZE];
	int answer = 0;
	int size = 0;
	int correct = 0;

	fprintf_s(stdout, u8"-------------------------------------------------------\n");
	fprintf_s(stdout, u8"--------------------GAME-START-------------------------\n");
	startTime = time(NULL); // �v���C���Ԍv���J�n

	// 5���E���h
	for (int i = 1; i < 6; i++) {
		// ���쐬
		answer = 0;
		size = i * 4;
		answer = makeQuestion(char1, char2, size);

		// ���\��
		fprintf_s(stdout, u8"-------------------------------------------------------\n");
		fprintf_s(stdout, u8"��%d��F\n\n", i);
		printQuestion(char1, char2, size, answer);
		fprintf_s(stdout, "\n\n");

		// �𓚓���
		int playersAnswer = getAnswer(size, answer);
		fprintf_s(stdout, "\n\n");

		// �������킹
		if (answer == playersAnswer) {
			fprintf_s(stdout, u8"�����ł��I\n\n");
			correct += 1;
		}
		else 
			fprintf_s(stdout, u8"�c�O�A�s�����ł�.\n\n");

		if (i != 5) {
			// Enter�L�[�����͂��ꂽ��A���̖���
			fprintf_s(stdout, u8"���̖��֐i�ނɂ́A�D���ȃL�[�������Ă��������B\n");
			system("pause");
			fprintf_s(stdout, "\n");
		}
		else {
			endTime = time(NULL); // �v���C���Ԍv���I��
			fprintf_s(stdout, u8"--------------------GAME-FINISH------------------------\n");
			fprintf_s(stdout, u8"-------------------------------------------------------\n");
		}
	}
	return correct;
}