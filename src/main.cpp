#include "../include/fhandle.h"
#include "../include/codegen.h"
#include<iostream>
using namespace std;

// Creates a minHeap for generating Huffman codes

int main(){
    // TODO: write a function to calculate the frequency of all characters in a file.

    char data[] = {'a','f','d','s','e'}; //contains list of characters
    int freq[] = {10,2,3,5,6}; //frequency of each character

    int n = sizeof(data)/sizeof(data[0]);

    minHeapNode *root = HuffmanCodes(data, freq, n);
    generateCodes(root, (char*)"");
    
    cout<<endl;
    return 0;
}
