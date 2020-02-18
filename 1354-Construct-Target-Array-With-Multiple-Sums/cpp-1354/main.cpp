/// Source : https://leetcode.com/problems/construct-target-array-with-multiple-sums/
/// Author : liuyubobobo
/// Time   : 2019-02-15

#include <iostream>
#include <vector>
#include <map>
#include <numeric>

using namespace std;


/// Using map to simulate priority queue
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    bool isPossible(vector<int>& target) {

        map<long long, int> q;
        for(int e: target) q[-e]++;

        long long sum = accumulate(target.begin(), target.end(), 0ll);
        while(q.begin()->first != -1ll){
            long long k = q.begin()->first;
            long long v = -k;

            long long leftsum = sum - v;
            if(v <= leftsum) return false;
            else{
                q[k] --;
                if(q[k] == 0ll) q.erase(k);
                q[- v % leftsum] ++;
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
