/// Source : https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/
/// Author : liuyubobobo
/// Time   : 2020-09-26

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Brute Force
/// Time Complexity: O((n + r)* 2^r)
/// Space Complexity: O(1)
class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {

        int rnum = requests.size(), res = 0;
        for(int i = 0; i < (1 << rnum); i ++)
            res = max(res, tryRequest(n, requests, i));
        return res;
    }

private:
    int tryRequest(int n, const vector<vector<int>>& requests, int state){

        vector<int> in(n, 0), out(n, 0);
        int index = 0;
        while(state){
            if(state % 2){
                out[requests[index][0]] ++;
                in[requests[index][1]] ++;
            }

            state /= 2;
            index ++;
        }

        for(int i = 0; i < n; i ++)
            if(in[i] != out[i]) return -1;
        return accumulate(in.begin(), in.end(), 0);
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

    return 0;
}
