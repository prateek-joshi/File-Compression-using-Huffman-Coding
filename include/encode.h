#pragma once
#include "./fhandle.h"
#include<string>
#include<bitset>
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

void storeEncodedText(string bstring){
    char *end;
    long long compressedText = strtoll(bstring.c_str(), &end, 2);

    fstream bfile;
    long long size = 0;

    opener(bfile, "compressed.bin", ios::binary|ios::out);
    bfile << compressedText;
    bfile.close();
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
    // cout<<encodedString<<endl;
    storeEncodedText(encodedString);
    // convert encoded string to binary and append to file
    datafile.close();
}