/// Source : https://leetcode.com/problems/top-k-frequent-elements/description/
/// Author : liuyubobobo
/// Time   : 2017-11-17

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <cassert>

using namespace std;

/// Using Tree Set
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        assert(k > 0);

        unordered_map<int, int> freq;
        for(int num: nums)
            freq[num] ++;

//        cout << "freq:" << endl;
//        for(pair<int, int>p: freq)
//            cout << "v: " << p.first << " f: " << p.second << endl;
//        cout << endl;

        assert(k <= freq.size());

        set<pair<int, int>, greater<pair<int, int>>> record;
        for(pair<int, int> p: freq)
            record.insert(make_pair(p.second, p.first));

        vector<int> res;
        for(int i = 0 ; i < k ; i ++){
            set<pair<int, int>>::iterator iter = record.begin();
            advance(iter, i);
            assert(iter != record.end());
            res.push_back(iter->second);
        }

        return res;
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