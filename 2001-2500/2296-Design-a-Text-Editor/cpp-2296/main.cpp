/// Source : https://leetcode.com/problems/design-a-text-editor/
/// Author : liuyubobobo
/// Time   : 2022-06-04

#include <iostream>
#include <vector>

using namespace std;


/// Using Linked List
/// Time Complexity: init: O(1)
///                  add: O(|text|)
///                  delete: O(k)
///                  move: O(k)
/// Space Complexity: O(all_characters)
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

    Node<T>* remove(Node<T>* node){
//        assert(!node);
        Node<T>* ret = node->prev;
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
        return ret;
    }
};

class TextEditor {

private:
    LinkedList<char> L;
    Node<char>* cur;

public:
    TextEditor() {
        cur = L.head;
    }

    void addText(string text) {
        for(char c: text)
            L.add(cur, c), cur = cur->next;
    }

    int deleteText(int k) {

        int res = 0;
        while(k -- && cur != L.head){
            cur = L.remove(cur);
            res ++;
        }
        return res;
    }

    string cursorLeft(int k) {

        while(k -- && cur != L.head) cur = cur->prev;

        string ret = "";
        Node<char>* p = cur;
        for(int i = 0; i < 10 && p != L.head; i ++)
            ret += p->value, p = p->prev;
        reverse(ret.begin(), ret.end());
        return ret;
    }

    string cursorRight(int k) {
        while(k -- && cur->next != L.tail) cur = cur->next;

        string ret = "";
        Node<char>* p = cur;
        for(int i = 0; i < 10 && p != L.head; i ++)
            ret += p->value, p = p->prev;
        reverse(ret.begin(), ret.end());
        return ret;
    }
};


int main() {

    return 0;
}
