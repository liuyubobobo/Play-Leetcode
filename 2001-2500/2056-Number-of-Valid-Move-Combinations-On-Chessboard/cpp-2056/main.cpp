/// Source : https://leetcode.com/problems/number-of-valid-move-combinations-on-chessboard/
/// Author : liuyubobobo
/// Time   : 2021-11-03

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Simulation
/// Time Compelxity: O(9^n * 7*n * n)
/// Space Complexity: O(n)
class Solution {

private:
    vector<vector<pair<int, int>>> dirs;

public:
    int countCombinations(vector<string>& pieces, vector<vector<int>>& positions) {

        dirs.assign(3, vector<pair<int, int>>());

        // rook
        dirs[0] = {{0, 0}, {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        // queen
        dirs[1] = {{0, 0}, {1, 0}, {-1, 0}, {0, 1}, {0, -1},
                   {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        // bishop
        dirs[2] = {{0, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

        int n = pieces.size();
        vector<int> p(n, 0);
        vector<pair<int, int>> pos(n);
        for(int i = 0; i < n; i ++){
            pos[i].first = positions[i][0] - 1;
            pos[i].second = positions[i][1] - 1;
            if(pieces[i] == "queen") p[i] = 1;
            if(pieces[i] == "bishop") p[i] = 2;
        }

        vector<int> d(n), s(n);
        return dfs_directions(n, p, pos, d, s, 0);
    }

private:
    int dfs_directions(int n, const vector<int>& pieces, const vector<pair<int, int>>& pos,
                       vector<int>& d, vector<int>& s, int index){

        if(index == n)
            return dfs_steps(n, pieces, pos, d, s, 0);

        int res = 0, L = dirs[pieces[index]].size();
        for(int i = 0; i < L; i ++){
            d[index] = i;
            res += dfs_directions(n, pieces, pos, d, s, index + 1);
        }
        return res;
    }

    int dfs_steps(int n, const vector<int>& pieces, const vector<pair<int, int>>& pos,
                  const vector<int>& d, vector<int>&s, int index){

        if(index == n){
            vector<pair<int, int>> cur = pos;
            vector<int> left = s;
            return dfs_check(n, cur, pieces, d, left);
        }

        int res = 0;
        if(d[index] == 0){
            s[index] = 0;
            res += dfs_steps(n, pieces, pos, d, s, index + 1);
        }
        else{
            int dx = dirs[pieces[index]][d[index]].first, dy = dirs[pieces[index]][d[index]].second;
            int cx = pos[index].first, cy = pos[index].second;
            for(int i = 1; i < 8; i ++){
                if(in_area(cx += dx, cy += dy)){
                    s[index] = i;
                    res += dfs_steps(n, pieces, pos, d, s, index + 1);
                }
                else break;
            }
        }
        return res;
    }

    bool dfs_check(int n, vector<pair<int, int>>& pos, const vector<int>& pieces,
                   const vector<int>& d, vector<int>& left){

        bool all_zero = true;
        for(int i = 0; i < n; i ++)
            if(left[i]){
                pos[i].first += dirs[pieces[i]][d[i]].first;
                pos[i].second += dirs[pieces[i]][d[i]].second;
                all_zero = false;
                left[i] --;
            }

        if(all_zero) return true;

        for(int i = 0; i < n; i ++)
            for(int j = i + 1; j < n; j ++)
                if(pos[i] == pos[j]) return false;

        return dfs_check(n, pos, pieces, d, left);
    }

    bool in_area(int x, int y){
        return x >= 0 && x < 8 && y >= 0 && y < 8;
    }
};


int main() {

    vector<string> pieces1 = {"rook"};
    vector<vector<int>> pos1 = {{1, 1}};
    cout << Solution().countCombinations(pieces1, pos1) << endl;
    // 15

    vector<string> pieces2 = {"queen"};
    vector<vector<int>> pos2 = {{1, 1}};
    cout << Solution().countCombinations(pieces2, pos2) << endl;
    // 22

    vector<string> pieces3 = {"bishop"};
    vector<vector<int>> pos3 = {{4, 3}};
    cout << Solution().countCombinations(pieces3, pos3) << endl;
    // 12

    vector<string> pieces4 = {"rook", "rook"};
    vector<vector<int>> pos4 = {{1, 1}, {8, 8}};
    cout << Solution().countCombinations(pieces4, pos4) << endl;
    // 223

    vector<string> pieces5 = {"queen", "bishop"};
    vector<vector<int>> pos5 = {{5, 7}, {3, 4}};
    cout << Solution().countCombinations(pieces5, pos5) << endl;
    // 281

    vector<string> pieces6 = {"rook", "queen", "rook", "rook"};
    vector<vector<int>> pos6 = {{3, 8}, {6, 8}, {5, 3}, {2, 3}};
    cout << Solution().countCombinations(pieces6, pos6) << endl;
    // 55717

    vector<string> pieces7 = {"bishop", "queen", "bishop", "bishop"};
    vector<vector<int>> pos7 = {{3, 7}, {7, 3}, {2, 4}, {4, 1}};
    cout << Solution().countCombinations(pieces7, pos7) << endl;
    // 15126

    return 0;
}
