/// Source : https://leetcode.com/problems/rotating-the-box/
/// Author : liuyubobobo
/// Time   : 2021-05-15

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(R * C)
/// Space Complexity: O(R * C)
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {

        int R = box.size(), C = box[0].size();
        vector<vector<char>> res(C, vector<char>(R));
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++)
                res[j][R - 1 - i] = box[i][j];

        fall(res);
        return res;
    }

private:
    void fall(vector<vector<char>>& box){

        int R = box.size(), C = box[0].size();
        for(int j = 0; j < C; j ++){
            int k = R - 1, i = R - 1;
            for(; i >= 0; i --)
                if(box[i][j] == '#')
                    box[i][j] = '.',
                    box[k][j] = '#',
                    k --;
                else if(box[i][j] == '*')
                    k = i - 1;
        }
    }
};


void print(const vector<vector<char>>& box){

    for(const vector<char>& line: box){
        for(char c: line) cout << c << " ";
        cout << endl;
    }
}

int main() {

    vector<vector<char>> box1 = {{'#', '.', '#'}};
    print(Solution().rotateTheBox(box1));
    // .
    // #
    // #

    vector<vector<char>> box2 = {{'#', '.', '*', '.'},
                                 {'#', '#', '*', '.'}};
    print(Solution().rotateTheBox(box2));
    // # .
    // # #
    // * *
    // . .

    return 0;
}
