#include "setting.h"

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

void writeResult(const char* fileName, char name[10], int correct, std::chrono::seconds playTime) {
	std::ofstream writingFile;
	std::string fileName1 = fileName;
	writingFile.open(fileName1, std::ios::app);

	writingFile <<  name << "," << correct << "," << playTime.count() << "\n" << std::endl;
	writingFile.close();
}

void readResult(const char* fileName) {
	std::ifstream ifs(fileName);
	std::string str;

	if (ifs.fail()) {
		std::cerr << "ファイルを開くことができませんでした。" << std::endl;
	}
	while (getline(ifs, str)) {
		std::cout << str << std::endl;
	}
}