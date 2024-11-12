#include <iostream>
#include <map>
#include <queue>
using namespace std;

struct node
{
    char ch;
    int freq;
    node* left;
    node* right;
    node (char c, int f) {
        ch = c;
        freq = f;
        left = NULL;
        right = NULL;
    }
};

struct Comparator {
    bool operator() (node* left, node* right) {
        return left->freq > right->freq;
    }
};

void huffmanEncoding(node* root, string code, map<char, string>& huffmanCode) {
    if (!root)
        return;

    if (!root->left && !root->right)
        huffmanCode[root->ch] = code;

    huffmanEncoding (root->left, code+'0', huffmanCode);
    huffmanEncoding (root->right, code+'1', huffmanCode);
}

map <char, string> huffmanCoding (map <char, int> freqMap) {
    priority_queue <node*, vector<node*>, Comparator> minHeap;

    for (const auto& pair : freqMap) {
        minHeap.push(new node(pair.first, pair.second));
    }

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
    huffmanEncoding(root, "", huffmanCode);

    return huffmanCode;
}

int main() {
    int n;
    cout << "Enter the number of characters : ";
    cin >> n;
    map <char, int> freqMap;
    char c;
    int f;
    for (int i=0; i<n;  i++) {
        cout << "Enter the character : ";
        cin >> c;
        cout << "Enter frequency of the character "<< c << " : ";
        cin >> f;
        freqMap[c] = f; 
    }

    map <char, string> huffmanCode;
    huffmanCode = huffmanCoding(freqMap);

    for (const auto& pair : huffmanCode) {
        cout << pair.first << " -> " << pair.second << endl;
    }

    return 0;
}