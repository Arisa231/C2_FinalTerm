#include "setting.h"

void playGame() {
	char char1[BUFFSIZE];
	char char2[BUFFSIZE];
	int answer = 0;
	int size = 0;

	// 5ラウンド
	for (int i = 1; i < 6; i++) {
		// 問題作成
		answer = 0;
		size = i * 4;

		answer = makeQuestion(char1, char2, size);

		// 問題表示
		fprintf_s(stdout, u8"-------------------------------------------------------\n");
		fprintf_s(stdout, u8"第%d問：\n\n", i);
		printQuestion(char1, char2, size, answer);

		// 解答入力
		fprintf_s(stdout, "\n\n");
		putAnswer(size, answer);

		// Enterキーが入力されたら、次の問題へ
		fprintf_s(stdout, u8"次の問題へ進むには、好きなキーを押してください。\n");
		system("pause");
		fprintf_s(stdout, "\n");
	}
}