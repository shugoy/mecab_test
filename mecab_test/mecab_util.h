//
//  mecab_util.h
//  mecab_test
//
//  Created by 山口 周悟 on 2017/01/27.
//  Copyright © 2017年 shugo. All rights reserved.
//

#ifndef mecab_util_h
#define mecab_util_h
#include <iostream>
#include <mecab.h>

void parseTest(std::string input){
    
    MeCab::Tagger *tagger = MeCab::createTagger("");
    const char *result = tagger->parse(input.c_str());
    
    std::cout << result << std::endl;
    
    delete tagger;
}

void wakachigakiTest(std::string input){
    
    MeCab::Tagger *tagger = MeCab::createTagger("-Owakati");
    const char *result = tagger->parse(input.c_str());
    
    std::cout << result << std::endl;
    
    delete tagger;
}

void parseNodeTest(std::string input){
    
    MeCab::Tagger *tagger = MeCab::createTagger("");
    const MeCab::Node* node = tagger->parseToNode(input.c_str());
    
    for (; node; node = node->next) {
        std::cout << std::string(node->surface,node->length) << std::endl;
        std::cout << "==========" << std::endl;
        std::cout << "id        : " << node->id        << std::endl;
        std::cout << "surface   : " << node->surface   << std::endl;
        std::cout << "feature   : " << node->feature   << std::endl;
        std::cout << "length    : " << node->length    << std::endl;
        std::cout << "rlength   : " << node->rlength   << std::endl;
        std::cout << "rcAttr    : " << node->rcAttr    << std::endl;
        std::cout << "lcAttr    : " << node->lcAttr    << std::endl;
        std::cout << "posid     : " << node->posid     << std::endl;
        std::cout << "char_type : " << (int)node->char_type << std::endl;
        std::cout << "stat      : " << (int)node->stat      << std::endl;
        std::cout << "isbest    : " << (int)node->isbest    << std::endl;
        std::cout << "alpha     : " << node->alpha     << std::endl;
        std::cout << "beta      : " << node->beta      << std::endl;
        std::cout << "prob      : " << node->prob      << std::endl;
        std::cout << "wcost     : " << node->wcost     << std::endl;
        std::cout << "cost      : " << node->cost      << std::endl;
    }
    
    delete tagger;
}

void parseNodeTest2(std::string input){
    
    MeCab::Tagger *tagger = MeCab::createTagger("");
    const MeCab::Node* node = tagger->parseToNode(input.c_str());
    
    for (; node; node = node->next) {
        if (node->length == 0) continue;
        std::cout << std::string(node->surface,node->length) << std::endl;
        std::cout << "feature   : " << node->feature   << std::endl;
        std::cout << std::endl;
    }
    
    delete tagger;
}

void kaigyouTest(std::string input, int maxnum){
    
    std::cout << "max " << maxnum << std::endl;
    for (int i=0; i<maxnum; i++) {
        std::cout << "ー";
    }
    std::cout << std::endl;
    
    MeCab::Tagger *tagger = MeCab::createTagger("");
    const MeCab::Node* node = tagger->parseToNode(input.c_str());
    
    std::string temp;
    int curr_num = 0;
    for (; node; node = node->next) {
        
        if (node->length == 0) continue;
        
        temp = std::string(node->surface,node->length);
        
        int len = node->length;
        if (node->char_type == 6) {
            len /= 3;
        }
        curr_num += len;
        if (curr_num > maxnum) {
            std::cout << std::endl;
            curr_num = 0;
        }
        std::cout << temp << " ";
        
    }
    std::cout << std::endl;
    
    
    delete tagger;
}

int lennode(const MeCab::Node* node) {
    int len = node->length;
    switch (node->char_type) {
        case 2:
        case 6:
        case 3:
            len /= 3;
            break;
            
        default:
            break;
    }
    return len;
}

void kaigyouTestV2(std::string input, int maxnum){
    
    for (int i=0; i<maxnum; i++) std::cout << "ー";
    std::cout << "max " << maxnum << std::endl;
    
    MeCab::Tagger *tagger = MeCab::createTagger("");
    const MeCab::Node* node = tagger->parseToNode(input.c_str());
    
    std::string temp;
    int curr_num = 0;
    for (; node; node = node->next) {
        
        if (node->length == 0) continue;
        
        temp = std::string(node->surface,node->length);
        
        int len = lennode(node);
        curr_num += len;
        
        int temp_num = curr_num;
        
        MeCab::Node* nextNode = node->next;
        while (true) {
            std::string feature(nextNode->feature);
            size_t found1 = feature.find("助詞");
            size_t found2 = feature.find("記号");
            size_t found3 = feature.find("記号");
            if (found1 != std::string::npos || found2 != std::string::npos || found3 != std::string::npos) {
                temp_num += lennode(nextNode);
                nextNode = nextNode->next;
            }
            else break;
            
        }
        if (temp_num > maxnum) {
            std::cout << std::endl;
            curr_num = len;
        }
        
        std::cout << temp;
        //std::cout << len;
        
    }
    std::cout << std::endl;
    
    
    delete tagger;
}

#endif /* mecab_util_h */
