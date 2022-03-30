/// Source : https://leetcode.com/problems/longest-increasing-subsequence/description/
/// Author : liuyubobobo
/// Time   : 2017-11-18
/// Updated: 2022-03-30

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O((right-left+1) * log(right))
/// Space Complexity: O(1)
class Solution {

public:
    vector<int> selfDividingNumbers(int left, int right) {

        vector<int> res;
        for(int i = left ; i <= right ; i ++)
            if(is_self_dividing(i))
                res.push_back(i);
        return res;
    }

private:
    bool is_self_dividing(int num){
        int t = num;
        while(t){
            int x = t % 10;
            t /= 10;
            if(x == 0 || num % x != 0)
                return false;
        }
        return true;
    }
};


void print_vec(const vector<int>& vec){
    for(int e: vec)
        cout << e << ' ';
    cout << endl;
}

int main() {

    print_vec(Solution().selfDividingNumbers(1, 22));

    return 0;
}