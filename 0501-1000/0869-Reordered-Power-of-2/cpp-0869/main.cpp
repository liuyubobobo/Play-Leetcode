/// Source : https://leetcode.com/problems/reordered-power-of-2/description/
/// Author : liuyubobobo
/// Time   : 2018-07-14

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


/// Permutation all possibility and check
/// Using next_permutation:)
///
/// Time Complexity: O((logN)! * logN)
/// Space Complexity: O(logN)
class Solution {
public:
    bool reorderedPowerOf2(int N) {

        vector<int> digits = getDigits(N);
        sort(digits.begin(), digits.end());
        do{
            if(digits[0] == 0)
                continue;
            if(isPower2(digits))
                return true;
        }while(next_permutation(digits.begin(), digits.end()));

        return false;
    }

private:
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