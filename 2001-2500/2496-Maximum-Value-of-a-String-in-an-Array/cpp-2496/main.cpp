/// Source : https://leetcode.com/problems/frog-jump-ii/description/
/// Author : liuyubobobo
/// Time   : 2023-01-02

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n * |s|)
/// Space Complexity: O(1)
class Solution {
public:
    int maximumValue(vector<string>& strs) {

        int res = 0;
        for(const string& s: strs)
            res = max(res, get_value(s));
        return res;
    }

private:
    int get_value(const string& s){

        if(all_digits(s)){
            long long res = 0;
            for(char c: s)
                res = res * 10 + (c - '0');
            return res;
        }
        return s.size();
    }

    bool all_digits(const string& s){

        for(char c: s)
            if(!isdigit(c)) return false;
        return true;
    }
};


int main() {

    return 0;
}
