/// Source : https://leetcode.com/problems/split-array-into-consecutive-subsequences/
/// Author : liuyubobobo
/// Time   : 2020-12-03

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;


/// HashTable + Priority Queue
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    bool isPossible(vector<int>& nums) {

        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> table;
        for(int e: nums)
            if(!table.count(e - 1)) table[e].push(1);
            else{
                int len = table[e - 1].top();
                table[e - 1].pop();
                if(table[e - 1].empty()) table.erase(e - 1);
                table[e].push(len + 1);
            }

        for(const pair<int, priority_queue<int, vector<int>, greater<int>>>& p: table){
            priority_queue<int, vector<int>, greater<int>> pq = p.second;
            while(!pq.empty()){
                if(pq.top() < 3) return false;
                pq.pop();
            }
        }
        return true;
    }
};


int main() {

    vector<int> nums1 = {1, 2, 3, 3, 4, 5};
    cout << Solution().isPossible(nums1) << endl;
    // 1

    vector<int> nums2 = {1,2,3,3,4,4,5,5};
    cout << Solution().isPossible(nums2) << endl;
    // 1

    vector<int> nums3 = {1,2,3,4,4,5};
    cout << Solution().isPossible(nums3) << endl;
    // 0

    return 0;
}
