/// Source : https://leetcode.com/problems/maximum-compatibility-score-sum/
/// Author : liuyubobobo
/// Time   : 2021-07-24

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(m^2 + m! * n)
/// Space Complexity: O(m^2)
class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {

        int n = students[0].size(), m = students.size();

        vector<vector<int>> scores(m, vector<int>(m));
        for(int i = 0; i < m; i ++)
            for(int j = 0; j < m; j ++)
                scores[i][j] = get_score(students[i], mentors[j]);

        vector<int> p(m, 0);
        for(int i = 1; i < m; i ++) p[i] = i;

        int max_res = 0;
        do{
            int tres = 0;
            for(int i = 0; i < m; i ++)
                tres += scores[p[i]][i];
            max_res = max(max_res, tres);
        }while(next_permutation(p.begin(), p.end()));
        return max_res;
    }

private:
    int get_score(const vector<int>& a, const vector<int>& b){
        int res = 0;
        for(int i = 0; i < a.size(); i ++)
            res += (a[i] == b[i]);
        return res;
    }
};


int main() {

    vector<vector<int>> students1 = {{1,1,0},{1,0,1},{0,0,1}};
    vector<vector<int>> mentors1 = {{1,0,0},{0,0,1},{1,1,0}};
    cout << Solution().maxCompatibilitySum(students1, mentors1) << endl;
    // 8

    vector<vector<int>> students2 = {{0,0},{0,0},{0,0}};
    vector<vector<int>> mentors2 = {{1,1},{1,1},{1,1}};
    cout << Solution().maxCompatibilitySum(students2, mentors2) << endl;
    // 0

    return 0;
}
