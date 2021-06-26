#define LINE_SIZE 100
#include<fstream>
#include<cstring>
#include<unordered_map>
using namespace std;

void opener(fstream & file, const char *filename, ios_base::openmode mode){
    try{
        file.open(filename, mode);
    } catch(exception & e){
        throw strcat((char*)"Could not open the file: ",filename);
    }
}

unordered_map<char, int> & getFrequencyFromFile(const char *filename){
    fstream file;
    unordered_map<char, int> charFreq;
    unordered_map<char, int>:: iterator it;
    char *line = (char*)malloc(LINE_SIZE*sizeof(char));

    opener(file, filename, ios::in);

    while(!file.eof()){
        file.getline(line,LINE_SIZE);
        // add characterwise frequency to map
        for(int i=0; i<LINE_SIZE; i++){
            charFreq[line[i]]++;
        }
    }

    file.close();
    return charFreq;
}