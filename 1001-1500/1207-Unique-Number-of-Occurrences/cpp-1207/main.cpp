/// Source : https://leetcode.com/problems/unique-number-of-occurrences/
/// Author : liuyubobobo
/// Time   : 2019-09-28

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Using HashMap
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

        unordered_map<int, int> freq;
        for(int e: arr) freq[e] ++;

        unordered_map<int, int> res;
        for(const pair<int, int>& p: freq)
            if(res.count(p.second)) return false;
            else res[p.second] ++;
        return true;
    }
};


int main() {

    return 0;
}