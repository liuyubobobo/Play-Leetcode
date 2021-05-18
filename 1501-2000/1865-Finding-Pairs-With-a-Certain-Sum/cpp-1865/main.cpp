/// Source : https://leetcode.com/problems/finding-pairs-with-a-certain-sum/
/// Author : liuyubobobo
/// Time   : 2021-05-15

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Using HashMap
/// Time Complexity: init: O(|nums1| + |nums2|)
///                  add: O(1)
///                  count: O(|nums1|)
/// Space Complexity: O(|nums1| + |nums2|)
class FindSumPairs {

private:
    vector<int> nums1, nums2;
    unordered_map<int, int> f;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) : nums1(nums1), nums2(nums2) {
        for(int e: nums2) f[e] ++;
    }

    void add(int index, int val) {

        int a = nums2[index];
        f[a] --;
        if(f[a] == 0) f.erase(a);
        f[a + val] ++;
        nums2[index] += val;
    }

    int count(int tot) {

        int res = 0;
        for(int e: nums1)
            if(f.find(tot - e) != f.end()) res += f[tot - e];
        return res;
    }
};


int main() {

    return 0;
}
