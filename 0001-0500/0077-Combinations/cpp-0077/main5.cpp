/// Source : https://leetcode.com/problems/combinations/description/
/// Author : liuyubobobo
/// Time   : 2019-03-29

#include <iostream>
#include <vector>

using namespace std;


/// Get all the combinations in place
/// find the first j which nums[j] + 1 != nums[j + 1] and increase nums[j]
/// See here for details: https://leetcode.com/problems/combinations/solution/
///
/// Time Complexity: O(k * C(n, k))
/// Space Complexity: O(1)
class Solution {

public:
    vector<vector<int>> combine(int n, int k) {

        vector<vector<int>> res;

        vector<int> c;
        for(int i = 1; i <= k; i ++)
            c.push_back(i);
        c.push_back(n + 1);

        int j = 0;
        while(j < k){

            res.push_back(vector<int>(c.begin(), c.begin() + k));

            for(j = 0; j < k && c[j] + 1 == c[j + 1]; j ++)
                c[j] = j + 1;

            c[j] ++;
        }
        return res;
    }
};


void print_vec(const vector<int>& vec){

    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    vector<vector<int>> res = Solution().combine(4,3);
    for( int i = 0 ; i < res.size() ; i ++ )
        print_vec(res[i]);
    return 0;
}