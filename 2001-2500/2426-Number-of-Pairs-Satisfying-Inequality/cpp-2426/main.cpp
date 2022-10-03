/// Source : https://leetcode.com/problems/number-of-pairs-satisfying-inequality/
/// Author : liuyubobobo
/// Time   : 2022-10-03

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Using AVL Tree
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
template<typename Key>
class AVLTreeMultiSet{

private:
    class Node{
    public:
        Key key;
        Node *left = nullptr, *right = nullptr;
        int height = 1, size = 1;

        Node(const Key& key): key(key){}
    };

    Node* root = nullptr;

public:
    AVLTreeMultiSet(){}

    int size(){
        return size(root);
    }

    void add(const Key& key){
        root = add(root, key);
    }

    void remove(const Key& key){
        root = remove(root, key);
    }

    bool contains(const Key& key){
        return get_node(root, key) != nullptr;
    }

    // 0-based rank
    int get_index(const Key& key){

        Node* node = get_node(root, key);
        assert(node);

        return size_less_than(key);
    }

    // 0-based select
    Key select(int index){

        assert(index < size(root));
        return select(root, index);
    }

    // < key 的元素有几个？
    int size_less_than(const Key& key){
        return size_less_than(root, key);
    }

    // <= key 的元素有几个？
    int size_less_than_or_equal_to(const Key& key){
        return size_less_than_or_equal_to(root, key);
    }

    // > key 的元素有几个？
    int size_larger_than(const Key& key){
        return size_larger_than(root, key);
    }

    // >= key 的元素有几个？
    int size_larger_than_or_equal_to(const Key& key){
        return size_larger_than_or_equal_to(root, key);
    }

private:
    int size(Node* node){
        return node ? node->size : 0;
    }

    int height(Node* node){
        return node ? node->height : 0;
    }

    int get_balance_factor(Node* node){
        return height(node->left) - height(node->right);
    }

    Node* right_rotate(Node* y) {
        Node* x = y->left;
        Node* T3 = x->right;

        // 向右旋转过程
        x->right = y;
        y->left = T3;

        // 更新 height 和 size
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        y->size = size(y->left) + size(y->right) + 1;
        x->size = size(x->left) + size(x->right) + 1;

        return x;
    }

    Node* left_rotate(Node* y) {
        Node* x = y->right;
        Node* T2 = x->left;

        // 向左旋转过程
        x->left = y;
        y->right = T2;

        // 更新 height 和 size
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        y->size = size(y->left) + size(y->right) + 1;
        x->size = size(x->left) + size(x->right) + 1;

        return x;
    }

    // 向以node为根的二分搜索树中插入元素(key, value)，递归算法
    // 返回插入新节点后二分搜索树的根
    Node* add(Node* node, const Key& key){

        if(node == nullptr)
            return new Node(key);

        if(key <= node->key)
            node->left = add(node->left, key);
        else if(key > node->key)
            node->right = add(node->right, key);

        return keep_balance(node);
    }

    Node* remove(Node* node, const Key& key){

        if(node == nullptr)
            return nullptr;

        Node* ret_node;
        if(key < node->key){
            node->left = remove(node->left, key);
            ret_node = node;
        }
        else if(key > node->key){
            node->right = remove(node->right, key);
            ret_node = node;
        }
        else{

            // 待删除节点左子树为空的情况
            if(node->left == nullptr){
                Node* right_node = node->right;
                node->right = nullptr;
                ret_node = right_node;
            }
                // 待删除节点右子树为空的情况
            else if(node->right == nullptr){
                Node* left_node = node->left;
                node->left = nullptr;
                ret_node = left_node;
            }
                // 待删除节点左右子树均不为空的情况
            else{
                // 找到比待删除节点大的最小节点, 即待删除节点右子树的最小节点
                // 用这个节点顶替待删除节点的位置
                Node* min_node = get_min_node(node->right);
                assert(min_node);
                node->key = min_node->key;

                node->right = remove_min(node->right);
                ret_node = node;
            }
        }

        return keep_balance(ret_node);
    }

    Node* remove_min(Node* node){

        if(node == nullptr)
            return nullptr;

        Node* ret_node;
        if(node->left) {
            node->left = remove_min(node->left);
            ret_node = node;
        }
        else
            ret_node = node->right;

        return keep_balance(ret_node);
    }

    Node* get_min_node(Node* node){

        if(!node) return nullptr;

        if(node->left) return get_min_node(node->left);
        return node;
    }

    Node* keep_balance(Node* node){

        if(!node) return nullptr;

        // 更新 height 和 size
        node->height = 1 + max(height(node->left), height(node->right));
        node->size = 1 + size(node->left) + size(node->right);

        // 计算平衡因子
        int balance_factor = get_balance_factor(node);

        // 平衡维护
        // LL
        if (balance_factor > 1 && get_balance_factor(node->left) >= 0)
            return right_rotate(node);

        // RR
        if (balance_factor < -1 && get_balance_factor(node->right) <= 0)
            return left_rotate(node);

        // LR
        if (balance_factor > 1 && get_balance_factor(node->left) < 0) {
            node->left = left_rotate(node->left);
            return right_rotate(node);
        }

        // RL
        if (balance_factor < -1 && get_balance_factor(node->right) > 0) {
            node->right = right_rotate(node->right);
            return left_rotate(node);
        }

        return node;
    }

    Node* get_node(Node* node, const Key& key){

        if(node == nullptr)
            return nullptr;

        if(key == node->key)
            return node;
        else if(key < node->key)
            return get_node(node->left, key);
        else
            return get_node(node->right, key);
    }

    Key select(Node* node, int index){

        if(index < size(node->left)) return select(node->left, index);

        if(index == size(node->left)) return node->key;

        return select(node->right, index - size(node->left) - 1);
    }

    // < key 的元素有几个
    int size_less_than(Node* node, const Key& key){
        if(!node) return 0;
        if(key <= node->key) return size_less_than(node->left, key);
        return size(node->left) + 1 + size_less_than(node->right, key);
    }

    // <= key 的元素有几个
    int size_less_than_or_equal_to(Node* node, const Key& key){
        if(!node) return 0;
        if(key < node->key) return size_less_than_or_equal_to(node->left, key);
        return size(node->left) + 1 + size_less_than_or_equal_to(node->right, key);
    }

    // > key 的元素有几个
    int size_larger_than(Node* node, const Key& key){
        if(!node) return 0;
        if(key >= node->key) return size_larger_than(node->right, key);
        return size_larger_than(node->left, key) + 1 + size(node->right);
    }

    // >= key 的元素有几个
    int size_larger_than_or_equal_to(Node* node, const Key& key){
        if(!node) return 0;
        if(key > node->key) return size_larger_than_or_equal_to(node->right, key);
        return size_larger_than_or_equal_to(node->left, key) + 1 + size(node->right);
    }
};

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {

        int n = nums1.size();
        vector<int> data(n);
        for(int i = 0; i < n; i ++) data[i] = nums1[i] - nums2[i];

        AVLTreeMultiSet<int> tree;
        for(int e: data) tree.add(e);

        long long res = 0;
        for(int e: data){
            tree.remove(e);
            res += tree.size_larger_than_or_equal_to(e - diff);
        }
        return res;
    }
};


int main() {

    return 0;
}
