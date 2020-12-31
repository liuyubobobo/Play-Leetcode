/// Source : https://leetcode.com/problems/longest-arithmetic-sequence/
/// Author : liuyubobobo
/// Time   : 2019-04-13

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// HashMap + Bianry Search
/// Time Complexity: O(n^2*logn)
/// Space Complexity: O(n^2)
class Solution {

public:
    int longestArithSeqLength(vector<int>& A) {

        unordered_map<int, vector<int>> map;
        for(int i = 0; i < A.size(); i ++)
            map[A[i]].push_back(i);

        int res = 2;
        for(int i = 0; i < A.size(); i ++)
            for(int j = i + 1; j < A.size(); j ++)
                res = max(res, length(j, A[j], A[j] - A[i], map));
        return res;
    }

private:
    int length(int pos, int cur, int diff, unordered_map<int, vector<int>>& map){

        int res = 2;
        while(true){
            cur += diff;
            vector<int>::iterator iter = upper_bound(map[cur].begin(), map[cur].end(), pos);
            if(iter == map[cur].end()) break;

            res ++;
            pos = *iter;
        }
        return res;
    }
};


int main() {

    vector<int> A1 = {3, 6, 9, 12};
    cout << Solution().longestArithSeqLength(A1) << endl; // 4

    vector<int> A2 = {9, 4, 7, 2, 10};
    cout << Solution().longestArithSeqLength(A2) << endl; // 3

    vector<int> A3 = {20,1,15,3,10,5,8};
    cout << Solution().longestArithSeqLength(A3) << endl; // 4

    return 0;
}