#include "Setting.h"

int main()
{
	time_t startTime, endTime, playTime;
	char name[10];

	// コンソール画面の文字コードを UTF-8に設定
	SetConsoleOutputCP(CP_UTF8);

	while (1) {
		startTime = time(NULL);
		endTime = time(NULL);

		// ゲームのイントロダクション（タイトル表示とモード選択）
		int mode;
		mode = introduction();

		// ゲームプレイモード
		if (mode == 0) {
			fprintf_s(stdout, u8"ゲームプレイモードを選択しました。\n");
			getName(name);								// player nameの取得
			fprintf_s(stdout, u8"好きなキーを押すと、ゲームスタートです。\n");
			system("pause");
			int correct = playGame(startTime, endTime); // ゲームのプレイ
			playTime = endTime - startTime;				// プレイ時間計算
			result(name, correct, playTime);			// プレイ結果表示
		}

		// ゲームの説明を表示
		else if (mode == 1)
			description();
		// ランキングを表示

		else if (mode == 2)
			ranking();
	}
}