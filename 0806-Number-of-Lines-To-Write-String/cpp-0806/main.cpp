/// Source : https://leetcode.com/problems/number-of-lines-to-write-string/description/
/// Author : liuyubobobo
/// Time   : 2018-03-24

#include <iostream>
#include <vector>

using namespace std;

/// Ad-Hoc
/// Time Complexity: O(len(S))
/// Space Complexity : O(1)
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {

        int lines = 0, cur = 0;
        for(char c: S){
            int w = widths[c - 'a'];
            if(cur + w > 100){
                lines ++;
                cur = w;
            }
            else
                cur += w;
        }

        return vector<int>{lines + 1, cur};
    }
};


void print_vec(const vector<int>& vec){

    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    vector<int> widths1 = {10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
    string S1 = "abcdefghijklmnopqrstuvwxyz";
    print_vec(Solution().numberOfLines(widths1, S1));

    vector<int> widths2 = {4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
    string S2 = "bbbcccdddaaa";
    print_vec(Solution().numberOfLines(widths2, S2));

    return 0;
}