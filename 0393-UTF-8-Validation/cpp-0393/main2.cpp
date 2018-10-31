/// Source : https://leetcode.com/problems/utf-8-validation/
/// Author : liuyubobobo
/// Time   : 2018-10-31

#include <iostream>
#include <vector>

using namespace std;


/// Using Bit Manipulation
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    bool validUtf8(vector<int>& data) {

        for(int i = 0; i < data.size(); ){
            int byte = data[i] & 0b11111111;
            if(!(byte & 0b10000000))
                i ++;
            else if((byte & 0b11000000) == 0b11000000 && !(byte & 0b00100000)){
                if(i + 1 >= data.size())
                    return false;
                if(!is10(data[i + 1]))
                    return false;
                i += 2;
            }
            else if((byte & 0b11100000) == 0b11100000 && !(byte & 0b00010000)){
                if(i + 2 >= data.size())
                    return false;
                for(int j = 1; j <= 2; j ++)
                    if(!is10(data[i + j]))
                        return false;
                i += 3;
            }
            else if((byte & 0b11110000) == 0b11110000 && !(byte & 0b00001000)){
                if(i + 3 >= data.size())
                    return false;
                for(int j = 1; j <= 3; j ++)
                    if(!is10(data[i + j]))
                        return false;
                i += 4;
            }
            else
                return false;
        }

        return true;
    }

private:
    bool is10(int byte){
        return (byte & 0b10000000) && !(byte & 0b01000000);
    }
};


int main() {

    vector<int> data1 = {197, 130, 1};
    // 11000101 10000010 00000001
    cout << Solution().validUtf8(data1) << endl;
    // true

    return 0;
}