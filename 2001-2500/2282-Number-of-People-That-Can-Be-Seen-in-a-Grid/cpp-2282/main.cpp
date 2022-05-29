#include <iostream>
#include <vector>

using namespace std;


class Solution {

public:
    vector<vector<int>> seePeople(vector<vector<int>>& heights) {

        int R = heights.size(), C = heights[0].size();

        vector<vector<int>> res1(R, vector<int>(C, 0));
        for(int i = 0; i < R; i ++){
            vector<int> stack;
            for(int j = 0; j < C; j ++){
                while(!stack.empty()){
                    res1[i][stack.back()] ++;
                    if(heights[i][j] > heights[i][stack.back()]) stack.pop_back();
                    else break;
                }
                stack.push_back(j);
            }
        }

        vector<vector<int>> res2(R, vector<int>(C, 0));
        for(int j = 0; j < C; j ++){
            vector<int> stack;
            for(int i = 0; i < R; i ++){
                while(!stack.empty()){
                    res2[stack.back()][j] ++;
                    if(heights[i][j] > heights[stack.back()][j]) stack.pop_back();
                    else break;
                }
                stack.push_back(i);
            }
        }

        vector<vector<int>> res(R, vector<int>(C, 0));
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++) res[i][j] = res1[i][j] + res2[i][j];
        return res;
    }
};


void print_matrix(const vector<vector<int>>& matrix){
    for(const vector<int>& row: matrix){
        for(int e: row) cout << e << ' ';
        cout << '\n';
    }
}

int main() {

    vector<vector<int>> height1 = {{3, 1, 4, 2, 5}};
    print_matrix(Solution().seePeople(height1));
    // 2 1 2 1 0

    vector<vector<int>> height2 = {{5, 1}, {3, 1}, {4, 1}};
    print_matrix(Solution().seePeople(height2));
    // 3 1
    // 2 1
    // 1 0

    vector<vector<int>> height3 = {{4, 2, 1, 1, 3}};
    print_matrix(Solution().seePeople(height3));
    // 2 2 1 1 0

    return 0;
}
