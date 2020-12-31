/// Source : https://leetcode.com/problems/add-binary/description/
/// Author : liuyubobobo
/// Time   : 2018-06-03

#include <iostream>

using namespace std;

/// Simulation
/// Time Complexity: O(max(len(a), len(b)))
/// Space Complexity: O(1)
class Solution {
public:
    string addBinary(string a, string b) {

        string res = a.size() > b.size() ? a : b;
        string adder = a.size() > b.size() ? b : a;

        int index = res.size() - 1;
        for(int i = adder.size() - 1 ; i >= 0 ; i --){
            res[index] += adder[i] - '0';
            index --;
        }

        for(int i = res.size() - 1 ; i > 0 ; i --)
            if(res[i] > '1'){
                res[i - 1] += 1;
                res[i] = '0' + (res[i] - '0') % 2;
            }

        if(res[0] > '1'){
            res[0] = '0' + (res[0] - '0') % 2;
            res = '1' + res;
        }
        return res;
    }
};


int main() {

    cout << Solution().addBinary("11", "1") << endl;
    cout << Solution().addBinary("1010", "1011") << endl;

    return 0;
}