/// Source : https://leetcode.com/problems/last-stone-weight/
/// Author : liuyubobobo
/// Time   : 2019-05-19

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// Using Priority Queue
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int> pq;
        for(int e: stones) pq.push(e);

        while(pq.size() > 1){
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            pq.push(a - b);
        }
        return pq.size() == 1 ? pq.top() : 0;
    }
};


int main() {

    vector<int> stones = {2,7,4,1,8,1};
    cout << Solution().lastStoneWeight(stones) << endl;

    return 0;
}