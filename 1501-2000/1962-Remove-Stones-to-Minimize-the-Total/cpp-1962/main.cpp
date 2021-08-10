/// Source : https://leetcode.com/problems/remove-stones-to-minimize-the-total/
/// Author : liuyubobobo
/// Time   : 2021-08-09

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// Priority Queue
/// Time Complexity: O(k * logn)
/// Space Complexity: O(n)
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {

        priority_queue<int> pq;
        for(int pile: piles) pq.push(pile);

        for(int i = 0; i < k && !pq.empty(); i ++){
            int e = pq.top(); pq.pop();
            pq.push(e - e / 2);
        }

        int res = 0;
        while(!pq.empty()){
            res += pq.top(); pq.pop();
        }
        return res;
    }
};

int main() {

    vector<int> piles1 = {5, 4, 9};
    cout << Solution().minStoneSum(piles1, 2) << endl;
    // 12

    vector<int> piles2 = {4, 3, 6, 7};
    cout << Solution().minStoneSum(piles2, 3) << endl;
    // 12

    return 0;
}
