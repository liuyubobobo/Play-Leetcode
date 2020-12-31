/// Source : https://leetcode.com/problems/contains-duplicate-iii/description/
/// Author : liuyubobobo
/// Time   : 2017-11-15

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Based on Buckets
// each time, all we need to check is the bucket that x belongs to and its two adjacent buckets
//
// One thing worth mentioning is the difference from bucket sort –
// Each of our buckets contains at most one element at any time,
// because two elements in a bucket means "almost duplicate" and we can return early from the function.
// Therefore, a HashMap with an element associated with a bucket label is enough for our purpose.
//
// Time Complexity: O(n)
// Space Complexity: O(k)
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {

        if(t < 0)
            return false;

        unordered_map<long long, long long> buckets;
        long long w = (long long)t + (long long)1;
        for(int i = 0 ; i < nums.size() ; i ++){

            long long num = (long long)nums[i];
            long long id = getID(num, w);

            // check if bucket id is empty, each bucket may contain at most one element
            if(buckets.find(id) != buckets.end())
                return true;

            // check the neighbor buckets for almost duplicate
            if(buckets.find(id - 1) != buckets.end() &&
               buckets[id - 1] >= num - (long long)t)
                return true;

            if(buckets.find(id + 1) != buckets.end() &&
               buckets[id + 1] <= num + (long long)t)
                return true;

            // now bucket id is empty and no almost duplicate in neighbor buckets
            buckets[id] = num;

            if(buckets.size() == k + 1)
                buckets.erase(getID((long long)nums[i-k], w));
        }

        return false;
    }

private:
    // Get the ID of the bucket from element value x and bucket width w
    // Since `-3 / 5 = 0` and but we need `-3 / 5 = -1`.
    long long getID(long long x, long long w){
        return x < 0 ? (x + 1) / w - 1 : x / w;
    }
};


void printBool(bool b){
    cout << (b ? "True" : "False") << endl;
}

int main() {

    int nums[] = {-2147483648, -2147483647};
    vector<int> vec(nums, nums + sizeof(nums)/sizeof(int));
    int k = 3;
    int t = 3;

    printBool(Solution().containsNearbyAlmostDuplicate(vec, k, t));

    return 0;
}