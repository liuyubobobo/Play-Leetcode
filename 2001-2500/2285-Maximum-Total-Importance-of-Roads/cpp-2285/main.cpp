/// Source : https://leetcode.com/problems/maximum-total-importance-of-roads/
/// Author : liuyubobobo
/// Time   : 2022-05-28

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Greedy
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {

        vector<long long> degrees(n, 0);
        for(const vector<int>& road: roads)
            degrees[road[0]] ++, degrees[road[1]] ++;

        sort(degrees.begin(), degrees.end(), greater<long long>());
        long long res = 0;
        for(int i = 0; i < n; i ++)
            res += degrees[i] * (n - i);
        return res;
    }
};

int main() {

    return 0;
}
