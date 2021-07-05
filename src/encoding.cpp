#include "../include/encode.h"
#include<string>
#include<iomanip>
#include<map>
using namespace std;

string codefile = "codes.txt";

int main(){
    compressFile("codes.txt","sample_file.txt");
    return 0;
}