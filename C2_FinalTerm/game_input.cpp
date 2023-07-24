#include "setting.h"

// プレイヤー名の入力
void getName(char name[10]) {
	double d;
	fprintf_s(stdout, u8"-------------------------------------------------------\n");
	fprintf_s(stdout, u8"プレイヤーの名前を10文字以内で入力してください。\n");
	for (;;) {

		fgets(name, 10, stdin);
		fprintf_s(stdout, u8"\n\n");
		fprintf_s(stdout, u8"プレイヤー名は、「%s」でよろしいですか？\n", name);
		fprintf_s(stdout, u8"よろしければ1を、変更するなら2を入力してください。\n");
		while (1) {
			if (scanf_s("%lf", &d) == 1 and (d == 1 or d == 2))
				break;
			fprintf_s(stdout, u8"1か2を入力してください。\n");
			scanf_s("%*[^\n]");
		}
		if (d == 1) {
			fprintf_s(stdout, u8"プレイヤー名は、「%s」で登録しました。\n", name);
			fprintf_s(stdout, u8"-------------------------------------------------------\n");
			break;
		}
	}
}

// 解答の入力
int getAnswer(int size, int answer) {
	double d1;
	double d2;
	int playersAnswer = 0;

	// 行の入力
	while (1) {
		fprintf_s(stdout, u8"一つだけ異なる文字は、何行目ですか？(解答を入力したらEnterを押してください。\n");
		fprintf_s(stdout, u8"解答：");
		if (scanf_s("%lf", &d1) == 1 and d1 <= size and d1 > 0)
			break;
		fprintf_s(stdout, u8"1から%d行目までしかありません。もう一度入力してください。\n", size);
		scanf_s("%*[^\n]");
	}

	playersAnswer = d1;
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
	playersAnswer = playersAnswer * 10 + d2;

	return playersAnswer;
}