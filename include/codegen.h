#include "../include/minHeap.h"
#include<string>
#include<vector>
#include<queue>
#include<iostream>
#include<map>
using namespace std;

minHeapNode* HuffmanCodes(unordered_map<char,int> & charFreq){
    struct minHeapNode *left, *right, *top;

    priority_queue<minHeapNode*, vector<minHeapNode*>, compare> minHeap;

    for(auto it: charFreq)
        minHeap.push(new minHeapNode(it.first, it.second));

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
    return minHeap.top();
}

void generateCodes(struct minHeapNode* root,string code) {
    if(!root)
        return;
    if(root->data != '#')
        // cout<<"hash"<<endl;
        cout<<root->data<<": "<<code<<endl;

    generateCodes(root->left, code+"0");
    generateCodes(root->right, code+"1");
}