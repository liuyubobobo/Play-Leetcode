/// Source : https://leetcode.com/problems/capitalize-the-title/
/// Author : liuyubobobo
/// Time   : 2022-01-08

#include <iostream>
#include <vector>

using namespace std;


/// Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    string capitalizeTitle(string title) {

        int n = title.size();
        for(int start = 0, i = 1; i <= n; i ++)
            if(i == n || title[i] == ' '){
                int len = i - start;
                if(len <= 2){
                    for(int j = start; j < i; j ++) title[j] = tolower(title[j]);
                }
                else{
                    title[start] = toupper(title[start]);
                    for(int j = start + 1; j < i; j ++) title[j] = tolower(title[j]);
                }

                start = i + 1;
                i = start;
            }
        return title;
    }
};


int main() {

    return 0;
}
