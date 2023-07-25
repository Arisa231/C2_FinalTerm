#include "setting.h"

int introduction() {
	double d;
	fprintf_s(stdout, u8"-------------------------------------------------------\n");
	fprintf_s(stdout, u8"-----------------文字間違い探しゲーム------------------\n");
	fprintf_s(stdout, u8"-------------------------------------------------------\n\n");

	fprintf_s(stdout, u8"モードを選択して、0〜3の数字を入力してください。\n");
	fprintf_s(stdout, u8"0：ゲームをプレイ\n");
	fprintf_s(stdout, u8"1：ゲームの説明を読む\n");
	fprintf_s(stdout, u8"2：ゲームのプレイ履歴を見る\n");
	fprintf_s(stdout, u8"3：ゲームを終了する\n\n");
	fprintf_s(stdout, u8"入力：");

	while (1) {
		if (scanf_s("%lf", &d) == 1 and d >= 0 and d <= 3)
			break;
		fprintf_s(stdout, u8"0〜3の数字を入力してください。\n");
		scanf_s("%*[^\n]");
	}

	if (d == 0)
		return 0;
	else if (d == 1)
		return 1;
	else if (d == 2)
		return 2;
	else if (d == 3)
		return 3;
}