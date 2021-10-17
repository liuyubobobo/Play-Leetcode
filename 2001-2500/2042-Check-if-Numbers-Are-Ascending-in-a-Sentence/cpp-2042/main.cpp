/// Source : https://leetcode.com/problems/check-if-numbers-are-ascending-in-a-sentence/
/// Author : liuyubobobo
/// Time   : 2021-10-16

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(|s|)
/// Space Complexity: O(|s|)
class Solution {
public:
    bool areNumbersAscending(string s) {

        vector<int> nums;
        for(int i = 0; i < s.size(); i ++)
            if(isdigit(s[i])){
                int j = i;
                for(; j < s.size(); j ++)
                    if(s[j] == ' ') break;
                nums.push_back(atoi(s.substr(i, j - i).c_str()));
                i = j;
            }

//        for(int e: nums) cout << e << ' '; cout << endl;

        for(int i = 1; i < nums.size(); i ++)
            if(nums[i] <= nums[i - 1]) return false;
        return true;
    }
};


int main() {

    cout << Solution().areNumbersAscending("1 box has 3 blue 4 red 6 green and 12 yellow marbles") << endl;
    // 1

    cout << Solution().areNumbersAscending("hello world 5 x 5") << endl;
    // 0

    cout << Solution().areNumbersAscending("sunset is at 7 51 pm overnight lows will be in the low 50 and 60 s") << endl;
    // 0

    cout << Solution().areNumbersAscending("4 5 11 26") << endl;
    // 1

    return 0;
}
