/// Source : https://leetcode.com/problems/baseball-game/
/// Author : liuyubobobo
/// Time   : 2022-03-25

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Using Stack
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int calPoints(vector<string>& ops) {

        vector<int> v;
        for(const string& e: ops)
            if(isdigit(e[0]) || e[0] == '-'){
                int x = atoi(e.c_str());
                v.push_back(x);
            }
            else if(e == "+")
                v.push_back(v.back() + v[v.size() - 2]);
            else if(e == "D")
                v.push_back(2 * v.back());
            else
                v.pop_back();

        return accumulate(v.begin(), v.end(), 0);
    }
};


int main() {

    return 0;
}
