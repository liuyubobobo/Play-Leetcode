/// Source : https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/
/// Author : liuyubobobo
/// Time   : 2019-02-15

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Using map to simulate priority queue
/// Time Complexity: O(t * logn)
/// Space Complexity: O(n)
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {

        map<pair<int, int>, int> q;
        for(const vector<int>& e: events)
            q[make_pair(e[0], e[1])] ++;

        int res = 0;
        for(int i = 0; i <= 100000 && !q.empty(); i ++){

            map<pair<int, int>, int>::iterator iter = q.begin();
            if(i >= iter->first.first && i <= iter->first.second){
                res ++;
                iter->second --;
                if(iter->second == 0) q.erase(iter);

                vector<pair<int, int>> v;
                for(map<pair<int, int>, int>::iterator iter = q.begin(); iter != q.end(); iter ++)
                    if(iter->first.first <= i)
                        v.push_back(iter->first);
                    else
                        break;

                for(const pair<int, int>& p: v){
                    int num = q[p];
                    q.erase(p);
                    if(i + 1 <= p.second){
                        pair<int, int> newp = make_pair(i + 1, p.second);
                        if(q.count(newp)) q[newp] += num;
                        else q[newp] = num;
                    }
                }
            }
        }
        return res;
    }
};


int main() {

    vector<vector<int>> events1 = {{1, 2}, {2, 3}, {3, 4}, {1, 2}};
    cout << Solution().maxEvents(events1) << endl;
    // 4

    vector<vector<int>> events2 = {{1, 4}, {4, 4}, {2, 2}, {3, 4}, {1, 1}};
    cout << Solution().maxEvents(events2) << endl;
    // 4

    vector<vector<int>> events3 = {{1, 5}, {1, 5}, {1, 5}, {2, 3}, {2, 3}};
    cout << Solution().maxEvents(events3) << endl;
    // 5

    vector<vector<int>> events4 = {{7, 11}, {7, 11}, {7, 11}, {9, 10}, {9, 11}};
    cout << Solution().maxEvents(events4) << endl;
    // 5

    return 0;
}
