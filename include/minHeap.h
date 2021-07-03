struct minHeapNode{
    string data;
    unsigned long long freq;
    minHeapNode *left, *right;

    minHeapNode(string data, unsigned long long freq){
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