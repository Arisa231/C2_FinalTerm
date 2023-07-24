#include "setting.h"

int introduction() {
	double d;
	fprintf_s(stdout, u8"-------------------------------------------------------\n");
	fprintf_s(stdout, u8"-------------------漢字間違い探しゲーム----------------\n");
	fprintf_s(stdout, u8"-------------------------------------------------------\n\n");

	fprintf_s(stdout, u8"モードを選択して、0〜2の数字を入力してください。\n");
	fprintf_s(stdout, u8"0：ゲームをプレイ\n");
	fprintf_s(stdout, u8"1：ゲームの説明を読む\n");
	fprintf_s(stdout, u8"2：ゲームのプレイ結果ランキングを見る\n\n");

	while (1) {
		if (scanf_s("%lf", &d) == 1 and d >= 0 and d <= 2)
			break;
		fprintf_s(stdout, u8"0〜2の数字を入力してください。\n");
		scanf_s("%*[^\n]");
	}

	if (d == 0)
		return 0;
	else if (d == 1)
		return 1;
	else if (d == 2)
		return 2;
}

void description() {

}

void ranking() {

}