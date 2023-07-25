#include "setting.h"

// プレイ結果の出力
void result(char name[10], int correct, std::chrono::seconds playTime) {
	fprintf_s(stdout, u8"\n\n");
	fprintf_s(stdout, u8"-------------------------------------------------------\n");
	fprintf_s(stdout, u8"--------------------GAME-RESULT------------------------\n");
	fprintf_s(stdout, u8"-------------------------------------------------------\n\n");
	fprintf_s(stdout, u8"%sのスコア：\n", name);
	fprintf_s(stdout, u8"正解数：%d, かかった時間：", correct);
	std::cout << playTime.count() << u8"秒\n\n" << std::endl;

	// プレイ結果をファイルに出力
	char fileName1[BUFFSIZE] = "result.txt";
	writeResult(fileName1, name, correct, playTime);

	fprintf_s(stdout, u8"好きなキーを押すと、モード選択に戻ります。\n");
	system("pause");

	fprintf_s(stdout, u8"-------------------------------------------------------\n");
	fprintf_s(stdout, u8"-------------------------------------------------------\n\n");
}

// プレイ結果を"result.txt"に書き込む
void writeResult(const char* fileName, char name[10], int correct, std::chrono::seconds playTime) {
	std::ofstream writingFile(fileName, std::ios::app);
	writingFile <<  name << "," << correct << "," << playTime.count() << std::endl;
	writingFile.close();
}

// プレイ履歴を"result.txt"から読み込んで、コンソール画面に出力
void readResult(const char* fileName) {
	std::cout << u8"-------------------------------------------------------" << std::endl;
	std::ifstream ifs(fileName);
	std::string str;
	if (ifs.fail()) {
		std::cerr << "ファイルを開くことができませんでした。" << std::endl;
	}
	while (getline(ifs, str)) {
		std::cout << str << std::endl;
	}
	std::cout << u8"-------------------------------------------------------\n" << std::endl;
	fprintf_s(stdout, u8"好きなキーを押すと、モード選択に戻ります。\n");
	system("pause");
}