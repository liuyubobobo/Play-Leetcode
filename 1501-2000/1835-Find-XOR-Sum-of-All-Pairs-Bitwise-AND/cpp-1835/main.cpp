/// Source : https://leetcode.com/problems/find-xor-sum-of-all-pairs-bitwise-and/
/// Author : liuyubobobo
/// Time   : 2021-04-17

#include <iostream>
#include <vector>

using namespace std;


/// Bit to bit process
/// Time Complexity: O(|arr1| + |arr2|)
/// Space Complexity: O(1)
class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {

        vector<int> f1(31, 0), f2(31, 0);
        for(int e: arr1) process(e, f1);
        for(int e: arr2) process(e, f2);

        int res = 0;
        for(int i = 30; i >= 0; i --){
            long long one = (long long)f1[i] * f2[i];
            int x = one % 2ll;
            res = res * 2 + x;
        }
        return res;
    }

private:
    void process(int num, vector<int>& f){
        for(int i = 0; i < 31; i ++)
            f[i] += (num & 1), num >>= 1;
    }
};


int main() {

    vector<int> arr11 = {1, 2, 3}, arr12 = {6, 5};
    cout << Solution().getXORSum(arr11, arr12) << endl;
    // 0

    vector<int> arr21 = {12}, arr22 = {4};
    cout << Solution().getXORSum(arr21, arr22) << endl;
    // 4

    return 0;
}
