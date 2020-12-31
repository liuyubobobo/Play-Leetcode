/// Source : https://leetcode.com/problems/maximum-number-of-eaten-apples/
/// Author : liuyubobobo
/// Time   : 2020-12-29

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// Using Priority Queue
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {

        int n = apples.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int res = 0;
        for(int i = 0; i < n; i ++){
            pq.push({i + days[i], apples[i]});
            while(!pq.empty() && pq.top().first <= i) pq.pop();

            if(!pq.empty()){
                pair<int, int> p = pq.top();
                pq.pop();
                p.second --;
                res ++;
                if(p.second) pq.push(p);
            }
        }

        int d = n;
        while(!pq.empty()){
            int endday = pq.top().first, cnt = pq.top().first;
            pq.pop();
            if(endday <= d) continue;

            int c = min(cnt, endday - d);
            res += c;
            d += c;
        }
        return res;
    }
};


int main() {

    vector<int> apples1 = {1, 2, 3, 5, 2}, days1 = {3, 2, 1, 4, 2};
    cout << Solution().eatenApples(apples1, days1) << endl;
    // 7

    vector<int> apples2 = {3,0,0,0,0,2}, days2 = {3,0,0,0,0,2};
    cout << Solution().eatenApples(apples2, days2) << endl;
    // 5

    vector<int> apples3 = {2, 2, 2}, days3 = {6, 4, 2};
    cout << Solution().eatenApples(apples3, days3) << endl;
    // 6

    return 0;
}
