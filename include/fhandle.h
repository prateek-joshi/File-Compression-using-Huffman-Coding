#pragma once
#define LINE_SIZE 100
#include<fstream>
#include<cstring>
#include<unordered_map>
#include<iostream>
using namespace std;

void opener(fstream & file, const char *filename, ios_base::openmode mode){
    file.open(filename, mode);
    if(!file){
        cout<< "Could not open the file: "<<filename<<endl;
        exit(1);
    }
}

unordered_map<char, int> getFrequencyFromFile(const char *filename){
    fstream file;
    unordered_map<char, int> charFreq;
    // unordered_map<char, int>:: iterator it;
    string line;

    opener(file, filename, ios::in);

    while(!file.eof()){
        getline(file,line);
        // add characterwise frequency to map
        for(int i=0; i<line.size(); i++){
            if(charFreq.find(line[i])==charFreq.end())
                charFreq[line[i]] = 1;
            else
                charFreq[line[i]]++;
        }
    }

    for(auto it: charFreq)
        cout<<it.first<<' '<<it.second<<endl;
    cout<<endl;
    file.close();
    return charFreq;
}