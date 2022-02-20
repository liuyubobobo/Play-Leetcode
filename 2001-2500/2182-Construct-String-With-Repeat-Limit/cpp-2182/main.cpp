/// Source : https://leetcode.com/problems/construct-string-with-repeat-limit/
/// Author : liuyubobobo
/// Time   : 2022-02-19

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// Greedy
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {

        vector<int> f(26, 0);
        for(char c: s) f[c - 'a'] ++;

        string res = "";
        while(true){
            pair<int, int> p = get_first_and_second(f);
            int first = p.first, second = p.second;
            if(first == -1 || first == res.back() - 'a') break;

            int k = min(f[first], repeatLimit);
            res += string(k, 'a' + first);
            f[first] -= k;

            if(f[first] && second != -1){
                res += (char)('a' + second);
                f[second] -= 1;
            }
        }
        return res;
    }

private:
    pair<int, int> get_first_and_second(const vector<int>& f){

        int first = -1;
        for(int i = 25; i >= 0; i --)
            if(f[i]){
                first = i;
                break;
            }

        int second = -1;
        for(int i = first - 1; i >= 0; i --)
            if(f[i]){
                second = i;
                break;
            }
        return {first, second};
    }
};

int main() {

    cout << Solution().repeatLimitedString("cczazcc", 3) << endl;
    // zzcccac

    cout << Solution().repeatLimitedString("aababab", 2) << endl;
    // bbabaa

    return 0;
}
