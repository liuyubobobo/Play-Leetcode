/// Source : https://leetcode.com/problems/longest-increasing-subsequence/description/
/// Author : liuyubobobo
/// Time   : 2017-11-18

#include <iostream>
#include <vector>

using namespace std;

/// Ad-Hoc
/// Time Complexity: O((right-left+1)*log10(right))
/// Space Complexity: O(1)
class Solution {

public:
    vector<int> selfDividingNumbers(int left, int right) {

        vector<int> res;
        for(int i = left ; i <= right ; i ++)
            if(selfDividing(i))
                res.push_back(i);
        return res;
    }

private:
    bool selfDividing(int num){
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


void printVec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    printVec(Solution().selfDividingNumbers(1, 22));

    return 0;
}