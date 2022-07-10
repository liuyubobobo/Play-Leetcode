/// Source : https://leetcode.com/problems/smallest-number-in-infinite-set/
/// Author : liuyubobobo
/// Time   : 2022-06-08

#include <iostream>
#include <set>

using namespace std;


/// Using Set
/// Time Complexity: init: O(1)
///                  pop: O(logn)
///                  add: O(logn)
/// Space Compelxity: O(n)
class SmallestInfiniteSet {

private:
    int start = 1;
    set<int> others;

public:
    SmallestInfiniteSet() {}

    int popSmallest() {

        if(!others.empty()){
            int ret = *others.begin();
            others.erase(others.begin());
            return ret;
        }

        int ret = start;
        start ++;
        return ret;
    }

    void addBack(int num) {

        if(others.count(num) || num >= start) return;

        if(num == start - 1){
            start --;
            while(true){
                auto iter = others.find(start - 1);
                if(iter != others.end()){
                    others.erase(iter);
                    start --;
                }
                else break;
            }
        }
        else{
            others.insert(num);
        }
    }
};


int main() {

    return 0;
}
