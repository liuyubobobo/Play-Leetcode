/// Source : https://leetcode.com/problems/splitting-a-string-into-descending-consecutive-values/
/// Author : liuyubobobo
/// Time   : 2021-05-01

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(|s| * 2^|s|)
/// Space Complexity: O(|s|)
class Solution {
public:
    bool splitString(string s) {

        int n = s.size();
        vector<int> bits(n);
        for(int state = 0; state < (1 << n); state ++){
            get_bits(state, bits);

            long long a = -1;
            int cnt = 0, start = 0, i = 1;
            for(; i <= bits.size(); i ++)
                if(i == bits.size() || bits[i] != bits[start]){

                    long long num = get_long(s, start, i);
                    if(num < 0ll) break;

                    if(cnt == 0) a = num;
                    else if(num != a - cnt) break;

                    cnt ++;
                    start = i;
                    i = start;
                }
            if(i == bits.size() + 1 && cnt > 1) return true;
        }
        return false;
    }

private:
    long long get_long(const string& s, int start, int end){

        long long a = 0ll;
        for(int i = start; i < end; i ++){
            if((LONG_LONG_MAX - (s[i] - '0')) / 10ll < a) return -1;
            a = a * 10ll + (s[i] - '0');
        }
        return a;
    }

    void get_bits(int state, vector<int>&  res){

        for(int i = 0; i < res.size(); i ++)
            res[i] = state & 1, state >>= 1;
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

    return 0;
}
