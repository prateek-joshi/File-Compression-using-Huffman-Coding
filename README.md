# Huffman-Coding
Huffman coding is a method of assigning binary codes to individual distinct characters, based on their frequency of repetition or probability of occurrence. Huffman codes can be of variable length and are prefix-free, meaning no code is the prefix of another. This methodology can be used to compress files, by constructing a prefix tree for all the characters in the file based on their weights.
## Implementation
Prefix trees for assigning Huffman codes are binary in nature, as the codes themselves are binary. This construction algorithm uses a minHeap, implemented using a priority queue, to build the Huffman tree. Each node of the tree contains the following:
- The character
- Frequency of repetition
- Address of the left child
- Address of the right child
![Huffman Tree Example](https://upload.wikimedia.org/wikipedia/commons/thumb/8/82/Huffman_tree_2.svg/1920px-Huffman_tree_2.svg.png "Sample Huffman Tree")

The characters that are the most frequently repeated are at the top of the tree, so that they can be accessed with the least number of seeks. All nodes except the leaf nodes contain:
- a placeholder character ('#' in this case)
- Total frequencies of its left and right subtrees

## Usage
The following commands are applicable for windows systems.
```
home> cd File-Compression-using-Huffman-Coding
home\File-Compression-using-Huffman-Coding> g++ -std=c++17 src\encoding.cpp
home\File-Compression-using-Huffman-Coding> .\a.exe file-to-be-compressed.txt
```
The following script generates a compressed binary file **compressed.bin**. The codes generated are stored in a text file named **codes.txt**. This can be used for decompression later on.

## To be done...
- Decompression algorithm
- Functionality to specify the name of the generated compressed file
- Functionality to specify the name of the generated codes file
