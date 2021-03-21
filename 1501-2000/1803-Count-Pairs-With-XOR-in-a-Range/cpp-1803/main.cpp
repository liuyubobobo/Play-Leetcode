/// Source : https://leetcode.com/problems/count-pairs-with-xor-in-a-range/
/// Author : liuyubobobo
/// Time   : 2021-03-21

#include <iostream>
#include <vector>

using namespace std;


/// Trie
/// Time Complexity: O(nlog(maxnum))
/// Space Complexity: O(nlog(maxnum))
class Solution {

public:
    int countPairs(vector<int>& nums, int low, int high) {

        int maxv = *max_element(nums.begin(), nums.end());
        maxv = max(maxv, high);
        int B = 0;
        while(maxv) B ++, maxv >>= 1;

        vector<pair<int, pair<int, int>>> trie(1, {0, {-1, -1}});
        int res = 0;
        vector<int> highb = get_binary(high, B), lowb = get_binary(low - 1, B);
        for(int num: nums){

            vector<int> v = get_binary(num, B);
            int a = solve(trie, 0, v, 0, highb);
            int b = solve(trie, 0, v, 0, lowb);
            res += a - b;

            add(trie, 0, v, 0);
        }

        return res;
    }

private:
    int solve(const vector<pair<int, pair<int, int>>>& trie, int root,
              const vector<int>& num, int index, const vector<int>& k){

        if(root >= trie.size()) return 0;

        if(index == k.size())
            return trie[root].first;

        int left = trie[root].second.first, right = trie[root].second.second;

        if(num[index] == 0 && k[index] == 0)
            return solve(trie, left, num, index + 1, k);

        if(num[index] == 0 && k[index] == 1)
            return (left == - 1 ? 0 : trie[left].first) + solve(trie, right, num, index + 1, k);

        if(num[index] == 1 && k[index] == 0)
            return solve(trie, right, num, index + 1, k);

        return (right == -1 ? 0 : trie[right].first) + solve(trie, left, num, index + 1, k);
    }

    void add(vector<pair<int, pair<int, int>>>& trie, int root, const vector<int>& num, int index){

        if(index == num.size()){
            trie[root].first += 1;
            return;
        }

        int left = trie[root].second.first, right = trie[root].second.second;
        if(num[index]){
            if(right == -1){
                trie.push_back({0, {-1, -1}});
                right = trie.size() - 1;
                trie[root].second.second = right;
            }
            add(trie, right, num, index + 1);
        }
        else{
            if(left == -1){
                trie.push_back({0, {-1, -1}});
                left = trie.size() - 1;
                trie[root].second.first = left;
            }
            add(trie, left, num, index + 1);
        }

        trie[root].first = (left == -1 ? 0 : trie[left].first) + (right == -1 ? 0 : trie[right].first);
    }

    vector<int> get_binary(int num, int B){

        vector<int> res(B);
        for(int i = 0; i < B; i ++)
            res[i] = (num & 1), num >>= 1;
        reverse(res.begin(), res.end());
        return res;
    }
};


int main() {

    vector<int> nums1 = {1, 4, 2, 7};
    cout << Solution().countPairs(nums1, 2, 6) << endl;
    // 6

    vector<int> nums2 = {9,8,4,2,1};
    cout << Solution().countPairs(nums2, 5, 14) << endl;
    // 8

    vector<int> nums3 = {7881,760,709,2937,1245,720,5187,6361,3793,141,7238};
    cout << Solution().countPairs(nums3, 1492, 3832) << endl;
    // 16

    vector<int> nums4 = {3856,3174,2182,7497,6155,4589,3581,4548,3982,2508};
    cout << Solution().countPairs(nums4, 6903, 6946) << endl;
    // 0

    return 0;
}
