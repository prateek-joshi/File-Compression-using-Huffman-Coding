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
    char *line = (char*)malloc(LINE_SIZE*sizeof(char));

    opener(file, filename, ios::in);

    while(!file.eof()){
        file.getline(line,LINE_SIZE);
        // add characterwise frequency to map
        for(int i=0; i<LINE_SIZE; i++){
            // myrecipe.insert (std::make_pair<std::string,double>("eggs",6.0));
            if(charFreq.find(line[i]) == charFreq.end()){
                // not found, insert new pair
                charFreq.insert({line[i],1});
            }
            else{
                // increment existing frequency term
                charFreq[line[i]]++;
            }
        }
    }

    file.close();
    return charFreq;
}