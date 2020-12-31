/// Source : https://leetcode.com/problems/utf-8-validation/
/// Author : liuyubobobo
/// Time   : 2018-10-31

#include <iostream>
#include <vector>

using namespace std;


/// Using Binary String
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    bool validUtf8(vector<int>& data) {

        for(int i = 0; i < data.size(); ){
            string byte = get_binary_str(data[i]);
            if(byte[0] == '0')
                i ++;
            else if(byte.substr(0, 3) == "110"){
                if(i + 1 >= data.size())
                    return false;
                if(!is10(data[i + 1]))
                    return false;
                i += 2;
            }
            else if(byte.substr(0, 4) == "1110"){
                if(i + 2 >= data.size())
                    return false;
                for(int j = 1; j <= 2; j ++)
                    if(!is10(data[i + j]))
                        return false;
                i += 3;
            }
            else if(byte.substr(0, 5) == "11110"){
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
        string s = get_binary_str(byte);
        return s[0] == '1' && s[1] == '0';
    }

    string get_binary_str(int data){
        string ret = "";
        for(int i = 0; i < 8; i ++){
            ret += '0' + data % 2;
            data /= 2;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};


int main() {

    vector<int> data1 = {197, 130, 1};
    // 11000101 10000010 00000001
    cout << Solution().validUtf8(data1) << endl;
    // true

    return 0;
}