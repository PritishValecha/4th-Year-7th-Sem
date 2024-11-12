#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct node {
    char cha;
    int freq;
    node* left;
    node* right;
    node(char c, int f) {
        cha = c;
        freq = f;
        left = NULL;
        right = NULL;
    }
};

struct Compare {
    bool operator() (node* left, node* right) {
        return left->freq > right->freq;
    }
};

void generateHuffmanCode (node* root, string code, map <char, string>& huffmanCode) {
    if(!root)
        return;

    if (!root->left && !root->right)
        huffmanCode[root->cha] = code;

    generateHuffmanCode(root->left, code+"0", huffmanCode);
    generateHuffmanCode(root->right, code+"1", huffmanCode);
}

map <char, string> huffmanEncoding (const map <char, int> freqMap) {
    priority_queue <node*, vector<node*>, Compare> minHeap;

    for (const auto& pair : freqMap)
        minHeap.push(new node(pair.first, pair.second));

    int sum;
    while (minHeap.size() > 1) {
        node* left = minHeap.top();
        minHeap.pop();
        node* right = minHeap.top();
        minHeap.pop();

        sum = left->freq + right->freq;
        node* internal = new node('\0', sum);
        internal->left = left;
        internal->right = right;

        minHeap.push(internal);
    }

    node* root = minHeap.top();
    map <char, string> huffmanCode;

    generateHuffmanCode(root, "", huffmanCode);

    return huffmanCode;
}

int main() {
    int n, freq;
    char c;
    map <char, int> freqMap;
    cout << "Enter the number of characters : ";
    cin >> n;
    for (int i=0; i<n; i++) {
        cout << "Enter the character : ";
        cin >> c;
        cout << "Enter the frequency of "<< c <<" : ";
        cin >> freq;
        freqMap[c] = freq;
    }

    map <char, string> huffmanCode;
    huffmanCode = huffmanEncoding(freqMap);

    for(const auto& pair : huffmanCode) {
        cout << pair.first << " -> " << pair.second << endl;
    }

    return 0;
}