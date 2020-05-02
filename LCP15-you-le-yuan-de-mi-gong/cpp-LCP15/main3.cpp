/// Source : https://leetcode-cn.com/problems/you-le-yuan-de-mi-gong/
/// Author : liuyubobobo
/// Time   : 2020-05-01

#include <iostream>
#include <vector>

using namespace std;


/// Greedy
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> visitOrder(vector<vector<int>>& points, string direction) {

        int n = points.size();

        int leftmost = 0;
        for(int i = 0; i < n; i ++)
            if(points[i][0] < points[leftmost][0] ||
               (points[i][0] == points[leftmost][0] && points[i][1] < points[leftmost][1]))
                leftmost = i;

        vector<int> res = {leftmost};
        vector<bool> used(n, false);
        used[leftmost] = true;

        for(char c: direction){
            int p;
            for(p = 0; p < n; p ++) if(!used[p]) break;
            if(c == 'L'){
                for(int i = p + 1; i < n; i ++)
                    if(!used[i] && cross(points[res.back()], points[p], points[i]) < 0)
                        p = i;
            }
            else{
                for(int i = p + 1; i < n; i ++)
                    if(!used[i] && cross(points[res.back()], points[p], points[i]) > 0)
                        p = i;
            }
            res.push_back(p);
            used[p] = true;
        }
        for(int i = 0; i < n; i ++) if(!used[i]){res.push_back(i); break;}
        return res;
    }

private:
    int cross(const vector<int>& p1, const vector<int>& p2, const vector<int>& p3){
        return (p2[0] - p1[0]) * (p3[1] - p2[1]) - (p3[0] - p2[0]) * (p2[1] - p1[1]);
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << " "; cout << endl;
}

int main() {

    vector<vector<int>> points1 = {{1,1},{1,4},{3,2},{2,1}};
    print_vec(Solution().visitOrder(points1, "LL"));

    return 0;
}
