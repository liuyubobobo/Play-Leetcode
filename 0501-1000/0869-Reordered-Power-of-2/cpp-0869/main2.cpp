/// Source : https://leetcode.com/problems/reordered-power-of-2/description/
/// Author : liuyubobobo
/// Time   : 2018-07-14

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/// Permutation all possibility and check
/// Generate permutation by myself and skip the first zero case quickly
///
/// Time Complexity: O((logN)! * logN)
/// Space Complexity: O(logN)
class Solution {
public:
    bool reorderedPowerOf2(int N) {

        vector<int> digits = getDigits(N);
        return generatePermutation(digits, 0);
    }

private:
    bool generatePermutation(vector<int>& digits, int index){

        if(index == digits.size())
            return isPower2(digits);

        for(int i = index ; i < digits.size() ; i ++)
            if(index || digits[i]){
                swap(digits[index], digits[i]);
                if(generatePermutation(digits, index + 1))
                    return true;
                swap(digits[index], digits[i]);
            }
        return false;
    }

    bool isPower2(const vector<int>& digits){

        int num = 0;
        for(int digit: digits)
            num = num * 10 + digit;
        return isPower2(num);
    }

    bool isPower2(int x){
        for(int i = 0 ; i <= 30 ; i ++)
            if(x == (1<<i))
                return true;
        return false;
    }

    vector<int> getDigits(int N){
        vector<int> res;
        while(N){
            res.push_back(N % 10);
            N /= 10;
        }
        return res;
    }
};


void print_bool(bool res){
    cout << (res ? "True" : "False") << endl;
}

int main() {

    print_bool(Solution().reorderedPowerOf2(1));
    print_bool(Solution().reorderedPowerOf2(10));
    print_bool(Solution().reorderedPowerOf2(16));
    print_bool(Solution().reorderedPowerOf2(24));
    print_bool(Solution().reorderedPowerOf2(46));

    return 0;
}