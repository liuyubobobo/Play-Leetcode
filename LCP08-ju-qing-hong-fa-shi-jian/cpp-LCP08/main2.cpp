/// Source : https://leetcode-cn.com/problems/ju-qing-hong-fa-shi-jian/
/// Author : liuyubobobo
/// Time   : 2020-04-18

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace  std;


/// Binary Search
/// Time Complexity: O(|r| * log(|inc|))
/// Space Complexity: O(|inc|)
class Solution {
public:
    vector<int> getTriggerTime(vector<vector<int>>& inc, vector<vector<int>>& r) {

        vector<vector<int>> v = {{0, 0, 0}};
        for(const vector<int>& e: inc){
            vector<int> newe = v.back();
            newe[0] += e[0], newe[1] += e[1], newe[2] += e[2];
            v.push_back(newe);
        }

        vector<int> res;
        for(const vector<int>& e: r)
            res.push_back(binary_search(v, e));
        return res;
    }

private:
    int binary_search(const vector<vector<int>>& v, const vector<int>& e){

        int l = 0, r = v.size();
        while(l != r){
            int mid = (l + r) / 2;
            if(v[mid][0] >= e[0] && v[mid][1] >= e[1] && v[mid][2] >= e[2])
                r = mid;
            else
                l = mid + 1;
        }
        return l == v.size() ? -1 : l;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << " "; cout << endl;
}

int main() {

    vector<vector<int>> inc1 = {{2,8,4},{2,5,0},{10,9,8}};
    vector<vector<int>> r1 = {{2,11,3},{15,10,7},{9,17,12},{8,1,14}};
    print_vec(Solution().getTriggerTime(inc1, r1));
    // 2,-1,3,-1

    vector<vector<int>> inc2 = {{0,4,5}, {4,8,8},{8,6,1},{10,10,0}};
    vector<vector<int>> r2 = {{12,11,16},{20,2,6},{9,2,6},{10,18,3},{8,14,9}};
    print_vec(Solution().getTriggerTime(inc2, r2));
    // -1 4 3 3 3

    vector<vector<int>> inc3 = {{1,1,1}};
    vector<vector<int>> r3 = {{0,0,0}};
    print_vec(Solution().getTriggerTime(inc3, r3));
    // 0

    return 0;
}
