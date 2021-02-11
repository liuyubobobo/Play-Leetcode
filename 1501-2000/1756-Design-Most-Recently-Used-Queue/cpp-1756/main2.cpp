/// Source : https://leetcode.com/problems/design-most-recently-used-queue/
/// Author : liuyubobobo
/// Time   : 2021-02-10

#include <iostream>
#include <vector>

using namespace std;


/// Using AVL Tree
/// Time Complexity: init: O(nlogn)
///                  fetch: O(logn)
/// Space Complexity: O(n)
template<typename Key, typename Value>
class AVLTree{

private:
    class Node{
    public:
        Key key;
        Value value;
        Node *left = nullptr, *right = nullptr;
        int height = 1, size = 1;

        Node(const Key& key, const Value& value): key(key), value(value){}
    };

    Node* root = nullptr;

public:
    AVLTree(){}

    int size(){
        return size(root);
    }

    // 向二分搜索树中添加新的元素(key, value)
    void add(const Key& key, const Value& value){
        root = add(root, key, value);
    }

    bool contains(const Key& key){
        return getNode(root, key) != nullptr;
    }

    Value get(const Key& key){
        Node* node = getNode(root, key);
        assert(node);
        return node->value;
    }

    void set(const Key& key, const Value& newValue){
        Node* node = getNode(root, key);
        assert(node);
        node->value = newValue;
    }

    // 从二分搜索树中删除键为key的节点
    Value remove(const Key& key){

        Node* node = getNode(root, key);
        assert(node);

        root = remove(root, key);
        return node->value;
    }

    int rank(const Key& key){

        Node* node = getNode(root, key);
        assert(node);

        return rank(root, key);
    }

    Key select(int rank){
        return select(root, rank);
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

        y->size = size(y->left) + size(y->right) + 1;
        x->size = size(x->left) + size(x->right) + 1;

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

        y->size = size(y->left) + size(y->right) + 1;
        x->size = size(x->left) + size(x->right) + 1;

        return x;
    }

    // 向以node为根的二分搜索树中插入元素(key, value)，递归算法
    // 返回插入新节点后二分搜索树的根
    Node* add(Node* node, const Key& key, const Value& value){

        if(node == nullptr){
            return new Node(key, value);
        }

        if(key < node->key)
            node->left = add(node->left, key, value);
        else if(key > node->key)
            node->right = add(node->right, key, value);
        else // key.compareTo(node.key) == 0
            node->value = value;

        // 更新 height 和 size
        node->height = 1 + max(height(node->left), height(node->right));
        node->size = 1 + size(node->left) + size(node->right);

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
    Node* getNode(Node* node, const Key& key){

        if(node == nullptr)
            return nullptr;

        if(key == node->key)
            return node;
        else if(key < node->key)
            return getNode(node->left, key);
        else // if(key.compareTo(node.key) > 0)
            return getNode(node->right, key);
    }

    // 返回以node为根的二分搜索树的最小值所在的节点
    Node* minimum(Node* node){
        if(!node->left) return node;
        return minimum(node->left);
    }

    Node* remove(Node* node, const Key& key){

        if(node == nullptr) return nullptr;

        Node* retNode;
        if(key < node->key){
            node->left = remove(node->left, key);
            retNode = node;
        }
        else if(key > node->key){
            node->right = remove(node->right, key);
            retNode = node;
        }
        else{   // key == node.key

            if(node->left == nullptr){ // 待删除节点左子树为空的情况
                Node* rightNode = node->right;
                node->right = nullptr;
                retNode = rightNode;
            }
            else if(node->right == nullptr){ // 待删除节点右子树为空的情况
                Node* leftNode = node->left;
                node->left = nullptr;
                retNode = leftNode;
            }
            else{ // 待删除节点左右子树均不为空的情况
                // 找到比待删除节点大的最小节点, 即待删除节点右子树的最小节点
                // 用这个节点顶替待删除节点的位置
                Node* successor = minimum(node->right);
                successor->right = remove(node->right, successor->key);
                successor->left = node->left;

                node->left = node->right = nullptr;

                retNode = successor;
            }
        }

        if(retNode == nullptr) return nullptr;

        // 更新 height 和 size
        retNode->height = 1 + max(height(retNode->left), height(retNode->right));
        retNode->size = 1 + size(retNode->left) + size(retNode->right);

        // 计算平衡因子
        int balanceFactor = getBalanceFactor(retNode);

        // 平衡维护
        // LL
        if (balanceFactor > 1 && getBalanceFactor(retNode->left) >= 0)
            return rightRotate(retNode);

        // RR
        if (balanceFactor < -1 && getBalanceFactor(retNode->right) <= 0)
            return leftRotate(retNode);

        // LR
        if (balanceFactor > 1 && getBalanceFactor(retNode->left) < 0) {
            retNode->left = leftRotate(retNode->left);
            return rightRotate(retNode);
        }

        // RL
        if (balanceFactor < -1 && getBalanceFactor(retNode->right) > 0) {
            retNode->right = rightRotate(retNode->right);
            return leftRotate(retNode);
        }

        return retNode;
    }

    int rank(Node* node, const Key& key){
        if(key == node->key) return size(node->left) + 1;
        if(key < node->key) return rank(node->left, key);
        return size(node->left) + 1 + rank(node->right, key);
    }

    int select(Node* node, int rank){

        if(size(node->left) == rank) return node->key;

        if(rank < size(node->left)) return select(node->left, rank);
        return select(node->right, rank - size(node->left) - 1);
    }
};

class MRUQueue {

private:
    int maxid;
    AVLTree<int, int> tree;

public:
    MRUQueue(int n) : maxid(n) {
        for(int i = 0; i < n; i ++)
            tree.add(i, i + 1);
    }

    int fetch(int k) {
        k --;
        int key = tree.select(k), value = tree.get(key);
        tree.remove(key);
        tree.add(maxid ++, value);
        return value;
    }
};


int main() {

    MRUQueue q(8);
    cout << q.fetch(3) << endl; // 3
    cout << q.fetch(5) << endl; // 6
    cout << q.fetch(2) << endl; // 2
    cout << q.fetch(8) << endl; // 2

    return 0;
}
