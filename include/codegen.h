#include "./minHeap.h"
#include "./fhandle.h"
#include<string>
#include<vector>
#include<queue>
#include<iostream>
#include<map>
using namespace std;

minHeapNode* HuffmanCodes(const char *filename){
    struct minHeapNode *left, *right, *top;
    unordered_map<char,int> charFreq = getFrequencyFromFile(filename);
    priority_queue<minHeapNode*, vector<minHeapNode*>, compare> minHeap;

    for(auto it: charFreq)
        minHeap.push(new minHeapNode(it.first, it.second));

    while(minHeap.size() > 1){
        // Extract the two minimum items from the queue
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();

        // create a new node which is the sum of the frequencies of the two lowest nodes
        top = new minHeapNode('#', (left->freq + right->freq));
        top->left = left;
        top->right = right;

        // push it onto the queue
        minHeap.push(top);
    }
    cout<<"Huffman Tree Created!\n";
    return minHeap.top();
}

void generateCodes(struct minHeapNode* root,string code) {
    if(!root)
        return;

    generateCodes(root->left, code+"0");    // 0 if left
    if(root->data != '#')   //print value if required node is reached (not dummy character)
        cout<<root->data<<": "<<code<<endl;
    generateCodes(root->right, code+"1");   // 1 if right
}