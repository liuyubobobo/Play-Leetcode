/// Source : https://leetcode.com/problems/split-with-minimum-sum/
/// Author : liuyubobobo
/// Time   : 2023-03-04

#include <iostream>
#include <vector>

using namespace std;


/// Greedy
/// Time Complexity: O(log(num))
/// Space Complexity: O(log(num))
class Solution {
public:
    int splitNum(int num) {

        vector<int> f(10, 0);
        while(num) f[num % 10] ++, num /= 10;

        vector<string> res(2, "");
        for(int e = 1, index = 0; e <= 9; e ++){
            while(f[e] --) res[index] += to_string(e), index ^= 1;
        }

        for(int index = 0; index < 2; index ++)
            if(res[index] == "") res[index] = "0";

        int a = stoi(res[0]), b = stoi(res[1]);
        return a + b;
    }
};


int main() {

    return 0;
}
