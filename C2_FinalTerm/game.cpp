#include "setting.h"

void playGame() {
	char char1[BUFFSIZE];
	char char2[BUFFSIZE];
	int answer = 0;
	int size = 0;

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

		// �𓚓���
		fprintf_s(stdout, "\n\n");
		putAnswer(size, answer);

		// Enter�L�[�����͂��ꂽ��A���̖���
		fprintf_s(stdout, u8"���̖��֐i�ނɂ́A�D���ȃL�[�������Ă��������B\n");
		system("pause");
		fprintf_s(stdout, "\n");
	}
}