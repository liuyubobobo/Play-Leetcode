/// Source : https://leetcode.com/problems/maximal-score-after-applying-k-operations/description/
/// Author : liuyubobobo
/// Time   : 2023-01-08

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// PQ
/// Time Complexity: O(klogn)
/// Space Complexity: O(n)
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {

        priority_queue<int> pq;
        for(int e: nums) pq.push(e);

        long long res = 0;
        for(int i = 0; i < k && !pq.empty(); i ++){
            int e = pq.top(); pq.pop();
            res += e;

            e = e / 3 + !!(e % 3);
            if(e) pq.push(e);
        }
        return res;
    }
};


int main() {

    return 0;
}
