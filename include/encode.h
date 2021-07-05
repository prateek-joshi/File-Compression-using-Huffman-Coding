#pragma once
#include "./fhandle.h"
#include<string>
#include<iostream> //temporary
using namespace std;

unordered_map<string,string> unpackCodesFromFile(string codefile){
    fstream file;
    opener(file,codefile.c_str(),ios::in);
    unordered_map<string,string> codes;
    string encoded_text;

    while(!file.eof()){
        string key, code;
        char *end;

        getline(file, key, '|');
        getline(file,codes[key],'\n');
    }

    file.close();
    return codes;
}

// TODO
long long encodeText(unordered_map<string, long long> codes, string line){
    long long compressedText = 0;

    return compressedText;
}

void compressFile(string codefile, string file) {
    unordered_map<string, string> codes = unpackCodesFromFile(codefile);
    string encodedString = "", line = "";
    
    // temporary
    // for(auto i: codes)
    //     cout<<i.first<<' '<<i.second<<endl;

    fstream datafile;
    opener(datafile,file.c_str(),ios::in);

    while(!datafile.eof()){
        getline(datafile, line);
        for(int i: line){
            string key(1, i);
            encodedString += codes[key];
        }
        encodedString += codes["\\n"];
    }
    cout<<encodedString<<endl;
    datafile.close();
}