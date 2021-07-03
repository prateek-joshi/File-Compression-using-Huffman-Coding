#pragma once
#include "./fhandle.h"
#include<string>
#include<iostream> //temporary
using namespace std;

unordered_map<string,long long> unpackCodesFromFile(string codefile){
    fstream file;
    opener(file,codefile.c_str(),ios::in);
    unordered_map<string,long long> codes;
    string encoded_text;

    while(!file.eof()){
        string key, code;
        char *end;

        getline(file, key, '|');
        getline(file,code,'\n');

        codes[key] = strtoll(code.c_str(),&end,2);
    }

    return codes;
}

