/// Source : https://leetcode.com/problems/find-the-duplicate-number/description/
/// Author : liuyubobobo
/// Time   : 2017-11-03

#include <iostream>
#include <vector>
#include <cassert>
#include <random>
#include <chrono>
#include <algorithm>

using namespace std;

/// Two Pointers
/// Same algorithm as 142 Linked List Cycle II :)
///
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        assert(nums.size() > 1);

        int slow = 0;
        int fast = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        int p = 0;
        int entrance = nums[fast];
        while(p != entrance){
            p = nums[p];
            entrance = nums[entrance];
        }

        return p;
    }
};

int main() {

    int n = 10000;
    vector<int> vec(n+1, 0);
    for(int i = 0 ; i < n ; i ++)
        vec[i] = i+1;
    vec[n] = rand() % n + 1;
    cout << "The repeat number is " << vec[n] << endl;

    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(vec.begin(), vec.end(), std::default_random_engine(seed));

    cout << Solution().findDuplicate(vec) << endl;

    return 0;
}