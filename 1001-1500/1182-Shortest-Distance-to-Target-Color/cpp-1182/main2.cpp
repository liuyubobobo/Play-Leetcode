/// Source : https://leetcode.com/problems/shortest-distance-to-target-color/
/// Author : liuyubobobo
/// Time   : 2019-09-07

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(n + q)
/// SpaceComplexity: O(n)
class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {

        int n = colors.size();

        vector<vector<int>> forward(4, vector<int>(n, -1));
        for(int color = 1; color <= 3; color ++)
            for(int i = 0; i < n; i ++)
                if(colors[i] == color) forward[color][i] = 0;
                else if(i - 1 >= 0 && forward[color][i - 1] != -1)
                    forward[color][i] = forward[color][i - 1] + 1;

        vector<vector<int>> backward(4, vector<int>(n, -1));
        for(int color = 1; color <= 3; color ++)
            for(int i = n - 1; i >= 0; i --)
                if(colors[i] == color) backward[color][i] = 0;
                else if(i + 1 < n && backward[color][i + 1] != -1)
                    backward[color][i] = backward[color][i + 1] + 1;

        vector<int> res;
        for(const vector<int>& q: queries){
            int a = forward[q[1]][q[0]];
            int b = backward[q[1]][q[0]];
            if(a == -1) res.push_back(b);
            else if(b == -1) res.push_back(a);
            else res.push_back(min(a, b));
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