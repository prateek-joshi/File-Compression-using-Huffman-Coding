#include<iostream>
#include<vector>
#include<queue>
#include "utils/minHeap.h"
using namespace std;

// TODO: create a function to make Huffman codes
void HuffmanCodes(char *data, int *freq, int size){
    struct minHeapNode *left, *right, *top;

    priority_queue<minHeapNode*, vector<minHeapNode*>, compare> minHeap;

    for(int i=0;i<size;i++)
        minHeap.push(new minHeapNode(data[i], freq[i]));

    while(minHeap.size() > 1){
        // Extract the two minimum items from the queue
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();

        // create a new node which is the sum of the frequencies of the
        // two lowest nodes
        top = new minHeapNode('#', (left->freq + right->freq));
        top->left = left;
        top->right = right;

        // push it onto the queue
        minHeap.push(top);
    }
    cout<<"Huffman Tree Created!\n";
}

int main(){
    // TODO: write a function to calculate the frequency of all characters in a file.

    char data[] = {'a','f','d','s','e'}; //contains list of characters
    int freq[] = {10,2,3,5,6}; //frequency of each character

    int n = sizeof(data)/sizeof(data[0]);

    HuffmanCodes(data, freq, n);
    
    //create Huffman codes for each character
    cout<<endl;
    return 0;
}
