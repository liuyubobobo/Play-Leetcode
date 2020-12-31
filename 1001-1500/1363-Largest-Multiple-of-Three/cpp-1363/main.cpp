/// Source : https://leetcode.com/problems/largest-multiple-of-three/
/// Author : liuyubobobo
/// Time   : 2020-02-22

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Sorting and Greedy
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {

        vector<vector<int>> mod(3);
        int sum = 0;
        for(int d: digits)
            mod[d % 3].push_back(d), sum += d;

        for(int i = 0; i < 3; i ++)
            sort(mod[i].begin(), mod[i].end(), greater<int>());

        if(sum % 3 == 1){
            if(mod[1].size()) mod[1].pop_back();
            else if(mod[2].size() >= 2) mod[2].pop_back(), mod[2].pop_back();
            else return "";
        }
        else if(sum % 3 == 2){
            if(mod[2].size()) mod[2].pop_back();
            else if(mod[1].size() >= 2) mod[1].pop_back(), mod[1].pop_back();
            else return "";
        }

        vector<int> v;
        for(int i = 0; i < 3; i ++) for(int d: mod[i]) v.push_back(d);
        sort(v.begin(), v.end(), greater<int>());

        string res = "";
        for(int d: v) res += ('0' + d);
        return res[0] == '0' ? "0" : res;
    }
};


int main() {

    return 0;
}
