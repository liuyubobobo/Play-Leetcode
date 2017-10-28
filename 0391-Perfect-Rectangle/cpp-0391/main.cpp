/// Source : https://leetcode.com/problems/perfect-rectangle/description/
/// Author : liuyubobobo
/// Time   : 2017-10-27

#include <iostream>
#include <vector>
#include <cassert>
#include <map>

using namespace std;

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {

        int area = 0;
        int minx = INT_MAX, miny = INT_MAX;
        int maxx = 0, maxy = 0;

        map<pair<int,int>, int> corners;

        for(vector<int> rectangle: rectangles){
            assert(rectangle.size() == 4);
            minx = min(minx, rectangle[0]);
            miny = min(miny, rectangle[1]);
            maxx = max(maxx, rectangle[2]);
            maxy = max(maxy, rectangle[3]);
            area += (rectangle[2] - rectangle[0]) * (rectangle[3] - rectangle[1]);

            add_corner(corners, rectangle[0], rectangle[1]);
            add_corner(corners, rectangle[0], rectangle[3]);
            add_corner(corners, rectangle[2], rectangle[1]);
            add_corner(corners, rectangle[2], rectangle[3]);
        }

        if(area == (maxx - minx) * (maxy - miny))
            return make_sense(corners, make_pair(minx, miny), make_pair(maxx, maxy));

        return false;
    }

private:
    void add_corner(map<pair<int,int>, int>& corners, int x, int y){
        pair<int, int> corner = make_pair(x, y);
        if(corners.find(corner) == corners.end())
            corners[corner] = 1;
        else
            corners[corner] ++;
    }

    bool make_sense(map<pair<int,int>, int>& corners,
                    const pair<int, int>& leftBottom, const pair<int, int>& rightTop){

        if(corners[leftBottom] != 1)
            return false;
        corners.erase(leftBottom);

        if(corners[rightTop] != 1)
            return false;
        corners.erase(rightTop);

        pair<int, int> leftTop = make_pair(leftBottom.first, rightTop.second);
        if(corners[leftTop] != 1)
            return false;
        corners.erase(leftTop);

        pair<int, int> rightBottom = make_pair(rightTop.first, leftBottom.second);
        if(corners[rightBottom] != 1)
            return false;
        corners.erase(rightBottom);

        for(map<pair<int,int>, int>::iterator iter = corners.begin();
                iter != corners.end(); iter ++){
            if(iter->second % 2)
                return false;
        }

        return true;
    }
};


void printBool(bool res){
    cout << (res ? "true" : "false") << endl;
}

int main() {

    int n1 = 5;
    int rectangles1[5][4] = {
            {1, 1, 3, 3},
            {3, 1, 4, 2},
            {3, 2, 4, 4},
            {1, 3, 2, 4},
            {2, 3, 3, 4}
    };
    vector<vector<int>> vec1;
    for(int i = 0 ; i < n1 ; i ++)
        vec1.push_back(vector<int>(rectangles1[i], rectangles1[i] + 4));
    printBool(Solution().isRectangleCover(vec1));
    // true

    // ---

    int n2 = 4;
    int rectangles2[4][4] = {
            {1,1,2,3},
            {1,3,2,4},
            {3,1,4,2},
            {3,2,4,4}
    };
    vector<vector<int>> vec2;
    for(int i = 0 ; i < n2 ; i ++)
        vec2.push_back(vector<int>(rectangles2[i], rectangles2[i] + 4));
    printBool(Solution().isRectangleCover(vec2));
    // false

    // ---

    int n3 = 4;
    int rectangles3[4][4] = {
            {1,1,3,3},
            {3,1,4,2},
            {1,3,2,4},
            {3,2,4,4}
    };
    vector<vector<int>> vec3;
    for(int i = 0 ; i < n3 ; i ++)
        vec3.push_back(vector<int>(rectangles3[i], rectangles3[i] + 4));
    printBool(Solution().isRectangleCover(vec3));
    // false

    // ---

    int n4 = 12;
    int rectangles4[12][4] = {
            {0,0,4,1},
            {7,0,8,2},
            {6,2,8,3},
            {5,1,6,3},
            {4,0,5,1},
            {6,0,7,2},
            {4,2,5,3},
            {2,1,4,3},
            {0,1,2,2},
            {0,2,2,3},
            {4,1,5,2},
            {5,0,6,1}
    };
    vector<vector<int>> vec4;
    for(int i = 0 ; i < n4 ; i ++)
        vec4.push_back(vector<int>(rectangles4[i], rectangles4[i] + 4));
    printBool(Solution().isRectangleCover(vec4));
    // true

    return 0;
}