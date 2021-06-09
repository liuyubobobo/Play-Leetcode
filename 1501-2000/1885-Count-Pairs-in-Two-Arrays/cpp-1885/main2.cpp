/// Source : https://leetcode.com/problems/count-pairs-in-two-arrays/
/// Author : liuyubobobo
/// Time   : 2021-06-07

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// AVL
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

    // 1-based rank
    int rank(int key){

        Node* node = getNode(root, key);
        assert(node);

        return size_less_than(key) + 1;
    }

    int size_less_than(int key){
        return size_less_than(root, key);
    }

    int size_larger_than(int key){
        return size_larger_than(root, key);
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

    int size_less_than(Node* node, int key){
        if(!node) return 0;
        if(key <= node->key) return size_less_than(node->left, key);
        return size(node->left) + node->value + size_less_than(node->right, key);
    }

    int size_larger_than(Node* node, int key){
        if(!node) return 0;
        if(key >= node->key) return size_larger_than(node->right, key);
        return size(node->right) + node->value + size_larger_than(node->left, key);
    }
};

class Solution {
public:
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        assert(n == nums2.size());
        for(int i = 0; i < n; i ++) nums1[i] -= nums2[i];
//        for(int e: nums1) cout << e << " "; cout << endl;

        AVLTree tree;

        long long res = 0ll;
        for(int e: nums1){
            res += tree.size_larger_than(-e);
            tree.add(e);
        }
        return res;
    }
};


int main() {

    vector<int> nums11 = {2,1,2,1}, nums12 = {1,2,1,2};
    cout << Solution().countPairs(nums11, nums12) << endl;
    // 1

    vector<int> nums21 = {1,10,6,2}, nums22 = {1,4,1,5};
    cout << Solution().countPairs(nums21, nums22) << endl;
    // 5

    return 0;
}
