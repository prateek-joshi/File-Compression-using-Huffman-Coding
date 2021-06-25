struct minHeapNode{
    char data;
    unsigned int freq;
    minHeapNode *left, *right;

    minHeapNode(char data, unsigned int freq){
        left = right = nullptr;
        this->data = data;
        this->freq = freq;
    }
};

struct compare {
    bool operator()(minHeapNode* l, minHeapNode* r){
        return (l->freq > r->freq);
    }
};