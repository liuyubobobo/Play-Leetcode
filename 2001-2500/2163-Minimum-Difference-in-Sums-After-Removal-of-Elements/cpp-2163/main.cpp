/// Source : https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/
/// Author : liuyubobobo
/// Time   : 2022-02-06

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <cassert>

using namespace std;


/// Custom define two structures
/// Time Complexity: O(nlogn)
/// Space Compelxity: O(n)
class MinNSum{

private:
    priority_queue<int> pq;
    long long min_sum = 0;
    int n;

public:
    MinNSum(const vector<int>& nums) : n(nums.size()){
        for(int e: nums){
            pq.push(e);
            min_sum += e;
        }
    }

    long long get_min_sum(){
        return min_sum;
    }

    void add(int e){
        pq.push(e);
        min_sum += e;

        int maxv = pq.top();
        pq.pop();
        min_sum -= maxv;

//        assert(pq.size() == n);
    }
};

class MaxNSum{

private:
    multiset<int> min_set, max_set;
    long long max_sum = 0;
    int n;

public:
    MaxNSum(vector<int> nums){
        int n2 = nums.size();
        n = n2 / 2;

        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i ++) min_set.insert(nums[i]);
        for(int i = n; i < n2; i ++){
            max_set.insert(nums[i]);
            max_sum += nums[i];
        }
    }

    long long get_max_sum(){
        return max_sum;
    }

    void remove(int e){
        auto iter = min_set.find(e);
        if(iter != min_set.end()){
            min_set.erase(iter);
            return;
        }

//        assert(max_set.count(e));
        max_set.erase(max_set.find(e));
        max_sum -= e;

//        assert(!min_set.empty());
        int maxv = *min_set.rbegin();
        iter = min_set.end();
        iter --;
        min_set.erase(iter);
        max_set.insert(maxv);
        max_sum += maxv;
    }
};

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {

        int n3 = nums.size(), n = n3 / 3;

        vector<int> first(nums.begin(), nums.begin() + n);
        vector<int> second(nums.begin() + n, nums.end());

        MinNSum minNSum(first);
        MaxNSum maxNSum(second);
        long long res = minNSum.get_min_sum() - maxNSum.get_max_sum();
        for(int i = n ; i < n + n; i ++){
            minNSum.add(nums[i]);
            maxNSum.remove(nums[i]);
            res = min(res, minNSum.get_min_sum() - maxNSum.get_max_sum());
        }
        return res;
    }
};


int main() {

    vector<int> nums1 = {3, 1, 2};
    cout << Solution().minimumDifference(nums1) << endl;
    // -1

    vector<int> nums2 = {7, 9, 5, 8, 1, 3};
    cout << Solution().minimumDifference(nums2) << endl;
    // 1

    return 0;
}
