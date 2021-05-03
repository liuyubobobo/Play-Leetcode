/// Source : https://leetcode.com/problems/splitting-a-string-into-descending-consecutive-values/
/// Author : liuyubobobo
/// Time   : 2021-05-03

#include <iostream>
#include <vector>

using namespace std;


/// Enumerating First String
/// Time Complexity: O(|s|^2)
/// Space Complexity: O(|s|)
class Solution {
public:
    bool splitString(string s) {

        for(int end = 0; end + 1 < s.size(); end ++){
            string first = s.substr(0, end + 1);
            long long a = get_long(first);
            if(a < 0) break;

            if(ok(s, end + 1, a - 1ll))
                return true;
        }
        return false;
    }

private:
    long long get_long(const string& s){

        long long a = 0ll;
        for(int i = 0; i < s.size(); i ++){
            if((LONG_LONG_MAX - (s[i] - '0')) / 10ll < a) return -1;
            a = a * 10ll + (s[i] - '0');
        }
        return a;
    }

    bool ok(const string& s, int start, long long t){

        if(start >= s.size()) return true;

        long long cur = 0ll;
        int i = start;
        for(; i < s.size(); i ++){
            cur = cur * 10ll + (s[i] - '0');
            if(cur > t) return false;
            if(cur == t && ok(s, i + 1, t - 1ll)) return true;
        }
        return false;
    }
};


int main() {

    cout << Solution().splitString("1234") << endl;
    // 0

    cout << Solution().splitString("050043") << endl;
    // 1

    cout << Solution().splitString("9080701") << endl;
    // 0

    cout << Solution().splitString("10009998") << endl;
    // 1

    cout << Solution().splitString("810809808807806805") << endl;
    // 1

    cout << Solution().splitString("200100") << endl;
    // 1

    return 0;
}
