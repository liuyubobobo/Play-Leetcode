/// Source : https://leetcode.com/problems/my-calendar-ii/description/
/// Author : liuyubobobo
/// Time   : 2017-11-27

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Dynamic Segment Tree
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class MyCalendarThree {

private:
    struct Node{
        int left, right;
        int event = 0;
        int leftNodeIndex = -1, rightNodeIndex = -1;

        Node(int left, int right, int event){
            this->left = left;
            this->right = right;
            this->event = event;
        }
    };

    vector<Node> tree;

public:
    MyCalendarThree() {

        Node root(0, 1000000000, 0);
        tree.push_back(root);
    }

    int book(int start, int end) {

        add(0, start, end);
        return tree[0].event;
    }

private:
    int query(int treeID, int l, int r){

        if(l == tree[treeID].left && r == tree[treeID].right)
            return tree[treeID].event;

        if(tree[treeID].leftNodeIndex == -1)
            return tree[treeID].event;

        int leftNodeIndex = tree[treeID].leftNodeIndex;
        int rightNodeIndex = tree[treeID].rightNodeIndex;
        if(r <= tree[leftNodeIndex].right)
            return query(leftNodeIndex, l, r);
        else if(l >= tree[rightNodeIndex].left){
            return query(rightNodeIndex, l, r);
        }

        int leftEvent = query(leftNodeIndex, l, tree[leftNodeIndex].right);
        int rightEvent = query(rightNodeIndex, tree[rightNodeIndex].left, r);
        return max(leftEvent, rightEvent);
    }

    void add(int treeID, int l, int r){

        //assert(tree[treeID].left <= l && l < r && r <= tree[treeID].right);

        if(l == tree[treeID].left && r == tree[treeID].right){

            int leftNodeIndex, rightNodeIndex;
            if(tree[treeID].leftNodeIndex != -1){
                //assert(tree[treeID].rightNodeIndex != -1);

                leftNodeIndex = tree[treeID].leftNodeIndex;
                add(leftNodeIndex, tree[leftNodeIndex].left, tree[leftNodeIndex].right);

                rightNodeIndex = tree[treeID].rightNodeIndex;
                add(rightNodeIndex, tree[rightNodeIndex].left, tree[rightNodeIndex].right);

            }

            tree[treeID].event += 1;

            return;
        }

        if(tree[treeID].leftNodeIndex == -1){
            //assert(tree[treeID].rightNodeIndex == -1);

            int leftNodeIndex, rightNodeIndex;
            if(l == tree[treeID].left){
                Node leftNode(l, r, tree[treeID].event);
                leftNodeIndex = tree.size();
                tree.push_back(leftNode);
                tree[treeID].leftNodeIndex = leftNodeIndex;

                //assert(r < tree[treeID].right);
                Node rightNode(r, tree[treeID].right, tree[treeID].event);
                rightNodeIndex = tree.size();
                tree.push_back(rightNode);
                tree[treeID].rightNodeIndex = rightNodeIndex;

                add(leftNodeIndex, l, r);
            }
            else if(r == tree[treeID].right){
                //assert(tree[treeID].left < l);
                Node leftNode(tree[treeID].left, l, tree[treeID].event);
                leftNodeIndex = tree.size();
                tree.push_back(leftNode);
                tree[treeID].leftNodeIndex = leftNodeIndex;

                Node rightNode(l, r, tree[treeID].event);
                rightNodeIndex = tree.size();
                tree.push_back(rightNode);
                tree[treeID].rightNodeIndex = rightNodeIndex;

                add(rightNodeIndex, l, r);
            }
            else{
                //assert(tree[treeID].left < l);
                Node leftNode(tree[treeID].left, l, tree[treeID].event);
                leftNodeIndex = tree.size();
                tree.push_back(leftNode);
                tree[treeID].leftNodeIndex = leftNodeIndex;

                //assert(l < tree[treeID].right);
                Node rightNode(l, tree[treeID].right, tree[treeID].event);
                rightNodeIndex = tree.size();
                tree.push_back(rightNode);
                tree[treeID].rightNodeIndex = rightNodeIndex;

                add(rightNodeIndex, l, r);
            }

            int leftEvent = tree[leftNodeIndex].event;
            int rightEvent = tree[rightNodeIndex].event;
            tree[treeID].event = max(leftEvent, rightEvent);

            return;
        }

        int leftNodeIndex = tree[treeID].leftNodeIndex;
        int rightNodeIndex = tree[treeID].rightNodeIndex;
        //assert(leftNodeIndex + 1 == rightNodeIndex);
        //assert(tree[leftNodeIndex].right == tree[rightNodeIndex].left);

        if(r <= tree[leftNodeIndex].right){
            add(leftNodeIndex, l, r);
        }
        else if(l >= tree[rightNodeIndex].left){
            add(rightNodeIndex, l, r);
        }
        else{
            add(leftNodeIndex, l, tree[leftNodeIndex].right);
            add(rightNodeIndex, tree[rightNodeIndex].left, r);
        }

        int leftEvent = tree[leftNodeIndex].event;
        int rightEvent = tree[rightNodeIndex].event;
        tree[treeID].event = max(leftEvent, rightEvent);

        return;
    }
};


int main() {

    MyCalendarThree calendar;
    cout << calendar.book(10, 20) << endl; // 1
    cout << calendar.book(50, 60) << endl; // 1
    cout << calendar.book(10, 40) << endl; // 2
    cout << calendar.book(5, 15)  << endl; // 3
    cout << calendar.book(5, 10)  << endl; // 3
    cout << calendar.book(25, 55) << endl; // 3

    cout << endl;

    return 0;
}