#include "setting.h"

void putAnswer(int size, int answer) {
	double d1;
	double d2;
	int answerPlayer = 0;

	// 行の入力
	while (1) {
		fprintf_s(stdout, u8"一つだけ異なる文字は、何行目ですか？(解答を入力したらEnterを押してください。\n");
		fprintf_s(stdout, u8"解答：");
		if (scanf_s("%lf", &d1) == 1 and d1 <= size and d1 > 0)
			break;
		fprintf_s(stdout, u8"1から%d行目までしかありません。もう一度入力してください。\n", size);
		scanf_s("%*[^\n]");
	}

	answerPlayer = d1;

	fprintf_s(stdout, "\n");

	// 列の入力
	while (1) {
		fprintf_s(stdout, u8"何列目ですか？(解答を入力したらEnterを押してください。)\n");
		fprintf_s(stdout, u8"解答：");
		if (scanf_s("%lf", &d2) == 1 and d2 <= size and d2 > 0)
			break;
		fprintf_s(stdout, u8"1から%d列目までしかありません。もう一度入力してください。\n", size);
		scanf_s("%*[^\n]");
	}

	answerPlayer = answerPlayer * 10 + d2;

	fprintf_s(stdout, "\n\n");

	if (answer == answerPlayer) {
		fprintf_s(stdout, u8"正解です！\n\n");
	}
	else {
		fprintf_s(stdout, u8"残念、不正解です.\n\n");
	}
}