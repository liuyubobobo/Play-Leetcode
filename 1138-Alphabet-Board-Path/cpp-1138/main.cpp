/// Source : https://leetcode.com/problems/two-sum/description/
/// Author : liuyubobobo
/// Time   : 2019-07-27

#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;


/// BFS
/// Time Complexity: O(len(target) * 26)
/// Space Complexity: O(26 * 26)
class Path{
private:
    const int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    vector<string> board = {"abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"};
    vector<int> pre;
    int start;

public:
    Path(char c){
        start = c - 'a';
        for(int i = 0; i < 26; i ++) pre.push_back(-1);

        vector<bool> visited(26, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;
        pre[start] = start;
        while(!q.empty()){
            int cur = q.front();
            q.pop();

            int x = cur / 5, y = cur % 5;
            for(int d = 0; d < 4; d ++){
                int nextx = x + dirs[d][0], nexty = y + dirs[d][1];
                int next = nextx * 5 + nexty;
                if(inArea(nextx, nexty) && !visited[next]){
                    q.push(next);
                    visited[next] = true;
                    pre[next] = cur;
                }
            }
        }
//        cout << start << " : "; for(int e: pre) cout << e << " "; cout << endl;
    }

    string path(char target){

        string res = "";
        int cur = target - 'a';
        while(cur != start){
            res += get_dir(pre[cur], cur);
            cur = pre[cur];
        }
        reverse(res.begin(), res.end());
        return res;
    }

private:
    bool inArea(int x, int y){
        if(x <= 4) return x >= 0 && x <= 4 && y >= 0 && y < 5;
        return x == 5 && y == 0;
    }

    char get_dir(int s, int t){
        int sx = s / 5, sy = s % 5;
        int tx = t / 5, ty = t % 5;
        string res = "URDL";
        for(int i = 0; i < 4; i ++)
            if(sx + dirs[i][0] == tx && sy + dirs[i][1] == ty)
                return res[i];
        assert(false);
        return ' ';
    }
};

class Solution {
public:
    string alphabetBoardPath(string target) {

        vector<Path> paths;
        for(int i = 0; i < 26; i ++)
            paths.push_back(Path('a' + i));

        target = "a" + target;
        string res = "";
        for(int i = 1; i < target.size(); i ++)
            res += paths[target[i - 1] - 'a'].path(target[i]) + "!";
        return res;
    }
};


int main() {

    cout << Solution().alphabetBoardPath("leet") << endl;
    // DDR!UURRR!!DDD!

    cout << Solution().alphabetBoardPath("code") << endl;
    // DDR!UURRR!!DDD!

    return 0;
}