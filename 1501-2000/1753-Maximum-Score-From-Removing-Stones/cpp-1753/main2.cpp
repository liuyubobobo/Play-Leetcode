/// Source : https://leetcode.com/problems/maximum-score-from-removing-stones/
/// Author : liuyubobobo
/// Time   : 2021-02-06

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// Greedy + Priority Queue
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
            res += 1;
            pq.push(x - 1), pq.push(y - 1);
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
