/// Source : https://leetcode.com/problems/additive-number/
/// Author : liuyubobobo
/// Time   : 2022-01-09

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    bool isAdditiveNumber(string num) {

        int n = num.size();
        for(int len1 = 1; len1 <= 17 && len1 + 2 <= n; len1 ++)
            for(int len2 = 1; len2 <= 17 && len1 + len2 + 1 <= n; len2 ++)
                if(ok(n, num, len1, len2)) return true;
        return false;
    }

private:
    bool ok(int n, const string& num, int len1, int len2){

        if(num[0] == '0' && len1 > 1) return false;
        if(num[len1] == '0' && len2 > 1) return false;

        vector<long long> v;
        v.push_back(atoll(num.substr(0, len1).c_str()));
        v.push_back(atoll(num.substr(len1, len2).c_str()));

        int cur_index = len1 + len2;
        while(cur_index < n){

            long long next = v[v.size() - 2] + v[v.size() - 1];
            string next_s = to_string(next);
            int next_s_len = next_s.size();
            if(num.substr(cur_index, next_s_len) == next_s)
                cur_index += next_s_len;
            else
                return false;
            v.push_back(next);
        }
        return true;
    }
};


int main() {

    cout << Solution().isAdditiveNumber("112358") << endl;
    // 1

    cout << Solution().isAdditiveNumber("199100199") << endl;
    // 1

    cout << Solution().isAdditiveNumber("111") << endl;
    // 0

    cout << Solution().isAdditiveNumber("101") << endl;
    // 1

    return 0;
}
