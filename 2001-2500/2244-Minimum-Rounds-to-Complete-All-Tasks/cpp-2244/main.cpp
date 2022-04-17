/// Source : https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/
/// Author : liuyubobobo
/// Time   : 2022-04-16

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {

        map<int, int> f;
        for(int e: tasks) f[e] ++;

        int res = 0;
        for(const pair<int, int>& p: f){
            if(p.second == 1) return -1;
            res += (p.second / 3 + !!(p.second % 3));
        }
        return res;
    }
};


int main() {

    return 0;
}
