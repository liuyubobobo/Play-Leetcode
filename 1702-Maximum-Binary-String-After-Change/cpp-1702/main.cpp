/// Source : https://leetcode.com/problems/maximum-binary-string-after-change/
/// Author : liuyubobobo
/// Time   : 2020-12-26

#include <iostream>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    string maximumBinaryString(string binary) {

        int i;
        for(i = 0; i + 1 < binary.size(); i ++)
            if(binary[i] == '0' && binary[i + 1] == '0')
                binary[i] = '1';
            else break;

        while(i < binary.size() && binary[i] == '1') i ++;
        if(i == binary.size()) return binary;

        int zero = 0;
        for(int j = i + 1; j < binary.size(); j ++)
            zero += binary[j] == '0';

        return string(i + zero, '1') + "0" + string(binary.size() - (i + zero + 1), '1');
    }
};


int main() {

    string binary1 = "000110";
    cout << Solution().maximumBinaryString(binary1) << endl;
    // 111011

    string binary2 = "01";
    cout << Solution().maximumBinaryString(binary2) << endl;
    // 01

    string binary3 = "11";
    cout << Solution().maximumBinaryString(binary3) << endl;
    // 11

    return 0;
}
