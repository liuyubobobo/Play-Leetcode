/// Source : https://leetcode.com/problems/hand-of-straights/
/// Author : liuyubobobo
/// Time   : 2021-12-29

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Using Multiset
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        multiset<int> set;
        for(int e: hand) set.insert(e);

        while(!set.empty()){
            int start = *set.begin();
            for(int e = start; e < start + groupSize; e ++) {
                if (!set.count(e)) return false;
                set.erase(set.find(e));
            }
        }
        return true;
    }
};


int main() {

    return 0;
}
