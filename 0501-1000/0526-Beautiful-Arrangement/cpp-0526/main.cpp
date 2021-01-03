/// Source : https://leetcode.com/problems/beautiful-arrangement/
/// Author : liuyubobobo
/// Time   : 2020-01-03

#include <iostream>
#include <vector>

using namespace std;


/// Backtrack
/// Time Complexity: O(n^n)
/// Space Complexity: O(n)
class Solution {
public:
    int countArrangement(int n) {

        vector<bool> used(n + 1, false);
        return dfs(n, 1, used);
    }

private:
    int dfs(int n, int index, vector<bool>& used){

        if(index == n + 1) return 1;

        int res = 0;
        for(int num = 1; num <= n; num ++)
            if(!used[num] && (num % index == 0 || index % num == 0)){
                used[num] = true;
                res += dfs(n, index + 1, used);
                used[num] = false;
            }
        return res;
    }
};


int main() {

    cout << Solution().countArrangement(2) << endl;
    // 2

    return 0;
}
