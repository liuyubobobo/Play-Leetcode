/// Source : https://leetcode.com/problems/cracking-the-safe/
/// Author : liuyubobobo
/// Time   : 2021-07-16

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


/// De Bruijn sequence
/// Time Complexity: O(k^n)
/// Space Complexity: O(n)
class Solution {
public:
    string crackSafe(int n, int k) {

        string res = "";
        if(n == 1){
            for(int i = 0; i < k; i ++)
                res += to_string(i);
            return res;
        }

        vector<int> power = {1};
        for(int i = 1; i <= n; i ++) power.push_back(power[i - 1] * k);

        vector<int> g(power[n - 1], k - 1);
        stack<pair<int, int>> stack;
        stack.push({0, 0});
        while(!stack.empty()){
            if(g[stack.top().first] != -1){
                int u = stack.top().first;
                int next = u;
                next -= next / power[n - 2] * power[n - 2];
                next = next * k + g[u];
                stack.push({next, g[u]});
                g[u] --;
            }
            else{
                res += ('0' + stack.top().second);
                stack.pop();
            }
        }

        while((int)res.size() < power[n] + n - 1) res += "0";
        return res;
    }
};

int main() {

    cout << Solution().crackSafe(2, 3) << endl;

    return 0;
}
