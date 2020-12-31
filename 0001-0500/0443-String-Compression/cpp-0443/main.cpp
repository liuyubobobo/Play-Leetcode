/// Source : https://leetcode.com/problems/string-compression/description/
/// Author : liuyubobobo
/// Time   : 2017-10-28

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {

        if(chars.size() <= 1)
            return chars.size();

        int start = 0;
        int index = 0;
        for(int i = start + 1 ; i <= chars.size() ; ){
            if(i == chars.size() || chars[i] != chars[start]){
                int len = i - start;

                chars[index++] = chars[start];
                if(len != 1){
                    string len_str = to_string(len);
                    for(char c: len_str)
                        chars[index++] = c;
                }

                start = i;
                i = start + 1;
            }
            else
                i ++;
        }

        return index;
    }
};

int main() {

    char str1[] = {'a','a','b','b','c','c','c'};
    vector<char> vec1(str1, str1 + sizeof(str1)/sizeof(char));
    int len1 = Solution().compress(vec1);
    for(int i = 0 ; i < len1 ; i ++)
        cout << vec1[i] << " ";
    cout << endl;

    // ---

    char str2[] = {'a'};
    vector<char> vec2(str2, str2 + sizeof(str2)/sizeof(char));
    int len2 = Solution().compress(vec2);
    for(int i = 0 ; i < len2 ; i ++)
        cout << vec2[i] << " ";
    cout << endl;

    // ---

    char str3[] = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
    vector<char> vec3(str3, str3 + sizeof(str3)/sizeof(char));
    int len3 = Solution().compress(vec3);
    for(int i = 0 ; i < len3 ; i ++)
        cout << vec3[i] << " ";
    cout << endl;

    return 0;
}