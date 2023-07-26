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
		mode = chooseMode();

		// ゲームプレイモード
		if (mode == 0) {
			fprintf_s(stdout, u8"ゲームプレイモードを選択しました。\n");
			getName(name);	// player nameの取得

			fprintf_s(stdout, u8"好きなキーを押すと、ゲームスタートです。\n");
			system("pause");

			playGame(name, playTime); // ゲームのプレイ
		}

		// ゲームの説明を表示
		else if (mode == 1) {
			fprintf_s(stdout, u8"ゲーム説明モードを選択しました。\n\n");
			showDescription();
		}

		// プレイ履歴を表示
		else if (mode == 2) {
			fprintf_s(stdout, u8"プレイ履歴表示モードを選択しました。\n\n");
			char fileName[BUFFSIZE] = "result.txt";
			readResult(fileName);
		}

		// ゲームの終了
		else if (mode == 3) {
			fprintf_s(stdout, u8"ゲームを終了します。\n");
			fprintf_s(stdout, u8"-------------------------------------------------------\n");
			fprintf_s(stdout, u8"-------------------------------------------------------\n");
			break;
		}
	}

	return 0;
}