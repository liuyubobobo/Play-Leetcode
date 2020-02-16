/// Source : https://leetcode.com/problems/binary-watch/
/// Author : liuyubobobo
/// Time   : 2020-02-15

#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;


/// Backtracking
/// Time Complexity: O(2^10)
/// Space Complexity: O(1)
class Solution {

public:
    vector<string> readBinaryWatch(int num) {

        vector<string> res;
        vector<bool> bits(10, false);
        go(bits, 0, num, res);
        return res;
    }

private:
    void go(vector<bool>& bits, int index, int num, vector<string>& res){

        if(index == 10){
            int h = 0;
            for(int i = 0; i < 4; i ++) h = h * 2 + bits[i];

            int m = 0;
            for(int i = 4; i < 10; i ++) m = m * 2 + bits[i];

            if(h < 12 && m < 60){
                stringstream ss;
                ss << h << ":" << setfill('0') << setw(2) << m;
                res.push_back(ss.str());
            }

            return;
        }

        if(10 - index > num) go(bits, index + 1, num, res);
        if(num){
            bits[index] = true;
            go(bits, index + 1, num - 1, res);
            bits[index] = false;
        }
        return;
    }
};


int main() {

    return 0;
}
