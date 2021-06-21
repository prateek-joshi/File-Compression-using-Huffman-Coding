#include<bits/stdc++.h>
using namespace std;

struct minHeapNode{
    char data;
    unsigned int freq;
    minHeapNode *left, *right;

    minHeapNode(char data, unsigned int freq){
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

//create a function to make Huffman codes

int main(){
    char data[] = {}; //contains list of characters
    int freq[] = (); //frequency of each character

    int n = sizeof(data)/sizeof(data[0]);

    //create Huffman codes for each character

    return 0;
}
