#include "Setting.h"

int main()
{
	std::chrono::seconds playTime{30};
	char name[10];

	// コンソール画面の文字コードを UTF-8に設定
	SetConsoleOutputCP(CP_UTF8);

	while (1) {
		// ゲームのイントロダクション（タイトル表示とモード選択）
		int mode;
		mode = introduction();

		// ゲームプレイモード
		if (mode == 0) {
			fprintf_s(stdout, u8"ゲームプレイモードを選択しました。\n");
			getName(name);	// player nameの取得

			fprintf_s(stdout, u8"好きなキーを押すと、ゲームスタートです。\n");
			system("pause");

			int correct = playGame(playTime); // ゲームのプレイ
			result(name, correct, playTime);  // プレイ結果表示
		}

		// ゲームの説明を表示
		else if (mode == 1) {
			fprintf_s(stdout, u8"ゲーム説明モードを選択しました。\n\n");
			description();
		}

		// ランキングを表示
		else if (mode == 2) {
			fprintf_s(stdout, u8"ランキング表示モードを選択しました。\n\n");
			ranking();
		}
	}

	return 0;
}