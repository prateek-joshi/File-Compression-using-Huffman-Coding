#pragma once
#include<fstream>
#include<cstring>
#include<unordered_map>
#include<iostream>
#define LINE_SIZE 100
using namespace std;

void opener(fstream & file, const char *filename, ios_base::openmode mode){
    file.open(filename, mode);
    if(!file){
        cout<< "Could not open the file: "<<filename<<endl;
        exit(1);
    }
}

unordered_map<string, long long> getFrequencyFromFile(const char *filename){
    fstream file;
    unordered_map<string, long long> charFreq;
    // unordered_map<char, int>:: iterator it;
    string line;

    opener(file, filename, ios::in);

    while(!file.eof()){
        getline(file,line);
        // add characterwise frequency to map
        for(int i=0; i<line.size(); i++){
            string s(1, line[i]);
            if(charFreq.find(s)==charFreq.end())
                charFreq[s] = 1;
            else
                charFreq[s]++;
        }
        // TODO: handle newlines in text file.
        charFreq["\\n"]++;
    }

    // for(auto it: charFreq)
    //     cout<<it.first<<' '<<it.second<<endl;
    // cout<<endl;
    file.close();
    return charFreq;
}