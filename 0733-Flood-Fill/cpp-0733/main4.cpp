/// Source : https://leetcode.com/problems/flood-fill/description/
/// Author : liuyubobobo
/// Time   : 2018-09-29

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/// DFS - Using Stack
///
/// Time Complexity: O(n*m)
/// Space Complexity: O(n*m)
class Solution {

private:
    int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int n, m;

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int newColor) {

        n = image.size();
        m = image[0].size();
        int oldColor = image[sr][sc];

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        stack<pair<int, int>> stack;
        stack.push(make_pair(sr, sc));
        visited[sr][sc] = true;
        while(!stack.empty()){
            int x = stack.top().first, y = stack.top().second;
            stack.pop();

            image[x][y] = newColor;
            for(int i = 0; i < 4; i ++){
                int newX = x + d[i][0], newY = y + d[i][1];
                if(inArea(newX, newY) && !visited[newX][newY] && image[newX][newY] == oldColor){
                    visited[newX][newY] = true;
                    stack.push(make_pair(newX, newY));
                }
            }
        }

        return image;
    }

private:
    bool inArea(int x, int y){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
};


void printImage(const vector<vector<int>>& image){
    for(vector<int> row: image){
        for(int pixel: row)
            cout << pixel << "\t";
        cout << endl;
    }
}

int main() {

    vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    printImage(Solution().floodFill(image, 1, 1, 2));

    return 0;
}