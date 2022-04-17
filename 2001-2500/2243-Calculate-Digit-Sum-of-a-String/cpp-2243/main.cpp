/// Source : https://leetcode.com/problems/calculate-digit-sum-of-a-string/
/// Author : liuyubobobo
/// Time   : 2022-04-16

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(|s|)
/// Space Complexity: O(1)
class Solution {
public:
    string digitSum(string s, int k) {

        while(s.size() > k){

            string nexts = "";
            for(int i = 0; i < s.size(); i += k)
                nexts += to_string(sum(s.substr(i, k)));
            s = nexts;
        }
        return s;
    }

private:
    int sum(const string& s){
        int res = 0;
        for(int i = 0; i < s.size(); i ++)
            res += (s[i] - '0');
        return res;
    }
};


int main() {

    return 0;
}
