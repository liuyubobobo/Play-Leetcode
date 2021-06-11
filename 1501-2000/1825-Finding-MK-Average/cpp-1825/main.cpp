/// Source : https://leetcode.com/problems/finding-mk-average/
/// Author : liuyubobobo
/// Time   : 2021-06-10

#include <iostream>
#include <deque>
#include <set>

using namespace std;


/// Tree MultiSet
/// make the minTree to be full first, make the middleTree to be full second
/// Time Complexity: O(mlogm)
/// Space Complexity: O(m)
class MKAverage {

private:
    int m, k;
    deque<int> q;
    multiset<int> minTree, maxTree, middleTree;
    long long sum = 0ll;

public:
    MKAverage(int m, int k) : m(m), k(k) {}

    void addElement(int num) {

        if(q.size() == m){
            int front = q.front();
            q.pop_front();

            remove(front);
        }

        add(num);
        q.push_back(num);
    }

    void remove(int e){

        multiset<int>::iterator iter = maxTree.find(e);
        if(iter != maxTree.end()){
            maxTree.erase(iter);
            return;
        }

        iter = middleTree.find(e);
        if(iter != middleTree.end()){
            middleTree.erase(iter);
            sum -= e;

            while(middleTree.size() < m - 2 * k && maxTree.size()){
                int e = *maxTree.begin();
                maxTree.erase(maxTree.begin());

                middleTree.insert(e);
                sum += e;
            }

            return;
        }

        assert(minTree.count(e));
        minTree.erase(minTree.find(e));

        while(minTree.size() < k && middleTree.size()){
            int e = *middleTree.begin();
            middleTree.erase(middleTree.begin());
            sum -= e;

            minTree.insert(e);
        }

        while(middleTree.size() < m - 2 * k && maxTree.size()){
            int e = *maxTree.begin();
            maxTree.erase(maxTree.begin());

            middleTree.insert(e);
            sum += e;
        }
    }

    void add(int e){

        minTree.insert(e);

        while(minTree.size() > k){
            int e = *minTree.rbegin();
            minTree.erase((--minTree.end()));

            middleTree.insert(e);
            sum += e;
        }

        while(middleTree.size() > m - 2 * k){
            int e = *middleTree.rbegin();
            middleTree.erase((--middleTree.end()));
            sum -= e;

            maxTree.insert(e);
        }
    }

    int calculateMKAverage() {
        if(q.size() < m) return -1;
        return sum / (m - 2 * k);
    }
};


int main() {

//    ["MKAverage","addElement","addElement","calculateMKAverage","addElement","calculateMKAverage","addElement","addElement","addElement","calculateMKAverage"]
//    [[3,1],[3],[1],[],[10],[],[5],[5],[5],[]]
    MKAverage o1(3, 1);
    o1.addElement(3);
    o1.addElement(1);
    cout << o1.calculateMKAverage() << endl; // -1
    o1.addElement(10);
    cout << o1.calculateMKAverage() << endl; // 3

    cout << endl;

//    ["MKAverage","addElement","addElement","calculateMKAverage","addElement","addElement","calculateMKAverage","addElement","addElement","calculateMKAverage","addElement"]
//    [[3,1],[17612],[74607],[],[8272],[33433],[],[15456],[64938],[],[99741]]
    MKAverage o2(3, 1);
    o2.addElement(17612);
    o2.addElement(74607);
    cout << o2.calculateMKAverage() << endl; // -1
    o2.addElement(8272);
    o2.addElement(33433);
    cout << o2.calculateMKAverage() << endl; // 33433
    o2.addElement(15456);
    o2.addElement(64938);
    cout << o2.calculateMKAverage() << endl; // 33433

    return 0;
}
