/// Source : https://leetcode.com/problems/minimum-increment-to-make-array-unique/
/// Author : liuyubobobo
/// Time   : 2018-11-25

#include <iostream>
#include <vector>

using namespace std;


/// Using an array hashtable to record duplicate elements
/// Time Complexity: O(max number)
/// Space Complexity: O(max number)
class Solution {

private:
    const int MAX_NUM = 40000;

public:
    int minIncrementForUnique(vector<int>& A) {

        vector<int> freq(MAX_NUM + 1, 0);
        for(int a: A)
            freq[a] ++;

        int res = 0, left = 0;
        for(int i = 0; i <= MAX_NUM; i ++)
            if(freq[i] >= 2){
                res -= (freq[i] - 1) * i;
                left += freq[i] - 1;
            }
            else if(freq[i] == 0 && left){
                res += i;
                left --;
            }

        for(int i = 1; i <= left; i ++)
            res += (MAX_NUM + i);
        return res;
    }
};


int main() {

    return 0;
}