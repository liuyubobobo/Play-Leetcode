/// Source : https://leetcode.com/problems/separate-the-digits-in-an-array/
/// Author : liuyubobobo
/// Time   : 2023-02-04

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(nlog(MAX_NUM))
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {

        vector<int> res;
        for(int num: nums){
            vector<int> digits = get_digits(num);
            for(int e: digits) res.push_back(e);
        }
        return res;
    }

private:
    vector<int> get_digits(int x){
        vector<int> res;
        while(x) res.push_back(x % 10), x /= 10;
        if(res.empty()) res.push_back(0);
        reverse(res.begin(), res.end());
        return res;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
