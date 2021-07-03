#pragma once
#include "./fhandle.h"
#include<string>
#include<iostream> //temporary
using namespace std;

unordered_map<string,int> unpackCodesFromFile(string codefile){
    fstream file;
    opener(file,codefile.c_str(),ios::in);
    unordered_map<string,int> codes;
    string encoded_text;

    while(!file.eof()){
        string key, code;
        getline(file, key, '|');
        getline(file,code,'\n');

        codes[key] = stoi(code);
    }

    return codes;
}

