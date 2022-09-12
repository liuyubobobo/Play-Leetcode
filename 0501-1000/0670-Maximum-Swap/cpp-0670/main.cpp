/// Source : https://leetcode.com/problems/maximum-swap/
/// Author : liuyubobobo
/// Time   : 2022-09-12

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O((log(num))^2)
/// Space Complexity: O(log(num))
class Solution {
public:
    int maximumSwap(int num) {

        if(num < 10) return num;

        string num_s = to_string(num);
        for(int i = 0; i < num_s.size(); i ++)
            for(int j = i + 1; j < num_s.size(); j ++){
                swap(num_s[i], num_s[j]);
                int x = atoi(num_s.c_str());
                num = max(num, x);
                swap(num_s[i], num_s[j]);
            }
        return num;
    }
};


int main() {

    return 0;
}
