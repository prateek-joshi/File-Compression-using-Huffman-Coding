#include "../include/fhandle.h"
#include "../include/codegen.h"
#include<iostream>
using namespace std;

int main(int argc, char *argv[]){
    // check if filename is provided.
    if(argc==1)
        cout<< "Filename not provided.\n";
    else{
        minHeapNode *root = HuffmanCodes(argv[1]);
        generateCodes(root, (char*)"");

        cout<<endl;
    }
    return 0;
}
