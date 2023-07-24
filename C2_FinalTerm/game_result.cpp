#include "setting.h"

void result(char name[10], int correct, std::chrono::seconds playTime) {
	fprintf_s(stdout, u8"\n\n");
	fprintf_s(stdout, u8"-------------------------------------------------------\n");
	fprintf_s(stdout, u8"--------------------GAME-RESULT------------------------\n");
	fprintf_s(stdout, u8"-------------------------------------------------------\n\n");
	fprintf_s(stdout, u8"%sのスコア：\n", name);
	fprintf_s(stdout, u8"正解数：%d, かかった時間：", correct);
	std::cout << playTime.count() << u8"秒\n\n" << std::endl;

	fprintf_s(stdout, u8"好きなキーを押すと、モード選択に戻ります。\n");
	system("pause");

	fprintf_s(stdout, u8"-------------------------------------------------------\n");
	fprintf_s(stdout, u8"-------------------------------------------------------\n\n");
}
