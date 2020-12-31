/// Source : https://leetcode.com/problems/erect-the-fence/
/// Author : liuyubobobo
/// Time   : 2020-05-01

#include <iostream>
#include <vector>

using namespace std;


/// Jarvis Algorithm
/// Time Complexity: O(n*H)
/// Space Complexity: O(1)
class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& points) {

        if(points.size() <= 3) return points;

        int leftmost = 0;
        for(int i = 1; i < points.size(); i ++)
            if(points[i][0] < points[leftmost][0] ||
               (points[i][0] == points[leftmost][0] && points[i][1] < points[leftmost][1]))
                leftmost = i;

        int p = leftmost;
        vector<int> res = {p};
        while(true){
            int next = (res.back() + 1) % points.size();
            for(int i = 0; i < points.size(); i ++)
                if(i != res.back() && i != next)
                    if(cross_value(points[res.back()], points[next], points[i]) < 0)
                        next = i;

            for(int i = 0; i < points.size(); i ++)
                if(i != res.back() && i != next && in_between(points[p], points[i], points[next]))
                    res.push_back(i);

            if(next == leftmost) break;
            res.push_back(next);
            p = next;
        }

        vector<vector<int>> ret;
        for(int i: res) ret.push_back(points[i]);
        return ret;
    }

private:
    // see if x in between of p1 and p2
    bool in_between(const vector<int>& p1, const vector<int>& x, const vector<int>& p2){

        if(x[0] == p1[0] && x[1] == p1[1]) return false;
        if(x[0] == p2[0] && x[1] == p2[1]) return false;
        if(cross_value(p1, x, p2) != 0) return false;

        int a = p1[0], b = p2[0];
        if(a > b) swap(a, b);
        if(x[0] < a || x[0] > b) return false;

        a = p1[1], b = p2[1];
        if(a > b) swap(a, b);
        if(x[1] < a || x[1] > b) return false;

        return true;
    }

    int cross_value(const vector<int>& p1, const vector<int>& p2, const vector<int>& p3){
        int a = p2[0] - p1[0], b = p2[1] - p1[1];
        int c = p3[0] - p2[0], d = p3[1] - p2[1];
        return a * d - b * c;
    }
};


void print_vec(const vector<vector<int>>& vec){
    for(const vector<int>& p: vec) cout << "(" << p[0] << "," << p[1] << ")"; cout << endl;
}


int main() {

//    vector<vector<int>> points1 = {{1,1},{2,2},{2,0},{2,4},{3,3},{4,2}};
//    print_vec(Solution().outerTrees(points1));

    vector<vector<int>> points2 = {{0,0},{0,1},{0,2},{1,2},{2,2},{3,2},{3,1},{3,0},{2,0}};
    print_vec(Solution().outerTrees(points2));

    return 0;
}
