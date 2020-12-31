/// Source : https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/
/// Author : liuyubobobo
/// Time   : 2020-09-26

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>

using namespace std;


/// Brute Force with Optimization
/// Time Complexity: O((n + r)* 2^r)
/// Space Complexity: O(1)
class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {

        int res = 0;
        vector<int> indegrees(n, 0), outdegrees(n, 0);
        for(const vector<int>& e: requests)
            if(e[0] != e[1]) outdegrees[e[0]] ++, indegrees[e[1]] ++;
            else res ++;

        vector<vector<int>> rv;
        for(const vector<int>& request: requests){
            int a = request[0], b = request[1];
            if(a == b || !indegrees[a] || !indegrees[b] || !outdegrees[a] || !outdegrees[b])
                continue;
            rv.push_back(request);
        }

        int r = rv.size(), t = 0;
        for(int i = 0; i < (1 << r); i ++)
            t = max(t, tryRequest(n, rv, i));
        return res + t;
    }

private:
    int tryRequest(int n, const vector<vector<int>>& requests, int state){

        vector<int> in(n, 0), out(n, 0);
        int index = 0, res = 0;
        while(state){
            if(state & 1){
                out[requests[index][0]] ++;
                in[requests[index][1]] ++;
                res ++;
            }

            state >>= 1, index ++;
        }

        if(in != out) return -1;
        return res;
    }
};


int main() {

    vector<vector<int>> r1 = {{0,1},{1,0},{0,1},{1,2},{2,0},{3,4}};
    cout << Solution().maximumRequests(5, r1) << endl;
    // 5

    vector<vector<int>> r2 = {{0,0},{1,2},{2,1}};
    cout << Solution().maximumRequests(3, r2) << endl;
    // 3

    vector<vector<int>> r3 = {{0,3},{3,1},{1,2},{2,0}};
    cout << Solution().maximumRequests(4, r3) << endl;
    // 4

    vector<vector<int>> r4 = {{1,2},{1,2},{2,2},{0,2},{2,1},{1,1},{1,2}};
    cout << Solution().maximumRequests(3, r4) << endl;
    // 4

    vector<vector<int>> r5 ={{0,3},{3,3},{3,1},{0,1},{3,2},{2,2},{2,0},{1,0},{1,0},{1,2},{2,0},{1,3},{3,0}};
    cout << Solution().maximumRequests(4, r5) << endl;
    // 10

    return 0;
}
