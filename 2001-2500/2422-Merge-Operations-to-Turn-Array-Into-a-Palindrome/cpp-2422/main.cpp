/// Source : https://leetcode.com/problems/merge-operations-to-turn-array-into-a-palindrome/
/// Author : liuyubobobo
/// Time   : 2022-09-30

#include <iostream>
#include <vector>
#include <deque>

using namespace std;


/// Greedy and using deque
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int minimumOperations(vector<int>& nums) {

        deque<long long> q;
        for(int e: nums) q.push_back(e);

        int res = 0;
        while(q.size() > 1){
            long long front = q.front(), tail = q.back();
            if(front == tail) q.pop_front(), q.pop_back();
            else if(front < tail){
                q.pop_front();
                long long x = q.front(); q.pop_front();
                q.push_front(x + front);
                res ++;
            }
            else{
                q.pop_back();
                long long x = q.back(); q.pop_back();
                q.push_back(x + tail);
                res ++;
            }
        }
        return res;
    }
};


int main() {

    return 0;
}
