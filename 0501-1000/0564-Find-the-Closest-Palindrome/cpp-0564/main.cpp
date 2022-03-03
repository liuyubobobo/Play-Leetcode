/// Source : https://leetcode.com/problems/find-the-closest-palindrome/
/// Author : liuyubobobo
/// Time   : 2022-03-03

#include <iostream>
#include <vector>
#include <climits>
#include <cassert>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(|n|)
/// Space Complexity: O(|n|)
class Solution {
public:
    string nearestPalindromic(string n) {

        long long num = atoll(n.c_str());

        vector<long long> possible_res;
        get_palindrome_number(n, possible_res);
        get_palindrome_number(to_string(num + 2), possible_res);
        if(num - 2 >= 0)
            get_palindrome_number(to_string(num - 2), possible_res);

        int len = n.size();
        if(len % 2){
            int m = len / 2;
            get_num(num, m, '+', possible_res);
            get_num(num, m, '-', possible_res);
        }
        else{
            int m1 = len / 2 - 1, m2 = len / 2;
            get_num(num, m1, '+', possible_res);
            get_num(num, m1, '-', possible_res);
            get_num(num, m2, '+', possible_res);
            get_num(num, m2, '-', possible_res);
        }

        long long res = -1, best_diff = LONG_LONG_MAX;
        for(long long a: possible_res){
            if(a == num) continue;
            long long diff = abs(a - num);
            if(diff < best_diff) res = a, best_diff = diff;
            else if(diff == best_diff) res = min(res, a);
        }
        assert(res != -1);
        return to_string(res);
    }

private:
    void get_num(long long num, int pos, char type,
                 vector<long long>& possible_res){

        if(type == '+')
            num += (long long)pow(10, pos);
        else{
            num -= (long long)pow(10, pos);
            assert(num >= 0);
        }

        get_palindrome_number(to_string(num), possible_res);
    }

    void get_palindrome_number(const string& n, vector<long long>& possible_res){

        string n1 = n;
        for(int i = 0, j = n1.size() - 1; i < j; i ++, j --)
            n1[i] = n1[j];
        possible_res.push_back(atoll(n1.c_str()));

        string n2 = n;
        for(int i = 0, j = n1.size() - 1; i < j; i ++, j --)
            n2[j] = n2[i];
        possible_res.push_back(atoll(n2.c_str()));
    }
};


int main() {

    cout << Solution().nearestPalindromic("123") << '\n';
    // 121

    cout << Solution().nearestPalindromic("1") << '\n';
    // 0

    cout << Solution().nearestPalindromic("9") << '\n';
    // 8

    cout << Solution().nearestPalindromic("11") << '\n';
    // 9

    return 0;
}
