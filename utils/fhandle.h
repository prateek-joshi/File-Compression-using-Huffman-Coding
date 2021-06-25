#include<fstream>
#include<cstring>
using namespace std;

void opener(fstream & file, char *filename, ios_base::openmode mode){
    try{
        file.open(filename, mode);
    } catch(exception & e){
        throw strcat((char*)"Could not open the file: ",filename);
    }
}