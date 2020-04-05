/// Source : https://leetcode.com/problems/count-largest-group/
/// Author : liuyubobobo
/// Time   : 2020-04-04

#include <iostream>
#include <map>

using namespace std;


/// Using Hash Map
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int countLargestGroup(int n) {

        map<int, int> group;
        for(int i = 1; i <= n; i ++)
            group[sum(i)] ++;

        map<int, int> res;
        for(const pair<int, int>& p: group)
            res[p.second] ++;

        return res.rbegin()->second;
    }

private:
    int sum(int x){
        int res = 0;
        while(x) res += x % 10, x /= 10;
        return res;
    }
};


int main() {

    cout << Solution().countLargestGroup(13) << endl;
    // 4

    return 0;
}
