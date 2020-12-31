/// Source : https://leetcode.com/problems/count-number-of-teams/
/// Author : liuyubobobo
/// Time   : 2020-03-29

#include <iostream>
#include <vector>

using namespace std;


/// Presum-like
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    int numTeams(vector<int>& rating) {

        int n = rating.size();

        vector<int> right(n, 0), left(n, 0);
        for(int i = 0; i < n; i ++)
            for(int j = i + 1; j < n; j ++)
                right[i] += (rating[j] > rating[i]);
//        for(int e: greater) cout << e << " "; cout << endl;

        for(int i = n - 1; i >= 0; i --)
            for(int j = i - 1; j >= 0; j --)
                left[i] += (rating[j] > rating[i]);
//        for(int e: less) cout << e << " "; cout << endl;

        int res = 0;
        for(int i = 0; i < n; i ++)
            for(int j = i + 1; j < n; j ++)
                if(rating[j] > rating[i]) res += right[j];

        for(int i = n - 1; i >= 0; i --)
            for(int j = i - 1; j >= 0; j --)
                if(rating[j] > rating[i]) res += left[j];

        return res;
    }
};


int main() {

    vector<int> rating1 = {2, 5, 3, 4, 1};
    cout << Solution().numTeams(rating1) << endl;

    return 0;
}
