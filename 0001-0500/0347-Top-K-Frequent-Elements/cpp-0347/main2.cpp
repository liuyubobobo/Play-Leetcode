/// Source : https://leetcode.com/problems/top-k-frequent-elements/description/
/// Author : liuyubobobo
/// Time   : 2017-11-17

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cassert>

using namespace std;

/// Sorting
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {

private:
    unordered_map<int,int> freq;

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        assert(k > 0);

        freq.clear();
        for(int i = 0 ; i < nums.size() ; i ++ )
            freq[nums[i]] ++;

        assert(k <= freq.size());

        vector<int> res;
        for(pair<int, int> p: freq)
            res.push_back(p.first);

        sort(res.begin(), res.end(), [this](int a, int b){
            if(this->freq[a] != this->freq[b])
               return this->freq[a] > this->freq[b];
            return a < b;
        });

        return vector<int>(res.begin(), res.begin() + k);
    }
};


void print_vec(const vector<int>& vec){
    for(int e: vec) cout << e << " "; cout << endl;
}

int main() {

    vector<int> nums = {1, 1, 1, 2, 2, 3};
    print_vec(Solution().topKFrequent(nums, 2));

    return 0;
}