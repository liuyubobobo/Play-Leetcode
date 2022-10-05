/// Source : https://leetcode.cn/contest/hhrc2022/problems/o0Ma2v/
/// Author : liuyubobobo
/// Time   : 2022-10-03

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// Using PQ
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int lastMaterial(vector<int>& material) {

        priority_queue<int> pq;
        for(int e: material) pq.push(e);

        while(pq.size() >= 2){
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            if(a - b) pq.push(a - b);
        }
        return pq.empty() ? 0 : pq.top();
    }
};

int main() {

    return 0;
}
