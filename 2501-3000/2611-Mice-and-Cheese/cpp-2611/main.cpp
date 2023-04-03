/// Source : https://leetcode.com/problems/mice-and-cheese/description/
/// Author : liuyubobobo
/// Time   : 2023-04-02

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <queue>

using namespace std;


/// Using PQ
/// Time Complexity: O(nlogn + klogn)
/// Space Complexity: O(n)
class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {

        int res = accumulate(reward2.begin(), reward2.end(), 0);

        int n = reward1.size();
        priority_queue<int> pq;
        for(int i = 0; i < n; i++)
            pq.push(reward1[i] - reward2[i]);

        for(int i = 0; i < k; i++) {
            int t = pq.top(); pq.pop();
            res += t;
        }
        return res;
    }
};


int main() {

    return 0;
}
