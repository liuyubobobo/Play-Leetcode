/// Source : https://leetcode.cn/problems/kjpLFZ/
/// Author : liuyubobobo
/// Time   : 2023-05-07

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;


/// BFS
/// Time Complexity: O(R * C * k)
/// Space Complexity: O(R * C * k)
class Solution {

private:
    const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    int extractMantra(vector<string>& matrix, string mantra) {

        int R = matrix.size(), C = matrix[0].size(), k = mantra.size();

        vector<vector<vector<int>>> dis(k + 1, vector<vector<int>>(R, vector<int>(C, -1)));
        queue<tuple<int, int, int>> q;
        q.push({0, 0, 0});
        dis[0][0][0] = 0;
        while(!q.empty()){
            int index = get<0>(q.front()), cx = get<1>(q.front()), cy = get<2>(q.front());
            q.pop();

            int cur_dis = dis[index][cx][cy];
            if(index == k) return cur_dis;

            for(int d = 0; d < 4; d ++){
                int nx = cx + dirs[d][0], ny = cy + dirs[d][1];
                if(0 <= nx && nx < R && 0 <= ny && ny < C && dis[index][nx][ny] == -1){
                    dis[index][nx][ny] = cur_dis + 1;
                    q.push({index, nx, ny});
                }
            }

            if(matrix[cx][cy] == mantra[index] && dis[index + 1][cx][cy] == -1){
                dis[index + 1][cx][cy] = cur_dis + 1;
                q.push({index + 1, cx, cy});
            }
        }

        return -1;
    }
};


int main() {

    return 0;
}
