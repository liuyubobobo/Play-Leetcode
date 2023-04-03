/// Source : https://leetcode.com/problems/form-smallest-number-from-two-digit-arrays/description/
/// Author : liuyubobobo
/// Time   : 2023-04-02

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Brute Force
/// Time Complexity: O(100)
/// Space Complexity: O(1)
class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {

        for(int i = 1; i < 100; i ++){
            int x = i, state = 0;
            while(x){
                int d = x % 10;
                if(find(nums1.begin(), nums1.end(),d) != nums1.end())
                    state |= 1;
                if(find(nums2.begin(), nums2.end(),d) != nums2.end())
                    state |= 2;
                x /= 10;
            }
            if(state == 3)
                return i;
        }
        return -1;
    }
};

int main() {

    return 0;
}
