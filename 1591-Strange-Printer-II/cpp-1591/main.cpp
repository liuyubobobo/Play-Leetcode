/// Source : https://leetcode.com/problems/strange-printer-ii/
/// Author : liuyubobobo
/// Time   : 2020-09-20

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Simulation
/// Time Complexity: O(num^2 * m * n)
/// Space Complexity: O(m * n + num)
class Solution {

private:
    class Rectangle{
    public:
        int color, minx, maxx, miny, maxy, cnt;

        Rectangle(int color): color(color), cnt(0),
                              minx(INT_MAX), maxx(INT_MIN), miny(INT_MAX), maxy(INT_MIN){}

        int diff() const{
            return (maxx - minx + 1) * (maxy - miny + 1) - cnt;
        }
    };

public:
    bool isPrintable(vector<vector<int>>& targetGrid) {

        vector<Rectangle*> table(61, NULL);

        for(int i = 0; i < targetGrid.size(); i ++)
            for(int j = 0; j < targetGrid[i].size(); j ++){
                int color = targetGrid[i][j];
                if(!table[color])
                    table[color] = new Rectangle(color);
                table[color]->minx = min(table[color]->minx, i);
                table[color]->maxx = max(table[color]->maxx, i);
                table[color]->miny = min(table[color]->miny, j);
                table[color]->maxy = max(table[color]->maxy, j);
                table[color]->cnt ++;
            }

        vector<Rectangle*> q;
        for(int i = 1; i <= 60; i ++)
            if(table[i] && table[i]->diff() == 0){
                q.push_back(table[i]);
                table[i] = NULL;
            }

        while(!q.empty()){

            Rectangle* cur = q.back();
            q.pop_back();

            for(int i = 1; i <= 60; i ++)
                if(table[i]){
                    Rectangle* rec = table[i];
                    for(int i = cur->minx; i <= cur->maxx; i ++)
                        if(rec->minx <= i && i <= rec->maxx)
                            for(int j = cur->miny; j <= cur->maxy; j ++)
                                if(rec->miny <= j && j <= rec->maxy)
                                    rec->cnt += (targetGrid[i][j] != 0);

                    if(rec->diff() == 0){
                        q.push_back(rec);
                        table[i] = NULL;
                    }
                }

            for(int i = cur->minx; i <= cur->maxx; i ++)
                for(int j = cur->miny; j <= cur->maxy; j ++)
                    targetGrid[i][j] = 0;
        }

        for(int i = 1; i <= 60; i ++) if(table[i]) return false;
        return true;
    }
};


int main() {

    vector<vector<int>> grid1 = {
            {1,1,1,1},{1,2,2,1},{1,2,2,1},{1,1,1,1}
    };
    cout << Solution().isPrintable(grid1) << endl;
    // 1

    vector<vector<int>> grid2 = {
            {1,1,1,1},{1,1,3,3},{1,1,3,4},{5,5,1,4}
    };
    cout << Solution().isPrintable(grid2) << endl;
    // 1

    vector<vector<int>> grid3 = {
            {1,2,1},{2,1,2},{1,2,1}
    };
    cout << Solution().isPrintable(grid3) << endl;
    // 0

    vector<vector<int>> grid4 = {
            {1,1,1},{3,1,3}
    };
    cout << Solution().isPrintable(grid4) << endl;
    // 0

    return 0;
}
