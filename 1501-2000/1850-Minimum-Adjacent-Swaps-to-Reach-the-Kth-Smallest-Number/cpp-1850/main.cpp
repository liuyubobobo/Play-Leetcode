/// Source : https://leetcode.com/problems/minimum-adjacent-swaps-to-reach-the-kth-smallest-number/
/// Author : liuyubobobo
/// Time   : 2021-05-01

#include <iostream>
#include <algorithm>

using namespace std;


/// next_permutation + Greedy
/// Time Complexity: O(k * |num| + |num|^2)
/// Space Complexity: O(|num|)
class Solution {
public:
    int getMinSwaps(string num, int k) {

        string onum = num;
        for(int i = 0; i < k; i ++)
            next_permutation(num.begin(), num.end());
//        cout << num << endl;
        return solve(onum, num);
    }

private:
    int solve(string& s, const string& t){

        int res = 0;
        for(int i = 0; i < t.size(); i ++){

            int j = i;
            for(; j < s.size(); j ++)
                if(s[j] == t[i]) break;

            for(; j > i; j --){
                swap(s[j], s[j - 1]);
                res ++;
            }
        }
        return res;
    }
};


int main() {

    cout << Solution().getMinSwaps("5489355142", 4) << endl;
    // 2

    cout << Solution().getMinSwaps("11112", 4) << endl;
    // 4

    cout << Solution().getMinSwaps("00123", 1) << endl;
    // 1

    return 0;
}
