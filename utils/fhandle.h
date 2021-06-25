#include<fstream>
using namespace std;

fstream & opener(char *filename, int mode){
    try{
        fstream file(filename, mode);
    } catch(exception & e){
        throw e.what();
    }
}