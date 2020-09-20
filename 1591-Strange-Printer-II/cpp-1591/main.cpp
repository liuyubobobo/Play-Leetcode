#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;


class Solution {

private:
    class Rectangle{
    public:
        int color, minx, maxx, miny, maxy;
        unordered_set<int> points;

        Rectangle(int color): color(color),
                              minx(INT_MAX), maxx(INT_MIN), miny(INT_MAX), maxy(INT_MIN){}

        Rectangle(): Rectangle(-1){};

        const int diff() const{
            return (maxx - minx + 1) * (maxy - miny + 1) - points.size();
        }
    };

public:
    bool isPrintable(vector<vector<int>>& targetGrid) {

        unordered_map<int, Rectangle> table;

        for(int i = 0; i < targetGrid.size(); i ++)
            for(int j = 0; j < targetGrid[i].size(); j ++){
                if(!table.count(targetGrid[i][j]))
                    table[targetGrid[i][j]] = Rectangle(targetGrid[i][j]);
                table[targetGrid[i][j]].minx = min(table[targetGrid[i][j]].minx, i);
                table[targetGrid[i][j]].maxx = max(table[targetGrid[i][j]].maxx, i);
                table[targetGrid[i][j]].miny = min(table[targetGrid[i][j]].miny, j);
                table[targetGrid[i][j]].maxy = max(table[targetGrid[i][j]].maxy, j);
                table[targetGrid[i][j]].points.insert(i * 70 + j);
            }

        vector<Rectangle> q;
        for(const pair<int, Rectangle>& p: table)
            if(p.second.diff() == 0)
                q.push_back(p.second);

        for(const Rectangle& rec: q) table.erase(rec.color);

        while(!q.empty()){

            Rectangle cur = q.back();
            q.pop_back();

            for(const pair<int, Rectangle>& p: table){
                Rectangle rec = p.second;
                for(int i = cur.minx; i <= cur.maxx; i ++)
                    if(rec.minx <= i && i <= rec.maxx)
                        for(int j = cur.miny; j <= cur.maxy; j ++)
                            if(rec.miny <= j && j <= rec.maxy)
                                rec.points.insert(i * 70 + j);
                table[p.first] = rec;

                if(rec.diff() == 0) q.push_back(rec);
            }

            for(const Rectangle& rec: q) table.erase(rec.color);
        }
        return table.size() == 0;
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
