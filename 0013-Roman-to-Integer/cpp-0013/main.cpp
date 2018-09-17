/// Source : https://leetcode.com/problems/roman-to-integer/description/
/// Author : liuyubobobo
/// Time   : 2018-09-17

#include <iostream>
#include <unordered_map>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int romanToInt(string s) {

        unordered_map<char, int> map = {
                {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

        int res = 0;
        for(int i = 0; i < s.size(); i ++)
            if(i + 1 < s.size() && map[s[i]] < map[s[i + 1]]){
                res += map[s[i + 1]] - map[s[i]];
                i ++;
            }
            else
                res += map[s[i]];

        return res;
    }
};


int main() {

    return 0;
}