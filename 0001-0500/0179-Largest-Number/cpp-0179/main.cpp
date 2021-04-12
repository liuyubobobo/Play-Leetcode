/// Source : https://leetcode.com/problems/largest-number/
/// Author : liuyubobobo
/// Time   : 2021-04-12

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


/// Sorting
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    string largestNumber(vector<int>& nums) {

        vector<string> v;
        for(int num: nums) v.push_back(to_string(num));

        sort(v.begin(), v.end(), [](const string& a, const string& b){

            return a + b > b + a;
        });

        string res = "";
        for(const string& s: v) res += s;

        while(res[0] == '0') res = res.substr(1);
        return res.size() ? res : "0";
    }
};


int main() {

    return 0;
}
