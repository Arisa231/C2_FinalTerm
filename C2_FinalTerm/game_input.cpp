#include "setting.h"

// �v���C���[���̓���
void getName(char name[10]) {
	double d;
	fprintf_s(stdout, u8"-------------------------------------------------------\n");
	fprintf_s(stdout, u8"�v���C���[�̖��O��10�����ȓ��œ��͂��Ă��������B\n");
	for (;;) {
		// ���O�̓���
		fprintf_s(stdout, u8"���́F");
		if (scanf_s("%9s", name, 10) == 1) {
			scanf_s("%*[^\n]");

			// ���͂������O�̊m�F
			fprintf_s(stdout, u8"�v���C���[���́A�u%s�v�ł�낵���ł����H\n", name);
			fprintf_s(stdout, u8"��낵�����1���A�ύX����Ȃ�2����͂��Ă��������B\n");
			while (1) {
				fprintf_s(stdout, u8"���́F");
				if (scanf_s("%lf", &d) == 1 and (d == 1 or d == 2))
					break;
				fprintf_s(stdout, u8"1��2����͂��Ă��������B\n");
				scanf_s("%*[^\n]");
			}

			// ���O�̕ύX�Ȃ��̏ꍇ
			if (d == 1) {
				fprintf_s(stdout, u8"�v���C���[���́A�u%s�v�œo�^���܂����B\n", name);
				fprintf_s(stdout, u8"-------------------------------------------------------\n\n");
				break;
			}

			// ���O�̕ύX������ꍇ
			if (d == 2) {
				fprintf_s(stdout, u8"������x�A�v���C���[�̖��O��10�����ȓ��œ��͂��Ă��������B\n");
			}
		}
	}
}

// �𓚂̓���
int getAnswer(int size, int answer) {
	double d1;
	double d2;
	int playersAnswer = 0;

	// �s�̓���
	while (1) {
		fprintf_s(stdout, u8"������قȂ镶���́A���s�ڂł����H(�𓚂���͂�����Enter�������Ă��������B\n");
		fprintf_s(stdout, u8"�𓚁F");
		if (scanf_s("%lf", &d1) == 1 and d1 <= size and d1 > 0)
			break;
		fprintf_s(stdout, u8"1����%d�s�ڂ܂ł�������܂���B������x���͂��Ă��������B\n", size);
		scanf_s("%*[^\n]");
	}

	playersAnswer = d1;
	fprintf_s(stdout, "\n");

	// ��̓���
	while (1) {
		fprintf_s(stdout, u8"����ڂł����H(�𓚂���͂�����Enter�������Ă��������B)\n");
		fprintf_s(stdout, u8"�𓚁F");
		if (scanf_s("%lf", &d2) == 1 and d2 <= size and d2 > 0)
			break;
		fprintf_s(stdout, u8"1����%d��ڂ܂ł�������܂���B������x���͂��Ă��������B\n", size);
		scanf_s("%*[^\n]");
	}
	playersAnswer = playersAnswer * 100 + d2;

	// �v���C���[�̓��͂����𓚂�Ԃ�
	return playersAnswer;
}