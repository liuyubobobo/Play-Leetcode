/// Source : https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/
/// Author : liuyubobobo
/// Time   : 2020-06-13

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Using HashMap + Sorting and greedy
/// Time Complexity: O(nlogn)
/// Space Complexity: O(nlogn)
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {

        unordered_map<int, int> freq;
        for(int e: arr) freq[e] ++;

        vector<int> v;
        for(const pair<int, int>& p: freq) v.push_back(p.second);
        sort(v.begin(), v.end(), greater<int>());

        while(v.size() && k >= v.back())
            k -= v.back(), v.pop_back();
        return v.size();
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
