/// Source : https://leetcode.com/problems/execution-of-all-suffix-instructions-staying-in-a-grid/
/// Author : liuyubobobo
/// Time   : 2021-12-25

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(m * n)
/// Space Compelxity: O(1)
class Solution {
private:
    int N;

public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {

        N = n;

        int m = s.size();
        vector<int> res(m);
        for(int i = 0; i < m; i ++)
            res[i] = go(s, startPos[0], startPos[1], i);
        return res;
    }

private:
    int go(const string& s, int x, int y, int start){

        int res = 0;
        for(int i = start; i < s.size(); i ++){
            if(s[i] == 'R') y ++;
            else if(s[i] == 'L') y --;
            else if(s[i] == 'U') x --;
            else if(s[i] == 'D') x ++;
            if((x >= 0 && x < N && y >= 0 && y < N)) res ++;
            else break;
        }
        return res;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << ' '; cout << '\n';
}

int main() {

    vector<int> start1 = {0, 1};
    print_vec(Solution().executeInstructions(3, start1, "RRDDLU"));

    return 0;
}
