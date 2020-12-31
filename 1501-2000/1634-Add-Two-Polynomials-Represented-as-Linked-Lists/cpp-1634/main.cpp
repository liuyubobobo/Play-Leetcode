/// Source : https://leetcode.com/problems/add-two-polynomials-represented-as-linked-lists/
/// Author : liuyubobobo
/// Time   : 2020-11-01

#include <iostream>

using namespace std;


/// Linear Scan
/// Time Complexity: O(n + m)
/// Space Complexity: O(1)

/// Definition for polynomial singly-linked list.
struct PolyNode {
    int coefficient, power;
    PolyNode *next;
    PolyNode(): coefficient(0), power(0), next(nullptr) {};
    PolyNode(int x, int y): coefficient(x), power(y), next(nullptr) {};
    PolyNode(int x, int y, PolyNode* next): coefficient(x), power(y), next(next) {};
};

class Solution {
public:
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {

        PolyNode* dummyHead = new PolyNode();
        PolyNode* cur = dummyHead;
        PolyNode* a = poly1, *b = poly2;
        while(a || b){
            if(!a) cur->next = new PolyNode(b->coefficient, b->power), cur = cur->next, b = b ->next;
            else if(!b) cur->next = new PolyNode(a->coefficient, a->power), cur = cur->next, a = a ->next;
            else if(a->power == b->power){
                if(a->coefficient + b->coefficient){
                    cur->next = new PolyNode(a->coefficient + b->coefficient, a->power);
                    cur = cur->next;
                }
                a = a->next, b = b->next;
            }
            else if(a->power > b->power) cur->next = new PolyNode(a->coefficient, a->power), cur = cur->next, a = a ->next;
            else cur->next = new PolyNode(b->coefficient, b->power), cur = cur->next, b = b ->next;
        }
        return dummyHead->next;
    }
};


int main() {

    return 0;
}
