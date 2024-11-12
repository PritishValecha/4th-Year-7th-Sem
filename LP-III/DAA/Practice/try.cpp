#include <iostream>
#include <vector>

#define Q 'Q'
#define E '.'

using namespace std;

bool isSafe (vector <string>& board, int row, int col, int n) {
    for (int i=0; i<row; i++) {
        if (board[i][col] == Q)
            return false;
    }

    for (int i=row, j=col; i>=0 && j>=0; i--, j--) {
        if (board[i][j] == Q)
            return false;
    }

    for (int i=row, j=col; i>=0 && j<n; i--, j++) {
        if (board[i][j] == Q)
            return false;
    }

    return true;
}

bool nQueens (vector <string>& board, int row, int n) {
    if (row >= n)
        return true;

    for (int i=0; i<n; i++) {
        if (isSafe(board, row, i, n)) {
            board[row][i] = Q;

            if (nQueens(board, row+1, n))
                return true;

            board[row][i] = E;
        }
    }
    return false;
}

int main() {
    int n;
    cout << "Enter the size of the board : ";
    cin >> n;

    vector <string> board (n, string(n, E));

    if (nQueens(board, 0, n)) {
        cout << "Solution is : " << endl;
        for (const auto& s: board) {
            cout << s << endl;
        }
    }
    else {
        cout << "no solution";
    }

    return 0;
}




// #include <iostream>
// #include <vector>

// using namespace std;

// int dpKS (vector <int>& weights, vector <int>& values, int n, int capacity) {
//     vector <vector <int>> dp (n+1, vector <int> (capacity+1, 0));

//     for (int i=1; i<=n; i++) {
//         for (int w=0; w<=capacity; w++) {
//             if (w >= weights[i-1])
//                 dp[i][w] = max(dp[i-1][w], dp[i-1][w - weights[i-1]]+values[i-1]);
//             else
//                 dp[i][w] = dp[i-1][w];
//         }
//     }
//     return dp[n][capacity];
// }

// int main() {
//     int n, capacity;
//     cout << "Enter the capacity of the sack : ";
//     cin >> capacity;
//     cout << "Enter the number of items : ";
//     cin >> n;

//     vector <int> weights(n), values(n);
//     for (int i=0; i<n; i++) {
//         cout << "Item " << i+1 << " : " << endl;
//         cout << "Enter value of the item : ";
//         cin >> values[i];
//         cout << "Enter weight of the item : ";
//         cin >> weights[i];
//     }

//     int max = dpKS(weights, values, n, capacity);
//     cout << "Maximum value is : " << max;

//     return 0;
// }




// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// struct item {
//     double weight;
//     double value;
// };

// bool comapre (item a, item b) {
//     double r1 = a.value/a.weight;
//     double r2 = b.value/b.weight;
//     return r1 > r2;
// }

// double fractionalKS (vector <item>& items, int capacity) {
//     sort(items.begin(), items.end(), comapre);

//     double max = 0.0;
//     for (const auto& it : items) {
//         if (capacity >= it.weight) {
//             capacity -= it.weight;
//             max += it.value;
//         }
//         else {
//             max += it.value*(capacity/it.weight);
//             break;
//         }
//     }

//     return max;
// }

// int main() {
//     int n, capacity;
//     cout << "Enter the capacity of the sack : ";
//     cin >> capacity;
//     cout << "Enter the number of items : ";
//     cin >> n;

//     vector <item> items(n);
//     for (int i=0; i<n; i++) {
//         cout << "Item " << i+1 << " : " << endl;
//         cout << "Enter the value of item : ";
//         cin >> items[i].value;
//         cout << "Enter the weight of item : ";
//         cin >> items[i].weight;
//     }

//     double max = fractionalKS(items, capacity);

//     cout << "Maximum value is : " << max;

//     return 0;
// }



// #include <iostream>
// #include <map>
// #include <queue>

// using namespace std;

// struct node {
//     char ch;
//     int freq;
//     node* left;
//     node* right;
//     node(char c, int fr) {
//         ch = c;
//         freq = fr;
//         left = NULL;
//         right = NULL;
//     }
// };

// void generateHuffman(map <char, string>& huffmanCode, node* root, string code) {
//     if (!root)
//         return;

//     if (!root->left && !root->right)
//         huffmanCode[root->ch] = code;

//     generateHuffman(huffmanCode, root->left, code+'0');
//     generateHuffman(huffmanCode, root->right, code+'1');
// }

// struct compare{
//     bool operator() (node* left, node* right) {
//         return left->freq > right->freq;
//     }
// };

// map <char, string> huffmanEncoding(map <char, int> charFrequency) {
//     priority_queue <node*, vector <node*>, compare> minHeap;
    
//     for (const auto& pair : charFrequency) {
//         minHeap.push(new node(pair.first, pair.second));
//     }

//     int sum;
//     node* l, *r;
//     while (minHeap.size() > 1)
//     {
//         l = minHeap.top();
//         minHeap.pop();
//         r = minHeap.top();
//         minHeap.pop();
//         sum = l->freq + r->freq;
//         node* internal = new node('\0', sum);
//         internal->left = l;
//         internal->right = r;
//         minHeap.push(internal);
//     }
    
//     node* root = minHeap.top();
//     map <char, string> huffmanCode;
//     generateHuffman(huffmanCode, root, "");
    
//     return huffmanCode;
// }

// int main() {
//     int n;
//     cout << "Enter the number of characters : ";
//     cin >> n;

//     map <char, int> charF;
//     char c;
//     int f;
//     for (int i=0; i<n; i++) {
//         cout << "Enter the character : ";
//         cin >> c;
//         cout << "Enter the frequency of the character : ";
//         cin >> f;
//         charF[c] = f;
//     }

//     map <char, string> huffmanCode;
//     huffmanCode = huffmanEncoding(charF);

//     for (const auto& pair : huffmanCode) {
//         cout << pair.first << " -> " << pair.second << endl;
//     }
    
//     return 0;
// }





// #include <iostream>
// using namespace std;

// int fibI(int n) {
//     if (n <= 1)
//         return 1;

//     int a=0, b=1, c;
//     for (int i=1; i<n; i++) {
//         c = a + b;
//         a = b;
//         b = c;
//     }
//     return c;
// }

// int fibR(int n) {
//     if (n <= 2)
//         return 1;

//     return fibR(n-1) + fibR(n-2);
// }

// int main() {
//     int n;
//     cout << "Enter a number : ";
//     cin >> n;

//     int fi = fibI(n);
//     int fr = fibR(n);

//     cout << "Iterative : " << fi << endl;
//     cout << "Recursive : " << fr << endl;

//     return 0;
// }