/// Source : https://leetcode.com/problems/binary-watch/
/// Author : liuyubobobo
/// Time   : 2020-02-15

#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;


/// Brute Force
/// Time Complexity: O(2^10)
/// Space Complexity: O(1)
class Solution {

public:
    vector<string> readBinaryWatch(int num) {

        vector<string> res;
        for(int i = 0; i < (1 << 10); i ++)
            if(num_of_ones(i) == num){
                int m = i & 0b111111, h = i >> 6;
                if(h < 12 && m < 60){
                    stringstream ss;
                    ss << h << ":" << setfill('0') << setw(2) << m;
                    res.push_back(ss.str());
                }
            }
        return res;
    }

private:
    int num_of_ones(int x){
        int res = 0;
        while(x) res += x % 2, x /= 2;
        return res;
    }
};


int main() {

    return 0;
}
