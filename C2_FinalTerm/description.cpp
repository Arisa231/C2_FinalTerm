#include "setting.h"

void showDescription() {
    fprintf_s(stdout, u8"-------------------------------------------------------\n");
    fprintf_s(stdout, u8"-------------------------------------------------------\n\n");

    std::string str;
    std::ifstream ifs("description.txt");
    if (ifs.fail()) {
        std::cerr << "�t�@�C�����J�����Ƃ��ł��܂���ł����B" << std::endl;
    }
    while (getline(ifs, str)) {
        std::cout << str << std::endl;
    }

    fprintf_s(stdout, u8"\n-------------------------------------------------------\n");
    fprintf_s(stdout, u8"-------------------------------------------------------\n\n");
    
    fprintf_s(stdout, u8"\n�D���ȃL�[�������ƁA���[�h�I���ɖ߂�܂��B\n");
    system("pause");
    fprintf_s(stdout, u8"\n\n");
}