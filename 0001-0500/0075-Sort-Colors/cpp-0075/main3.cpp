/// Source : https://leetcode.com/problems/sort-colors/description/
/// Author : liuyubobobo
/// Time   : 2021-08-08

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// Counting
// Time Complexity: O(n)
// Space Complexity: O(3)
class Solution {
public:
    void sortColors(vector<int> &nums) {

        const int MAX = 3;
        vector<int> count(MAX, 0);
        for(int i = 0 ; i < nums.size() ; i ++){
            assert(nums[i] >= 0 && nums[i] <= MAX);
            count[nums[i]] ++;
        }

        int index = 0;
        for(int i = 0 ; i < MAX ; i ++)
            for(int j = 0; j < count[i]; j ++)
                nums[index++] = i;
    }
};


void print_arr(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    vector<int> vec1 = {2, 2, 2, 1, 1, 0};
    Solution().sortColors(vec1);
    print_arr(vec1);

    vector<int> vec2 = {2};
    Solution().sortColors(vec2);
    print_arr(vec2);

    return 0;
}
