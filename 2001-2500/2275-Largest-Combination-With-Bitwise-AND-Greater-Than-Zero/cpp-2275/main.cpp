/// Source : https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/
/// Author : liuyubobobo
/// Time   : 2022-05-15

#include <iostream>
#include <vector>

using namespace std;


/// Bitwise
/// Time Complexity: O(nlogn(MAX_E))
/// Space Complexity: O(1)
class Solution {
public:
    int largestCombination(vector<int>& candidates) {

        vector<int> f(31, 0);
        for(int e: candidates) calc(f, e);

        return *max_element(f.begin(), f.end());
    }

private:
    void calc(vector<int>& f, int x){

        int p = 0;
        while(x){
            if(x & 1) f[p] ++;
            x >>= 1, p ++;
        }
    }
};


int main() {

    vector<int> candidates1 = {16,17,71,62,12,24,14};
    cout << Solution().largestCombination(candidates1) << '\n';
    // 4

    vector<int> candidates2 = {8, 8};
    cout << Solution().largestCombination(candidates2) << '\n';
    // 2

    vector<int> candidates3 = {33,93,31,99,74,37,3,4,2,94,77,10,75,54,24,95,65,100,41,82,35,65,38,49,85,72,67,21,20,31};
    cout << Solution().largestCombination(candidates3) << '\n';
    // 18

    return 0;
}
