//
//  main.cpp
//  mecab_test
//
//  Created by 山口 周悟 on 2017/01/27.
//  Copyright © 2017年 shugo. All rights reserved.
//

#include "mecab_util.h"

int main(int argc, char **argv) {
    //parseTest("すもももももももものうち");
    //wakachigakiTest("すもももももももものうち");
    //parseNodeTest2("すもももももももものうち");
//    kaigyouTestV2("すもももももももものうち", 10);
//    kaigyouTestV2("すもももももももものうち", 9);
//    kaigyouTestV2("すもももももももものうち", 7);
    std::string str;
    //str = "あの日見た花の名前を僕達はまだ知らないかもしれない．";
    str = "日本国民は、正当に選挙された国会における代表者を通じて行動し、われらとわれらの子孫のために、諸国民との協和による成果と、わが国全土にわたって自由のもたらす恵沢を確保し、政府の行為によって再び戦争の惨禍が起ることのないやうにすることを決意し、ここに主権が国民に存することを宣言し、この憲法を確定する。";
    parseNodeTest2(str);
    kaigyouTestV2(str, 21);
}


