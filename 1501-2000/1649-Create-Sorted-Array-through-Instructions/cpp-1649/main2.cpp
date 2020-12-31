/// Source : https://leetcode.com/problems/create-sorted-array-through-instructions/
/// Author : liuyubobobo
/// Time   : 2020-11-17

#include <iostream>
#include <set>
#include <vector>

using namespace std;


/// AVL Tree
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class AVLTree{

private:
    class Node{
    public:
        int key, value = 1;
        Node *left = nullptr, *right = nullptr;
        int height = 1, size = 1;

        Node(int key): key(key){}
    };

    Node* root = nullptr;

public:
    AVLTree(){}

    int size(){
        return size(root);
    }

    // 向二分搜索树中添加新的元素(key, value)
    void add(int key){
        root = add(root, key);
    }

    bool contains(int key){
        return getNode(root, key) != nullptr;
    }

    int get(int key){
        Node* node = getNode(root, key);
        assert(node);
        return node->value;
    }

    int rank(int key){

        Node* node = getNode(root, key);
        assert(node);

        return rank(root, key);
    }

private:
    int size(Node* node){
        return node ? node->size : 0;
    }

    int height(Node* node){
        return node ? node->height : 0;
    }

    int getBalanceFactor(Node* node){
        return height(node->left) - height(node->right);
    }

    // 对节点y进行向右旋转操作，返回旋转后新的根节点x
    //        y                              x
    //       / \                           /   \
    //      x   T4     向右旋转 (y)        z     y
    //     / \       - - - - - - - ->    / \   / \
    //    z   T3                       T1  T2 T3 T4
    //   / \
    // T1   T2
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T3 = x->right;

        // 向右旋转过程
        x->right = y;
        y->left = T3;

        // 更新 height 和 size
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        y->size = size(y->left) + size(y->right) + y->value;
        x->size = size(x->left) + size(x->right) + x->value;

        return x;
    }

    // 对节点y进行向左旋转操作，返回旋转后新的根节点x
    //    y                             x
    //  /  \                          /   \
    // T1   x      向左旋转 (y)       y     z
    //     / \   - - - - - - - ->   / \   / \
    //   T2  z                     T1 T2 T3 T4
    //      / \
    //     T3 T4
    Node* leftRotate(Node* y) {
        Node* x = y->right;
        Node* T2 = x->left;

        // 向左旋转过程
        x->left = y;
        y->right = T2;

        // 更新 height 和 size
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        y->size = size(y->left) + size(y->right) + y->value;
        x->size = size(x->left) + size(x->right) + x->value;

        return x;
    }

    // 向以node为根的二分搜索树中插入元素(key, value)，递归算法
    // 返回插入新节点后二分搜索树的根
    Node* add(Node* node, int key){

        if(node == nullptr){
            return new Node(key);
        }

        if(key < node->key)
            node->left = add(node->left, key);
        else if(key > node->key)
            node->right = add(node->right, key);
        else // key.compareTo(node.key) == 0
            node->value ++, node->size ++;

        // 更新 height 和 size
        node->height = 1 + max(height(node->left), height(node->right));
        node->size = node->value + size(node->left) + size(node->right);

        // 计算平衡因子
        int balanceFactor = getBalanceFactor(node);

        // 平衡维护
        // LL
        if (balanceFactor > 1 && getBalanceFactor(node->left) >= 0)
            return rightRotate(node);

        // RR
        if (balanceFactor < -1 && getBalanceFactor(node->right) <= 0)
            return leftRotate(node);

        // LR
        if (balanceFactor > 1 && getBalanceFactor(node->left) < 0) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // RL
        if (balanceFactor < -1 && getBalanceFactor(node->right) > 0) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // 返回以node为根节点的二分搜索树中，key所在的节点
    Node* getNode(Node* node, int key){

        if(node == nullptr)
            return nullptr;

        if(key == node->key)
            return node;
        else if(key < node->key)
            return getNode(node->left, key);
        else // if(key.compareTo(node.key) > 0)
            return getNode(node->right, key);
    }

    int rank(Node* node, int key){
        if(key == node->key) return size(node->left) + 1;
        if(key < node->key) return rank(node->left, key);
        return size(node->left) + node->value + rank(node->right, key);
    }
};

class Solution {

private:
    const int MOD = 1e9 + 7;

public:
    int createSortedArray(vector<int>& instructions) {

        AVLTree tree;
        int res = 0;
        for(int e: instructions){
            tree.add(e);
            int left = tree.rank(e) - 1;
            int right = tree.size() - left - tree.get(e);
            res += min(left, right);
            res %= MOD;
        }
        return res;
    }
};


int main() {

    vector<int> ins1 = {1,5,6,2};
    cout << Solution().createSortedArray(ins1) << endl;
    // 1

    vector<int> ins2 = {1,2,3,6,5,4};
    cout << Solution().createSortedArray(ins2) << endl;
    // 3

    vector<int> ins3 = {1,3,3,3,2,4,2,1,2};
    cout << Solution().createSortedArray(ins3) << endl;
    // 4

    return 0;
}
