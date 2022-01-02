/// Source : https://leetcode.com/problems/destroying-asteroids/
/// Author : liuyubobobo
/// Time   : 2022-01-01

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Using Multiset
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {

        multiset<long long, greater<long long>> data;
        for(int e: asteroids) data.insert((long long)e);

        long long cur = mass;
        while(!data.empty()){
            multiset<long long, greater<long long>>::iterator iter = data.lower_bound(cur);
            if(iter == data.end()) return false;

            cur += *iter;
            data.erase(iter);
        }
        return true;
    }
};


int main() {

    return 0;
}
