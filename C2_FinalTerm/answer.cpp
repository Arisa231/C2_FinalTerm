#include "setting.h"

void putAnswer(int size, int answer) {
	double d1;
	double d2;
	int answerPlayer = 0;

	// �s�̓���
	while (1) {
		fprintf_s(stdout, u8"������قȂ镶���́A���s�ڂł����H(�𓚂���͂�����Enter�������Ă��������B\n");
		fprintf_s(stdout, u8"�𓚁F");
		if (scanf_s("%lf", &d1) == 1 and d1 <= size and d1 > 0)
			break;
		fprintf_s(stdout, u8"1����%d�s�ڂ܂ł�������܂���B������x���͂��Ă��������B\n", size);
		scanf_s("%*[^\n]");
	}

	answerPlayer = d1;

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

	answerPlayer = answerPlayer * 10 + d2;

	fprintf_s(stdout, "\n\n");

	if (answer == answerPlayer) {
		fprintf_s(stdout, u8"�����ł��I\n\n");
	}
	else {
		fprintf_s(stdout, u8"�c�O�A�s�����ł�.\n\n");
	}
}