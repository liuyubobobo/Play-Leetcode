/// Source : https://leetcode.com/problems/number-of-distinct-islands-ii/description/
/// Author : liuyubobobo
/// Time   : 2017-10-19

#include <iostream>
#include <vector>
#include <cassert>
#include <set>

using namespace std;

/// floodfill
/// Time Complexity: O(n*m*n*m)
/// Space Complexity: O(n*m)
class Solution {

private:
    class Island{

    public:
        vector<vector<int>> shape;

        Island(const vector<vector<int>>& ashape){
            shape = ashape;
        }

        bool operator==(const Island& other){

            vector<vector<int>> other_shape = other.shape;

            for(int i = 0 ; i < 4 ; i ++){
                if(sameShape(other_shape))
                    return true;

                vector<vector<int>> h_reflection_shape = hReflect(other_shape);
                if(sameShape(h_reflection_shape))
                    return true;

                vector<vector<int>> v_reflection_shape = vReflect(other_shape);
                if(sameShape(v_reflection_shape))
                    return true;

                other_shape = rotate(other_shape);
            }

            assert(sameShape(other_shape, other.shape));

            return false;
        }

        friend ostream& operator<<(ostream &os, const Island& island){

            os << island.shape.size() << " x ";
            assert(island.shape.size() > 0);
            os << island.shape[0].size() << endl;

            for(int i = 0 ; i < island.shape.size() ; i ++){
                for(int j = 0 ; j < island.shape[i].size() ; j ++)
                    os << island.shape[i][j];
                os << endl;
            }
            return os;
        }

    private:
        bool sameShape(const vector<vector<int>>& other_shape){

            if(shape.size() != other_shape.size())
                return false;

            assert(shape.size() > 0 && other_shape.size() > 0);
            if(shape[0].size() != other_shape[0].size())
                return false;

            for(int i = 0 ; i < shape.size() ; i ++)
                for(int j = 0 ;  j < shape[0].size() ; j ++)
                    if(shape[i][j] != other_shape[i][j])
                        return false;

            return true;
        }

        bool sameShape(const vector<vector<int>>& shapeA,
                       const vector<vector<int>>& shapeB){

            if(shapeA.size() != shapeB.size())
                return false;

            assert(shapeA.size() > 0 && shapeB.size() > 0);
            if(shapeA[0].size() != shapeB[0].size())
                return false;

            for(int i = 0 ; i < shapeA.size() ; i ++)
                for(int j = 0 ;  j < shapeA[0].size() ; j ++)
                    if(shapeA[i][j] != shapeB[i][j])
                        return false;

            return true;
        }

        vector<vector<int>> rotate(const vector<vector<int>>& ashape){

            int n = ashape.size();
            assert(n > 0);
            int m = ashape[0].size();

            vector<vector<int>> res(m, vector<int>(n, 0));
            for(int i = 0 ; i < n ; i ++)
                for(int j = 0 ; j < m ; j ++)
                    res[j][n-1-i] = ashape[i][j];

            return res;
        }

        vector<vector<int>> hReflect(const vector<vector<int>>& ashape){
            int n = ashape.size();
            assert(n > 0);
            int m = ashape[0].size();

            vector<vector<int>> res(n, vector<int>(m, 0));
            for(int i = 0 ; i < n ; i ++)
                for(int j = 0 ; j < m ; j ++)
                    res[n-1-i][j] = ashape[i][j];

            return res;
        }

        vector<vector<int>> vReflect(const vector<vector<int>>& ashape){
            int n = ashape.size();
            assert(n > 0);
            int m = ashape[0].size();

            vector<vector<int>> res(n, vector<int>(m, 0));
            for(int i = 0 ; i < n ; i ++)
                for(int j = 0 ; j < m ; j ++)
                    res[i][m-1-j] = ashape[i][j];

            return res;
        }
    };

    int d[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int n, m;
    vector<Island> islands;
    int tag[50][50];

public:
    int numDistinctIslands2(vector<vector<int>>& grid) {
        n = grid.size();
        assert(n > 0);
        m = grid[0].size();

        islands.clear();

        for(int i = 0 ; i < n ; i ++)
            for(int j = 0 ; j < m ; j ++)
                tag[i][j] = 0;

        // DFS
        int index = 1;
        for(int i = 0 ; i < n ; i ++)
            for(int j = 0 ; j < m ; j ++)
                if(tag[i][j] == 0 && grid[i][j] == 1){
                    dfs(grid, i, j, index);
                    Island island = getIsland(grid, index);

                    bool repeat = false;
                    for(int i = 0 ; i < islands.size() ; i ++)
                        if(island == islands[i]){
                            repeat = true;
                            break;
                        }

                    if(!repeat)
                        islands.push_back(island);

                    index ++;
                }

//        for(Island& island: islands)
//            cout << island << endl;

        return islands.size();
    }

private:
    bool inArea(int x, int y){
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    void dfs(const vector<vector<int>>& grid, int x, int y, int index){

        tag[x][y] = index;

        for(int i = 0 ; i < 4 ; i ++){
            int newx = x + d[i][0];
            int newy = y + d[i][1];
            if(inArea(newx, newy) && tag[newx][newy] == 0 && grid[newx][newy] == 1)
                dfs(grid, newx, newy, index);
        }
    }

    Island getIsland(const vector<vector<int>>& grid, int index){

        int minx = n, miny = m, maxx = -1, maxy = -1;
        for(int i = 0 ; i < n ; i ++)
            for(int j = 0 ; j < m ; j ++)
                if(tag[i][j] == index){
                    minx = min(minx, i);
                    miny = min(miny, j);
                    maxx = max(maxx, i);
                    maxy = max(maxy, j);
                }

        vector<vector<int>> shape(maxx-minx+1, vector<int>(maxy-miny+1, 0));
        for(int i = minx; i <= maxx ; i ++)
            for(int j = miny; j <= maxy; j ++)
                if(tag[i][j] == index)
                    shape[i-minx][j-miny] = 1;

        return Island(shape);
    }
};


vector<vector<int>> getMapVec(string grid_map[], int n, int m){

    vector<vector<int>> res(n, vector<int>(m, 0));
    for(int i = 0 ; i < n ; i ++)
        for(int j = 0 ; j < grid_map[i].size() ; j ++)
            if(grid_map[i][j] == '1')
                res[i][j] = 1;
    return res;
}


int main() {

    int n1 = 4, m1 = 5;
    string grid_map1[] = {
            "11000",
            "10000",
            "00001",
            "00011",
    };
    vector<vector<int>> grid_map_vec1 = getMapVec(grid_map1, n1, m1);
    cout << Solution().numDistinctIslands2(grid_map_vec1) << endl;

    int n2 = 4, m2 = 5;
    string grid_map2[] = {
            "11100",
            "10001",
            "01001",
            "01110",
    };
    vector<vector<int>> grid_map_vec2 = getMapVec(grid_map2, n2, m2);
    cout << Solution().numDistinctIslands2(grid_map_vec2) << endl;

    int grid_map3[22][50] = {
            {1,0,1,0,0,1,0,0,1,1,0,0,0,1,1,1,1,0,1,1,0,1,0,0,0,0,0,0,1,1,0,1,0,0,1,0,0,0,0,1,0,1,0,0,1,1,0,1,0,0},
            {1,1,0,1,0,0,1,0,1,1,0,1,1,1,1,1,0,0,0,0,1,1,1,0,0,0,1,0,0,1,1,1,1,1,0,0,1,0,0,0,1,0,1,1,1,1,1,0,0,1},
            {1,1,0,0,1,0,0,1,0,1,0,1,1,0,0,1,0,0,1,1,0,0,0,1,0,0,0,1,1,1,1,1,0,0,0,1,1,0,1,0,0,0,1,1,1,0,0,1,1,0},
            {1,1,1,0,0,0,0,1,0,1,0,1,1,0,0,1,1,0,1,0,1,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,0,1,0,0,1,0,0,1,0,1},
            {0,0,1,0,1,0,0,1,1,0,1,1,0,1,1,1,0,1,1,1,0,1,0,0,1,1,1,0,0,0,0,1,1,0,1,1,1,0,0,0,0,0,0,0,0,1,1,0,1,0},
            {0,0,1,1,1,0,0,1,0,1,1,0,0,1,1,1,0,0,1,0,0,1,0,0,1,1,1,1,0,1,0,0,1,1,1,1,1,1,0,0,1,0,0,1,0,1,1,0,1,1},
            {0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0,0,1,1,0,0,0,1,1,0,0,1,1,0,0,0,1,1,0,0,1,1,1,1,1,0,1,1,1,1},
            {1,1,1,1,1,0,1,1,0,1,1,0,0,0,1,1,1,0,0,0,0,1,1,0,0,0,0,0,0,1,1,1,0,1,1,0,0,0,1,0,1,1,0,1,0,0,1,0,1,0},
            {0,0,0,1,0,1,1,0,1,0,1,1,0,1,0,0,1,1,1,0,1,1,1,1,1,0,1,0,1,0,1,0,0,1,1,1,1,1,0,1,1,1,1,1,1,0,1,0,1,1},
            {1,1,0,0,0,1,0,0,1,0,0,0,0,1,0,1,1,1,1,1,1,1,0,0,0,1,0,0,1,1,0,0,1,1,0,0,0,1,0,1,0,1,1,1,1,0,0,0,0,1},
            {0,1,0,1,0,1,1,0,0,0,0,0,0,1,1,0,1,1,1,1,1,1,0,0,0,1,0,0,1,0,1,1,1,0,0,0,0,1,1,0,0,0,0,0,1,1,1,1,0,0},
            {0,0,1,0,0,0,0,0,1,0,0,1,1,0,0,0,1,1,1,0,1,1,1,1,0,0,1,1,1,1,1,0,0,0,0,1,1,1,0,0,1,1,1,0,0,1,0,0,1,1},
            {1,1,0,0,1,1,0,0,0,0,1,1,1,1,1,1,0,0,1,1,0,0,1,1,0,1,0,1,0,0,0,1,1,1,0,0,0,1,0,1,1,1,1,0,0,0,1,0,0,0},
            {0,1,1,0,1,1,1,1,1,0,0,1,1,1,1,0,0,0,1,0,0,1,0,1,1,0,1,0,1,1,1,1,0,1,1,1,0,0,1,0,1,0,1,1,1,1,0,1,1,1},
            {1,0,1,0,1,1,1,1,1,0,1,0,0,0,1,1,1,1,0,1,1,1,1,0,1,1,1,0,0,1,1,0,1,1,1,1,1,1,1,0,0,0,1,0,1,1,0,1,0,0},
            {1,1,1,0,0,0,1,1,1,0,0,1,0,1,1,1,0,0,1,0,1,0,0,1,0,0,1,0,0,0,0,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,1},
            {0,0,1,1,1,0,1,1,1,1,1,0,0,1,1,0,0,0,1,1,0,1,1,0,1,1,0,1,1,1,1,1,0,0,1,1,1,0,1,1,1,1,0,0,0,0,1,1,0,0},
            {1,1,1,0,0,0,1,0,1,1,1,1,1,0,0,0,1,0,0,0,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,1,0,0,1,0,0,1},
            {0,0,1,0,1,1,1,1,0,0,0,1,0,1,1,0,0,1,0,0,1,1,1,0,1,1,1,0,0,1,0,0,0,1,0,0,1,0,0,1,1,0,1,0,1,1,1,0,0,0},
            {0,1,0,0,1,0,0,1,0,1,1,0,1,0,0,0,1,1,1,0,0,1,0,0,1,0,1,0,0,0,0,0,1,1,0,1,1,0,1,0,1,0,0,1,1,1,0,0,0,0},
            {1,0,0,0,0,1,1,1,1,0,0,0,1,1,0,1,1,0,1,0,1,0,1,0,0,1,1,0,1,1,0,1,0,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,1,0},
            {1,0,1,0,0,1,1,0,1,1,0,0,1,0,0,1,1,0,1,1,1,0,1,0,1,1,1,0,1,0,0,0,1,0,0,1,0,1,0,1,1,1,0,1,1,1,1,0,0,1}
    };
    int n3 = 22, m3 = 50;
    vector<vector<int>> grid_map_vec3(n3, vector<int>(m3, 0));
    for(int i = 0 ; i < n3 ; i ++){
        for(int j = 0 ; j < m3 ; j ++){
            if(grid_map3[i][j])
                grid_map_vec3[i][j] = 1;
            //cout << grid_map_vec3[i][j];
        }
        //cout << endl;
    }
    //cout << endl;

    cout << Solution().numDistinctIslands2(grid_map_vec3) << endl;

    return 0;
}