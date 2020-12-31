/// Source : https://leetcode.com/problems/rotated-digits/description/
/// Author : liuyubobobo
/// Time   : 2018-02-24

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Brute Force
/// Time Complexity: O(NlogN)
/// Space Complexity: O(logN)
class Solution {

public:
    int rotatedDigits(int N) {

        int res = 0;
        for(int i = 1 ; i <= N ; i ++){
            vector<int> digits = get_digits(i);
            bool ok = true;
            for(int d: digits)
                if(d == 3 || d == 4 || d ==7){
                    ok = false;
                    break;
                }

            if(ok){
                rotate(digits);
                int num = get_num(digits);
                if(num != i)
                    res ++;
            }
        }
        return res;
    }

private:
    int get_num(const vector<int>& digits){
        int x = 0;
        for(int d: digits)
            x = x * 10 + d;
        return x;
    }
    void rotate(vector<int>& digits){

        for(int i = 0 ; i < digits.size() ; i ++)
            if(digits[i] == 2)
                digits[i] = 5;
            else if(digits[i] == 5)
                digits[i] = 2;
            else if(digits[i] == 6)
                digits[i] = 9;
            else if(digits[i] == 9)
                digits[i] = 6;
            else
                assert(digits[i] == 0 || digits[i] == 1 || digits[i] == 8);
    }

    vector<int> get_digits(int x){

        vector<int> res;
        while(x){
            res.push_back(x%10);
            x /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {

    cout << Solution().rotatedDigits(10) << endl;
    return 0;
}