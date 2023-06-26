/// Source : https://leetcode.com/problems/number-of-beautiful-pairs/description/
/// Author : liuyubobobo
/// Time   : 2023-06-25

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {

        int n = nums.size(), res = 0;
        for(int i = 0; i < n; i ++)
            for(int j = i + 1; j < n; j ++){
                int a = to_string(nums[i])[0] - '0';
                int b = to_string(nums[j]).back() - '0';
                res += gcd(a, b) == 1;
            }
        return res;
    }

private:
    template<typename T>
    T gcd(T a, T b){
        if(a < b) swap(a, b);
        while(b){
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }
};


int main() {

    return 0;
}
