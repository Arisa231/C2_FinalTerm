#include "setting.h"

void description() {
    std::string str = "";

    std::ifstream file("description.txt");

    // �J���Ȃ�������G���[��Ԃ�
    if (!file)
        fprintf_s(stdout, u8"�t�@�C�����J�����Ƃ��ł��܂���ł����B\n");
    else {
        // ��s���ǂݍ���ŕ\������
        while (getline(file, str))
        {
            std::cout << str << std::endl;
        }
    }
    
    fprintf_s(stdout, u8"\n�D���ȃL�[�������ƁA���[�h�I���ɖ߂�܂��B\n");
    system("pause");
    fprintf_s(stdout, u8"\n\n");
}