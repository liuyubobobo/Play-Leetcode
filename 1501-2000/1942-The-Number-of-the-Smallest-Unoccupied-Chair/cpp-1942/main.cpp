/// Source : https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/
/// Author : liuyubobobo
/// Time   : 2021-07-24

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Sweep lines
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {

        int n = times.size();
        vector<vector<int>> v; // (time, (-1 leave  or 1 enter)), index
        for(int i = 0; i < n; i ++)
            v.push_back({times[i][0], 1, i}),
            v.push_back({times[i][1], -1, i});

        sort(v.begin(), v.end());

        vector<int> chairs(n, -1);
        set<int> available;
        for(int i = 0; i < n; i ++) available.insert(i);
        for(const vector<int>& p: v){
            int t = p[0], action = p[1], index = p[2];
            if(action == -1){
                assert(chairs[index] != -1 && !available.count(chairs[index]));
                available.insert(chairs[index]);
            }
            else{
                chairs[index] = *available.begin();
                available.erase(available.begin());
            }
        }

        return chairs[targetFriend];
    }
};


int main() {

    return 0;
}
