#include "setting.h"

void description() {
    std::string str = "";

    std::ifstream file("description.txt");

    // 開けなかったらエラーを返す
    if (!file)
        fprintf_s(stdout, u8"ファイルを開くことができませんでした。\n");
    else {
        // 一行ずつ読み込んで表示する
        while (getline(file, str))
        {
            std::cout << str << std::endl;
        }
    }
    
    fprintf_s(stdout, u8"\n好きなキーを押すと、モード選択に戻ります。\n");
    system("pause");
    fprintf_s(stdout, u8"\n\n");
}