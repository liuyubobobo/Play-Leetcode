/// Source : https://leetcode.com/problems/range-module/description/
/// Author : liuyubobobo
/// Time   : 2017-10-24

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Dynamic Segment Tree
class RangeModule {

private:
    struct Node{
        int left, right;
        bool isTracked;
        bool pure = true;
        int leftNodeIndex = -1, rightNodeIndex = -1;

        Node(int left, int right, bool isTracked){
            this->left = left;
            this->right = right;
            this->isTracked = isTracked;
        }
    };

    vector<Node> tree;

public:
    RangeModule() {

        Node root(1, 1000000000, false);
        tree.push_back(root);
    }

    void addRange(int left, int right) {

        setRange(0, left, right, true);
    }

    void removeRange(int left, int right) {

        setRange(0, left, right, false);
    }

    bool queryRange(int left, int right) {

        return queryRange(0, left, right);
    }

private:
    void setRange(int treeIndex, int l, int r, bool tracked){

        assert(tree[treeIndex].left <= l && l < r && r <= tree[treeIndex].right);
        if(tree[treeIndex].pure && tree[treeIndex].isTracked == tracked)
            return;

        if(l == tree[treeIndex].left && r == tree[treeIndex].right){
            tree[treeIndex].isTracked = tracked;
            tree[treeIndex].pure = true;
            if(tree[treeIndex].leftNodeIndex != -1){
                assert(tree[treeIndex].rightNodeIndex != -1);

                int leftNodeIndex = tree[treeIndex].leftNodeIndex;
                setRange(leftNodeIndex, tree[leftNodeIndex].left, tree[leftNodeIndex].right, tracked);

                int rightNodeIndex = tree[treeIndex].rightNodeIndex;
                setRange(rightNodeIndex, tree[rightNodeIndex].left, tree[rightNodeIndex].right, tracked);
            }

            return;
        }

        if(tree[treeIndex].leftNodeIndex == -1){
            assert(tree[treeIndex].rightNodeIndex == -1);
            assert(tree[treeIndex].pure);

            int leftNodeIndex, rightNodeIndex;
            if(l == tree[treeIndex].left){
                Node leftNode(l, r, tree[treeIndex].isTracked);
                leftNodeIndex = tree.size();
                tree.push_back(leftNode);
                tree[treeIndex].leftNodeIndex = leftNodeIndex;

                assert(r < tree[treeIndex].right);
                Node rightNode(r, tree[treeIndex].right, tree[treeIndex].isTracked);
                rightNodeIndex = tree.size();
                tree.push_back(rightNode);
                tree[treeIndex].rightNodeIndex = rightNodeIndex;

                setRange(leftNodeIndex, l, r, tracked);
            }
            else if(r == tree[treeIndex].right){
                assert(tree[treeIndex].left < l);
                Node leftNode(tree[treeIndex].left, l, tree[treeIndex].isTracked);
                leftNodeIndex = tree.size();
                tree.push_back(leftNode);
                tree[treeIndex].leftNodeIndex = leftNodeIndex;

                Node rightNode(l, r, tree[treeIndex].isTracked);
                rightNodeIndex = tree.size();
                tree.push_back(rightNode);
                tree[treeIndex].rightNodeIndex = rightNodeIndex;

                setRange(rightNodeIndex, l, r, tracked);
            }
            else{
                assert(tree[treeIndex].left < l);
                Node leftNode(tree[treeIndex].left, l, tree[treeIndex].isTracked);
                leftNodeIndex = tree.size();
                tree.push_back(leftNode);
                tree[treeIndex].leftNodeIndex = leftNodeIndex;

                assert(l < tree[treeIndex].right);
                Node rightNode(l, tree[treeIndex].right, tree[treeIndex].isTracked);
                rightNodeIndex = tree.size();
                tree.push_back(rightNode);
                tree[treeIndex].rightNodeIndex = rightNodeIndex;

                setRange(rightNodeIndex, l, r, tracked);
            }

            tree[treeIndex].pure = (tree[leftNodeIndex].pure && tree[rightNodeIndex].pure &&
                                    tree[leftNodeIndex].isTracked == tree[rightNodeIndex].isTracked);
            if(tree[treeIndex].pure) {
                tree[treeIndex].isTracked = tree[leftNodeIndex].isTracked;
                assert(tree[treeIndex].isTracked == tree[leftNodeIndex].isTracked);
            }

            return;
        }

        int leftNodeIndex = tree[treeIndex].leftNodeIndex;
        int rightNodeIndex = tree[treeIndex].rightNodeIndex;
        assert(leftNodeIndex + 1 == rightNodeIndex);
        assert(tree[leftNodeIndex].right == tree[rightNodeIndex].left);

        if(r <= tree[leftNodeIndex].right){
            setRange(leftNodeIndex, l, r, tracked);
        }
        else if(l >= tree[rightNodeIndex].left){
            setRange(rightNodeIndex, l, r, tracked);
        }
        else{
            setRange(leftNodeIndex, l, tree[leftNodeIndex].right, tracked);
            setRange(rightNodeIndex, tree[rightNodeIndex].left, r, tracked);
        }

        tree[treeIndex].pure = (tree[leftNodeIndex].pure && tree[rightNodeIndex].pure &&
                tree[leftNodeIndex].isTracked == tree[rightNodeIndex].isTracked);
        if(tree[treeIndex].pure){
            tree[treeIndex].isTracked = tree[leftNodeIndex].isTracked;
            assert(tree[treeIndex].isTracked == tree[rightNodeIndex].isTracked);
        }

        return;
    }

    bool queryRange(int treeIndex, int l, int r){

        assert(tree[treeIndex].left <= l && l < r && r <= tree[treeIndex].right);

        if(l == tree[treeIndex].left && r == tree[treeIndex].right)
            return tree[treeIndex].pure && tree[treeIndex].isTracked;

        if(tree[treeIndex].leftNodeIndex == -1){
            assert(tree[treeIndex].rightNodeIndex == -1);
            assert(tree[treeIndex].pure);
            return tree[treeIndex].isTracked;
        }

        int leftNodeIndex = tree[treeIndex].leftNodeIndex;
        int rightNodeIndex = tree[treeIndex].rightNodeIndex;
        assert(leftNodeIndex + 1 == rightNodeIndex);
        assert(tree[leftNodeIndex].right == tree[rightNodeIndex].left);

//        if(tree[treeIndex].isLazy){
//            tree[leftNodeIndex].isTracked = tree[treeIndex].isTracked;
//            tree[leftNodeIndex].isLazy = true;
//            tree[rightNodeIndex].isTracked = tree[treeIndex].isTracked;
//            tree[rightNodeIndex].isLazy = true;
//
//            tree[treeIndex].isLazy = false;
//        }

        if(r <= tree[leftNodeIndex].right)
            return queryRange(leftNodeIndex, l, r);
        else if(l >= tree[rightNodeIndex].left)
            return queryRange(rightNodeIndex, l, r);
        else{
            return queryRange(leftNodeIndex, l, tree[leftNodeIndex].right)
                    && queryRange(rightNodeIndex, tree[rightNodeIndex].left, r);
        }
    }
};


void printBool(bool v){
    cout << (v ? "true" : "false") << endl;
}

int main() {

    RangeModule obj1;
    obj1.addRange(10, 20);
    obj1.removeRange(14, 16);

    printBool(obj1.queryRange(10, 14));
    printBool(obj1.queryRange(13, 15));
    printBool(obj1.queryRange(16, 17));

    cout << endl;

    RangeModule obj2;
    obj2.addRange(6,8);
    obj2.removeRange(7,8);
    obj2.removeRange(8,9);
    obj2.addRange(8,9);
    obj2.removeRange(1,3);
    obj2.addRange(1,8);
    printBool(obj2.queryRange(2,4));
    printBool(obj2.queryRange(2,9));
    printBool(obj2.queryRange(4,6));

    return 0;
}