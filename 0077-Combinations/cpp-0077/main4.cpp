/// Source : https://leetcode.com/problems/combinations/description/
/// Author : liuyubobobo
/// Time   : 2019-03-29

#include <iostream>
#include <vector>

using namespace std;


/// Get all the combinations in place
/// Find the first non-saturated element and increase it
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
//        Solution::print_vec(c);
        res.push_back(c);

        while(c[0] != n - k + 1){

            if(c.back() != n) c.back() ++;
            else{
                int i;
                for(i = k - 1; i >= 0; i --)
                    if(c[i] != i + n - k + 1){
                        c[i] ++;
                        for(int j = i + 1; j < k; j ++)
                            c[j] = c[j - 1] + 1;
                        break;
                    }
            }
//            Solution::print_vec(c);
            res.push_back(vector<int>(c.begin(), c.begin() + k));
        }
        return res;
    }

    static void print_vec(const vector<int>& vec){

        for(int e: vec)
            cout << e << " ";
        cout << endl;
    }
};


int main() {

    vector<vector<int>> res = Solution().combine(4,3);
    for( int i = 0 ; i < res.size() ; i ++ )
        Solution::print_vec(res[i]);

    return 0;
}