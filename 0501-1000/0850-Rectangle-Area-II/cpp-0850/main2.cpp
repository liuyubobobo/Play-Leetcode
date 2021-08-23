/// Source : https://leetcode.com/problems/rectangle-area-ii/
/// Author : liuyubobobo
/// Time   : 2021-08-22

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;


/// Sweep lines
/// Using multiset to optimize
///
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {

private:
    const int OPEN = 0, CLOSE = 1;
    long long MOD = 1e9 + 7;

public:
    int rectangleArea(vector<vector<int>>& rectangles) {

        vector<vector<int>> events; // x, open or close, y1, y2
        for(const vector<int>& rec: rectangles){
            int x1 = rec[0], y1 = rec[1], x2 = rec[2], y2 = rec[3];
            events.push_back({x1, OPEN, y1, y2});
            events.push_back({x2, CLOSE, y1, y2});
        }

        sort(events.begin(), events.end());

        int px = events[0][0];
        multiset<pair<int, int>> activey = {{events[0][2], events[0][3]}};
        long long res = 0ll;
        for(int i = 1; i < events.size(); i ++){
            int x = events[i][0], type = events[i][1], y1 = events[i][2], y2 = events[i][3];

            long long y = 0;
            if(!activey.empty()){
                pair<int, int> cur = {-1, -1};
                for(const pair<int, int>& p: activey){
                    if(cur.first == -1) cur = p;
                    else if(p.first <= cur.second) cur.second = max(cur.second, p.second);
                    else{
                        y += cur.second - cur.first;
                        cur = p;
                    }
                }
                if(cur.first != -1) y += cur.second - cur.first;

                res += y * (x - px);
                res %= MOD;
            }

            if(type == OPEN){
                activey.insert({y1, y2});
            }
            else{
                assert(type == CLOSE);
                assert(activey.count({y1, y2}));
                activey.erase(activey.find(make_pair(y1, y2)));
            }

            px = x;
        }
        return res;
    }
};


int main() {

    vector<vector<int>> rec1 = {
            {0,0,2,2},{1,0,2,3},{1,0,3,1}
    };
    cout << Solution().rectangleArea(rec1) << endl;
    // 6

    vector<vector<int>> rec2 = {
            {0,0,1000000000,1000000000}
    };
    cout << Solution().rectangleArea(rec2) << endl;
    // 49

    vector<vector<int>> rec3 = {
            {25,20,70,27},{68,80,79,100},{37,41,66,76}
    };
    cout << Solution().rectangleArea(rec3) << endl;
    // 1550

    vector<vector<int>> rec4 = {
            {0,0,3,3},{2,0,5,3},{1,1,4,4}
    };
    cout << Solution().rectangleArea(rec4) << endl;
    // 18

    vector<vector<int>> rec5 = {
            {22,24,67,34},{23,18,39,41},{10,63,80,98}
    };
    cout << Solution().rectangleArea(rec5) << endl;
    // 3108

    return 0;
}
