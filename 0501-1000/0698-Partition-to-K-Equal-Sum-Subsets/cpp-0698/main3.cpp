/// Source : https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/
/// Author : liuyubobobo
/// Time   : 2017-10-19

#include <iostream>
#include <vector>
#include <numeric>
#include <cassert>

using namespace std;

/// Dynamic Programming
///
/// Time Complexity: O((2^len(nums)) * len(nums))
/// Space Complexity: O((2^len(nums)))
class Solution {

private:
    int subsum = 0;
    bool visited[1<<16];
    int todo[1<<16];

public:

    bool canPartitionKSubsets(vector<int>& nums, int k) {

        int sum = accumulate(nums.begin(), nums.end(), 0);
        // cout << "sum = " << sum << endl;
        if(sum % k != 0)
            return false;

        subsum = sum / k;
        // cout << subsum << endl;

        sort(nums.begin(), nums.end());
        if(nums[nums.size()-1] > subsum)
            return false;

        int len = (1<<nums.size());
        // cout << len << endl;

        for(int i = 0 ; i < len ; i ++){
            visited[i] = false;
            todo[i] = subsum;
        }

        visited[0] = true;
        for(int i = 0 ; i < len ; i ++){

            // i should be visited here
            // if !visited[i], means the state of i can not construct to a solution!
            if(!visited[i])
                continue;

            for(int j = 0 ; j < nums.size() ; j ++)
                if((i & (1<<j)) == 0){
                    int newState = (i | (1<<j));
                    if(!visited[newState] && todo[i] >= nums[j]){
                        todo[newState] = todo[i] - nums[j];
                        if(todo[newState] == 0)
                            todo[newState] = subsum;
                        visited[newState] = true;
                    }
//                    else if(visited[newState]){
//                        assert(todo[i] >= nums[j]);
//                        assert(todo[newState] == todo[i] - nums[j] ||
//                               (todo[i] - nums[j] == 0 && todo[newState] == subsum));
//                    }
                }
        }

        int lastState = (1<<nums.size())-1;
        return visited[lastState] && todo[lastState] == subsum;
    }
};

int main() {

    int arr0[] = {2, 2, 3, 3, 3, 3};
    vector<int> vec0(arr0, arr0 + sizeof(arr0) / sizeof(int));
    int k0 = 4;
    if(Solution().canPartitionKSubsets(vec0, k0))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    int arr1[] = {4, 3, 2, 3, 5, 2, 1};
    vector<int> vec1(arr1, arr1 + sizeof(arr1) / sizeof(int));
    int k1 = 4;
    if(Solution().canPartitionKSubsets(vec1, k1))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    int arr2[] = {71,85,99,110,27,47,8,83,72,24,52,17,99};
    vector<int> vec2(arr2, arr2 + sizeof(arr2) / sizeof(int));
    int k2 = 13;
    if(Solution().canPartitionKSubsets(vec2, k2))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    int arr3[] = {39, 73, 52, 3, 9370};
    vector<int> vec3(arr3, arr3 + sizeof(arr3) / sizeof(int));
    int k3 = 3;
    if(Solution().canPartitionKSubsets(vec3, k3))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    int arr4[] = {2,2,2,2,3,4,5};
    vector<int> vec4(arr4, arr4 + sizeof(arr4) / sizeof(int));
    int k4 = 4;
    if(Solution().canPartitionKSubsets(vec4, k4))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}