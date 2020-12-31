/// Source : https://leetcode.com/problems/erect-the-fence/
/// Author : liuyubobobo
/// Time   : 2020-05-01

#include <iostream>
#include <vector>

using namespace std;


/// Graham Scan - Two Pass
/// Time Complexity: O(nlogn + 2n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& points) {

        if(points.size() <= 3) return points;

        sort(points.begin(), points.end(),
             [](const vector<int>& p1, const vector<int>& p2){
                 return p1[0] == p2[0] ? p1[1] < p2[1] : p1[0] < p2[0];
             });

        vector<vector<int>> res;
        for(vector<vector<int>>::iterator iter = points.begin(); iter != points.end(); iter ++){
            while(res.size() >= 2){
                int det = cross_value(res[res.size() - 2], res.back(), *iter);
                if(det < 0)
                    res.pop_back();
                else break;
            }
            res.push_back(*iter);
        }

        vector<vector<int>>::reverse_iterator riter = points.rbegin();
        for(riter ++; riter != points.rend(); riter ++){
            while(res.size() >= 2 && cross_value(res[res.size() - 2], res.back(), *riter) < 0)
                res.pop_back();
            res.push_back(*riter);
        }

        res.pop_back();
        return res;
    }

private:
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

    vector<vector<int>> points = {{1,1},{2,2},{2,0},{2,4},{3,3},{4,2}};
    print_vec(Solution().outerTrees(points));

    return 0;
}
