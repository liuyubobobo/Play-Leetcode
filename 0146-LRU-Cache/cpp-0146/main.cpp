/// Source : https://leetcode.com/problems/lru-cache/
/// Author : liuyubobobo
/// Time   : 2019-03-02

#include <iostream>
#include <unordered_map>
#include <cassert>

using namespace std;


/// HashMap + Double Linked List
/// Time Complexity: init: O(1)
///                  get: O(1)
///                  put: O(1)
/// Space Complexity: O(n)
class LRUCache {

private:
    class Node{

    public:
        int key, value;
        Node *prev, *next;

        Node(int k, int v): key(k), value(v), prev(NULL), next(NULL){}
    };

    int capacity;
    unordered_map<int, Node*> data;

    Node* dummyHead;
    Node* tail;

public:
    LRUCache(int capacity): capacity(capacity){
        dummyHead = new Node(-1, -1);
        tail = new Node(-1, -1);

        dummyHead->next = tail;
        tail->prev = dummyHead;
    }

    ~LRUCache(){
        // TODO memory
    }

    int get(int key) {
//        cout << "get " << key << endl;
        if(data.count(key)){
            moveToHead(data[key]);
            assert(dummyHead->next);
//            debug();
            return dummyHead->next->value;
        }
        return -1;
    }

    void put(int key, int value) {
//        cout << "put " << key << " " << value << endl;
        if(data.count(key)){
            data[key]->value = value;
            moveToHead(data[key]);
            return;
        }

        data[key] = new Node(key, value);
        addFirst(data[key]);
//        debug();
        if(data.size() > capacity){
            assert(data.size() == capacity + 1);
            int delKey = removeLast();
            assert(data.count(delKey));
            data.erase(delKey);
//            debug();
        }
    }

private:
    void moveToHead(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;

        node->prev = node->next = NULL;
        addFirst(node);
    }

    void addFirst(Node* node){

        node->next = dummyHead->next;
        node->next->prev= node;

        node->prev = dummyHead;
        dummyHead->next = node;
    }

    int removeLast(){

        assert(tail->prev != dummyHead);
        Node* delNode = tail->prev;

        tail->prev = tail->prev->prev;
        tail->prev->next = tail;

        // TODO: delete delNode
        return delNode->key;
    }

    void debug(){

        cout << "Hash Map : sz = " << data.size() << endl;
        for(const pair<int, Node*>& p: data)
            cout << p.first << " : ( " << p.second->key << " , " << p.second->value << " )" << endl;

        cout << "Double Linked List : " << endl;
        Node* cur = dummyHead;
        while(cur)
            cout << "(" << cur->key << "," << cur->value << ") -> ", cur = cur->next;
        cout << "NULL" << endl << endl;
    }
};


int main() {

    LRUCache cache1(2);
    cache1.put(1, 1);
    cache1.put(2, 2);
    cout << cache1.get(1) << endl; // 1
    cache1.put(3, 3);
    cout << cache1.get(2) << endl; // -1
    cache1.put(4, 4);
    cout << cache1.get(1) << endl; // -1
    cout << cache1.get(3) << endl; // 3
    cout << cache1.get(4) << endl; // 4

    cout << endl;

    LRUCache cache2(2);
    cache2.put(2, 1);
    cache2.put(1, 1);
    cache2.put(2, 3);
    cache2.put(4, 1);
    cout << cache2.get(1) << endl; // -1
    cout << cache2.get(2) << endl; // 3

    return 0;
}