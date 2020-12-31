/// Source : https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/description/
/// Author : liuyubobobo
/// Time   : 2018-09-29

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/// Brute Force
/// but only iterate from 2 to the minFreq
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> freq;
        for(int x: deck)
            freq[x] ++;

        int minFreq = INT_MAX;
        for(const pair<int, int>& p: freq)
            minFreq = min(minFreq, p.second);

        for(int i = 2; i <= minFreq; i ++)
            if(minFreq % i == 0){
                bool ok = true;
                for(const pair<int, int>& p: freq)
                    if(p.second % i){
                        ok = false;
                        break;
                    }
                if(ok)
                    return true;
            }

        return false;
    }
};


int main() {

    vector<int> vec = {1,1,1,1,2,2,2,2,2,2};
    cout << Solution().hasGroupsSizeX(vec) << endl;
    // true

    return 0;
}