#include "../include/fhandle.h"
#include "../include/codegen.h"
#include "../include/encdec.h"
#include<iostream>
using namespace std;

string codefile = "codes.txt";

int main(int argc, char *argv[]){
    // check if filename is provided.
    if(argc==1)
        cout<< "Filename not provided.\n";
    else{
        string filename = argv[1];
        minHeapNode *root = HuffmanCodes(filename.c_str());
        generateCodes(root, (char*)"");

        compressFile(codefile,filename);
    }
    return 0;
}
