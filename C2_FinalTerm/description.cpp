#include "setting.h"

void showDescription() {
    fprintf_s(stdout, u8"-------------------------------------------------------\n");
    fprintf_s(stdout, u8"-------------------------------------------------------\n\n");

    std::string str;
    std::ifstream ifs("description.txt");
    if (ifs.fail()) {
        std::cerr << "ファイルを開くことができませんでした。" << std::endl;
    }
    while (getline(ifs, str)) {
        std::cout << str << std::endl;
    }

    fprintf_s(stdout, u8"\n-------------------------------------------------------\n");
    fprintf_s(stdout, u8"-------------------------------------------------------\n\n");
    
    fprintf_s(stdout, u8"\n好きなキーを押すと、モード選択に戻ります。\n");
    system("pause");
    fprintf_s(stdout, u8"\n\n");
}