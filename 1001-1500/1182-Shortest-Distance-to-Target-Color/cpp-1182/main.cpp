/// Source : https://leetcode.com/problems/shortest-distance-to-target-color/
/// Author : liuyubobobo
/// Time   : 2019-09-07

#include <iostream>
#include <vector>

using namespace std;


/// Preprocess and Binary Search
/// Time Complexity: O(nlogn + q)
/// SpaceComplexity: O(n)
class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {

        int n = colors.size();

        vector<vector<int>> forward = get(colors);
        reverse(colors.begin(), colors.end());
        vector<vector<int>> backward = get(colors);

        vector<int> res;
        for(const vector<int>& q: queries){
            int a = forward[q[1]][q[0]];
            int b = backward[q[1]][n - 1 - q[0]];
            if(a == -1) res.push_back(b);
            else if(b == -1) res.push_back(a);
            else res.push_back(min(a, b));
        }
        return res;
    }

private:
    vector<vector<int>> get(const vector<int>& colors){

        int n = colors.size();

        vector<vector<int>> pos(4);
        for(int i = 0; i < n; i ++)
            pos[colors[i]].push_back(i);

        vector<vector<int>> res(4, vector<int>(n, -1));
        for(int i = 0; i < n; i ++)
            for(int color = 1; color <= 3; color ++){
                vector<int>::iterator iter = lower_bound(pos[color].begin(), pos[color].end(), i);
                if(iter != pos[color].end())
                    res[color][i] = *iter - i;
            }
        return res;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << " "; cout << endl;
}

int main() {

    vector<int> colors1 = {1,1,2,1,3,2,2,3,3};
    vector<vector<int>> queries1 = {{1, 3}, {2, 2}, {6, 1}};
    print_vec(Solution().shortestDistanceColor(colors1, queries1));
    // 3 0 3

    return 0;
}