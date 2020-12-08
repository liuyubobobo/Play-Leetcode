/// Source : https://leetcode.com/problems/split-array-into-fibonacci-sequence/submissions/
/// Author : liuyubobobo
/// Time   : 2020-12-08

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

private:
    const long long LIMIT = 2147483647ll;

public:
    vector<int> splitIntoFibonacci(const string& s) {

        for(int sz1 = 1; sz1 <= 10;  sz1 ++)
            for(int sz2 = 1; sz2 <= 10; sz2 ++){
                vector<int> res = ok(s, sz1, sz2);
                if(!res.empty()) return res;
            }

        return {};
    }

private:
    vector<int> ok(const string& s, int sz1, int sz2){

        if(sz1 + sz2 >= s.size()) return {};

        if(s[0] == '0' && sz1 > 1) return {};
        long long a = atoll(s.substr(0, sz1).c_str());
        if(a > LIMIT) return {};

        if(s[sz1] == '0' && sz2 > 1) return {};
        long long b = atoll(s.substr(sz1, sz2).c_str());
        if(b > LIMIT) return {};

        vector<int> res = {(int)a, (int)b};
        int p = sz1 + sz2;
        while(p < s.size()){
            long long c = a + b;
            if(c > LIMIT) return {};

            string cstr = to_string(c);
            int next = s.find(cstr, p);
            if(next != p) return {};

            a = b, b = c;
            res.push_back((int) c);
            p +=cstr.size();
        }
        return res;
    };
};


int main() {

    return 0;
}
