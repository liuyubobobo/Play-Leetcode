/// Source : https://leetcode.com/problems/steps-to-make-array-non-decreasing/
/// Author : liuyubobobo
/// Time   : 2022-06-04

#include <iostream>
#include <vector>
#include <deque>

using namespace std;


/// Linked List Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(n)
template<typename T>
class Node{
public:
    T value;
    Node* next, *prev;
    Node(T v, Node* next, Node* prev) : value(v), next(next), prev(prev){}
    Node(T v) : Node(v, nullptr, nullptr){}
    Node(): Node(T()){}
};

template<typename T>
class LinkedList{
public:
    Node<T>* head, *tail;

    LinkedList(){
        head = new Node<T>();
        tail = new Node<T>();
        head->next = tail;
        tail->prev = head;
    }

    void add(Node<T>* pre, T v){
        Node<T>* new_node = new Node<T>(v);
        add(pre, new_node);
    }

    void add_first(T v){
        add(head, v);
    }

    void add_last(T v){
        add(tail->prev, v);
    }

    void add(Node<T>* pre, Node<T>* new_node){
        new_node->next = pre->next;
        pre->next = new_node;
        new_node->next->prev = new_node;
        new_node->prev = pre;
    }

    void add_first(Node<T>* new_node){
        add(head, new_node);
    }

    void add_last(Node<T>* new_node){
        add(tail->prev, new_node);
    }

    // return node->next
    Node<T>* remove(Node<T>* node){
//        assert(!node);
        Node<T>* ret = node->next;
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
        return ret;
    }
};

class Solution {
public:
    int totalSteps(vector<int>& nums) {

        LinkedList<int> linkedList;
        deque<Node<int>*> del;
        for(int i = (int)nums.size() - 1; i >= 0; i --){
            linkedList.add_first(nums[i]);
            if(i - 1 >= 0 && nums[i - 1] > nums[i])
                del.push_back(linkedList.head->next);
        }

        int res = 0;
        while(!del.empty()){
            int n = del.size();
            for(int i = 0; i < n; i ++){
                Node<int>* del_node = del.front(); del.pop_front();
                Node<int>* next = linkedList.remove(del_node);
                if(next != linkedList.tail && next->prev != linkedList.head && next->prev->value > next->value){
                    if(del.empty() || del.back() != next)
                        del.push_back(next);
                }
            }
            res ++;
        }
        return res;
    }
};


int main() {

    vector<int> nums1 = {7, 14, 4, 14, 13, 2, 6, 13};
    cout << Solution().totalSteps(nums1) << '\n';
    // 3

    return 0;
}
