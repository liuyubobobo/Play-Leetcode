/// Source : https://leetcode.com/problems/odd-even-jump/
/// Author : liuyubobobo
/// Time   : 2019-01-12

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Dynamic Programming
/// Using a self-implement BST to store the next step information :-)
/// Of course, using AVL or RBTree will be better, but for this problem, just BST is enough,
/// int main2, I will use RBTree in Standard Library :-)
///
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class BST{

private:
    class Node{
    public:
        int v, smallest_index, largest_index;
        Node* left, *right;

        Node(int v, int index): v(v), smallest_index(index), largest_index(index),
                                left(NULL), right(NULL){}
    };

    Node* root;

public:
    BST(): root(NULL){}

    void add(int v, int index){
        root = add(root, v, index);
    }

    int larger_than(int x){
        Node* ret = larger_than(root, x);
        if(!ret) return -1;
        return ret->smallest_index;
    }

    int smaller_than(int x){
        Node* ret = smaller_than(root, x);
        if(!ret) return -1;
        return ret->smallest_index;
    }

private:
    Node* smaller_than(Node* node, int x){

        if(!node) return NULL;
        if(node->v == x)
            return node;
        if(node->v < x){
            Node* ret = smaller_than(node->right, x);
            if(!ret) return node;
            return ret;
        }
        return smaller_than(node->left, x);
    }

    Node* larger_than(Node* node, int x){

        if(!node) return NULL;
        if(node->v == x)
            return node;
        if(node->v > x){
            Node* ret = larger_than(node->left, x);
            if(!ret) return node;
            return ret;
        }
        return larger_than(node->right, x);
    }

    Node* add(Node* node, int x, int index){

        if(!node) return new Node(x, index);

        if(x == node->v)
            node->smallest_index = min(node->smallest_index, index),
                    node->largest_index = max(node->largest_index, index);
        else if(x < node->v)
            node->left = add(node->left, x, index);
        else
            node->right = add(node->right, x, index);
        return node;
    }
};

class Solution {
public:
    int oddEvenJumps(const vector<int>& A) {

        int n = A.size();

        vector<int> larger(n, -1);
        larger[n - 1] = n - 1;
        BST bst1;
        bst1.add(A[n - 1], n - 1);
        for(int i = n - 2; i >= 0; i --){
            larger[i] = bst1.larger_than(A[i]);
            bst1.add(A[i], i);
        }
//        cout << "larger : ";
//        for(int e: larger)
//            cout << e << " ";
//        cout << endl;

        vector<int> smaller(n, -1);
        smaller[n - 1] = n - 1;
        BST bst2;
        bst2.add(A[n - 1], n - 1);
        for(int i = n - 2; i >= 0; i --){
            smaller[i] = bst2.smaller_than(A[i]);
            bst2.add(A[i], i);
        }
//        cout << "smaller : ";
//        for(int e: smaller)
//            cout << e << " ";
//        cout << endl;

        vector<vector<bool>> dp(n, vector<bool>(2, false));
        dp[n - 1][0] = dp[n - 1][1] = true;
        for(int i = n - 2; i >= 0; i --){
            if(larger[i] != -1)
                dp[i][0] = dp[larger[i]][1];
            if(smaller[i] != -1)
                dp[i][1] = dp[smaller[i]][0];
        }

        int res = 0;
        for(int i = 0; i < n; i ++)
            res += dp[i][0];
        return res;
    }
};


int main() {

    vector<int> A1 = {10,13,12,14,15};
    cout << Solution().oddEvenJumps(A1) << endl;
    // 2

    vector<int> A2 = {2,3,1,1,4};
    cout << Solution().oddEvenJumps(A2) << endl;
    // 3

    vector<int> A3 = {5,1,3,4,2};
    cout << Solution().oddEvenJumps(A3) << endl;
    // 3

    return 0;
}