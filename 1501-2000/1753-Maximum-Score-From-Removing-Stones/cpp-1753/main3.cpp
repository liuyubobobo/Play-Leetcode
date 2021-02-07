/// Source : https://leetcode.com/problems/maximum-score-from-removing-stones/
/// Author : liuyubobobo
/// Time   : 2021-02-06

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// Greedy + Priority Queue + Optimization
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int maximumScore(int a, int b, int c) {

        priority_queue<int> pq;
        pq.push(a), pq.push(b), pq.push(c);
        int res = 0;
        while(true){
            int x= pq.top(); pq.pop();
            int y = pq.top(); pq.pop();
            if(y == 0) break;

            int z = pq.top();
            if(z == 0){
                res += min(x, y);
                break;
            }

            int t = y - (z - 1);
            res += t;
            pq.push(x - t), pq.push(y - t);
        }
        return res;
    }
};


int main() {

    cout << Solution().maximumScore(2, 4, 6) << endl;
    // 6

    cout << Solution().maximumScore(4, 4, 6) << endl;
    // 7

    cout << Solution().maximumScore(1, 8, 8) << endl;
    // 8

    return 0;
}
