/// Source : https://leetcode.com/problems/reconstruct-a-2-row-binary-matrix/description/
/// Author : liuyubobobo
/// Time   : 2023-06-29

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// Using PQ
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {

        int n = colsum.size();

        vector<vector<int>> res(2, vector<int>(n, 0));
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < n; i ++)
            if(colsum[i]) pq.push({colsum[i], i});

        while(!pq.empty()){
            int sum = pq.top().first, index = pq.top().second;
            pq.pop();

            if(sum == 2){
                res[0][index] = res[1][index] = 1;
                upper --, lower --;
                if(upper < 0 || lower < 0) return vector<vector<int>>(0);
            }
            else{
                if(upper)
                    res[0][index] = 1, upper --;
                else if(lower)
                    res[1][index] = 1, lower --;
                else return vector<vector<int>>(0);
            }
        }

        if(upper || lower) return vector<vector<int>>(0);
        return res;
    }
};


int main() {

    vector<int> colsum1 = {2,1,2,0,1,0,1,2,0,1};
    Solution().reconstructMatrix(5, 5, colsum1);

    return 0;
}
