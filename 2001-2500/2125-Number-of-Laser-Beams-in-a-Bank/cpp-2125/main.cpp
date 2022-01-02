/// Source : https://leetcode.com/problems/number-of-laser-beams-in-a-bank/
/// Author : liuyubobobo
/// Time   : 2022-01-01

#include <iostream>
#include <vector>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(R * C)
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {

        vector<int> data;
        for(const string& s: bank){
            int num = 0;
            for(char c: s) num += c == '1';

            if(num) data.push_back(num);
        }

        int res = 0;
        for(int i = 1; i < data.size(); i ++)
            res += data[i - 1] * data[i];
        return res;
    }
};


int main() {

    return 0;
}
