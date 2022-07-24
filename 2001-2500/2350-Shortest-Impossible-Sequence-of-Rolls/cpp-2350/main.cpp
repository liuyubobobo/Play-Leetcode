/// Source : https://leetcode.com/problems/shortest-impossible-sequence-of-rolls/
/// Author : liuyubobobo
/// Time   : 2022-07-23

#include <iostream>
#include <vector>

using namespace std;


/// Greedy
/// Time Complexity: O(n + k)
/// Space Compelxity: O(k)
class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {

        vector<bool> used(k + 1, false);
        int cnt = 0, res = 0;
        for(int e: rolls){
            if(!used[e]){
                used[e] = true;
                cnt ++;
                if(cnt == k){
                    res ++;
                    used.assign(k + 1, false);
                    cnt = 0;
                }
            }
        }
        return res;
    }
};


int main() {

    return 0;
}
