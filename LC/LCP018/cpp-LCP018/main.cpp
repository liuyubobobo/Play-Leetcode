/// Source : https://leetcode-cn.com/problems/2vYnGI/
/// Author : liuyubobobo
/// Time   : 2020-09-12

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Binary Search
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {

private:
    const int MOD = 1e9 + 7;
public:
    int breakfastNumber(vector<int>& staple, vector<int>& drinks, int x) {

        sort(staple.begin(), staple.end());
        sort(drinks.begin(), drinks.end());

        int res = 0;
        for(int e: staple){
            vector<int>::iterator iter = upper_bound(drinks.begin(), drinks.end(), x - e);
            res += iter - drinks.begin();
            res %= MOD;
        }
        return res;
    }
};


int main() {

    vector<int> staple1 = {10,20,5};
    vector<int> drinks1 = {5, 5, 2};
    cout << Solution().breakfastNumber(staple1, drinks1, 15) << endl;
    // 6

    vector<int> staple2 = {2, 1, 1};
    vector<int> drinks2 = {8,9,5,1};
    cout << Solution().breakfastNumber(staple2, drinks2, 9) << endl;
    // 8

    return 0;
}
