#include<iostream>
#include<vector>
#include<queue>
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
    int data[] = {1,2,23,14,5}; //contains list of characters
    //int freq[] = {}; //frequency of each character

    int n = sizeof(data)/sizeof(data[0]);

    priority_queue<int, vector<int>, greater<int>> pq;

    for(auto i: data){
        pq.push(i);
    }

    while(!pq.empty()){
        cout<<pq.top()<<' ';
        pq.pop();
    }
    //create Huffman codes for each character
    cout<<endl;
    return 0;
}
