/// Source : https://leetcode.cn/problems/get-kth-magic-number-lcci/
/// Author : liuyubobobo
/// Time   : 2022-09-27

#include <iostream>
#include <queue>
#include <set>

using namespace std;


/// Using PQ
/// Time Complexity: O(klogk)
/// Space Complexity: O(k)
class Solution {
public:
    int getKthMagicNumber(int k) {

        priority_queue<long long, vector<long long>, greater<long long>> pq;
        pq.push(1);

        set<long long> visited;

        long long res = -1;
        while(k){
            res = pq.top(); pq.pop();
            if(visited.count(res)) continue;

            visited.insert(res);

            k --;
            pq.push(res * 3);
            pq.push(res * 5);
            pq.push(res * 7);
        }
        return res;
    }
};


int main() {

    cout << Solution().getKthMagicNumber(2) << '\n';
    // 3

    return 0;
}
