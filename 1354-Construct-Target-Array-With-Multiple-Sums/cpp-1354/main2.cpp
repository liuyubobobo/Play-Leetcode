/// Source : https://leetcode.com/problems/construct-target-array-with-multiple-sums/
/// Author : liuyubobobo
/// Time   : 2019-02-17

#include <iostream>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;


/// Using priority queue
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    bool isPossible(vector<int>& target) {

        if(target.size() == 2 && (target[0] == 1 || target[1] == 1)) return true;

        priority_queue<long long> pq;
        for(int e: target) pq.push(e);

        long long sum = accumulate(target.begin(), target.end(), 0ll);
        while(!pq.empty() && pq.top() != 1ll){
            long long v = pq.top();

            long long leftsum = sum - v;
            if(v <= leftsum || leftsum == 0) return false;
            else{
                pq.pop();

                pq.push(v % leftsum);
                sum -= v - v % leftsum;
            }
        }
        return true;
    }
};


int main() {

    vector<int> v1 = {9, 3, 5};
    cout << Solution().isPossible(v1) << endl;
    // 1

    vector<int> v2 = {1, 1, 1, 2};
    cout << Solution().isPossible(v2) << endl;
    // 0

    vector<int> v3 = {8, 5};
    cout << Solution().isPossible(v3) << endl;
    // 1

    vector<int> v4 = {1, 1000};
    cout << Solution().isPossible(v4) << endl;
    // 1

    return 0;
}
