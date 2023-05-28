/// Source : https://leetcode.com/problems/minimum-cost-to-make-all-characters-equal/description/
/// Author : liuyubobobo
/// Time   : 2023-05-27

#include <iostream>
#include <deque>

using namespace std;


/// Greedy
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    long long minimumCost(string s) {

        int n = s.size();
        deque<pair<int, int>> pos0, pos1;
        for(int start = 0, i = 1; i <= n; i ++){
            if(i == n || s[i] != s[start]){
                int a = start, b = i - 1;
                if(s[start] == '0') pos0.push_back({a, b});
                else pos1.push_back({a, b});
                start = i;
            }
        }
        return min(solve(n, pos0), solve(n, pos1));
    }

private:
    long long solve(int n, deque<pair<int, int>>& pos){

        long long res = 0;
        while(!pos.empty()){
            int tres1 = pos.front().second + 1 + pos.front().first;
            int tres2 = (n - pos.back().first) + (n - (pos.back().second + 1));

            if(tres1 < tres2) res += tres1, pos.pop_front();
            else res += tres2, pos.pop_back();
        }
        return res;
    }
};


int main() {

    cout << Solution().minimumCost("0011") << '\n';
    // 2

    cout << Solution().minimumCost("010101") << '\n';
    // 9

    return 0;
}
