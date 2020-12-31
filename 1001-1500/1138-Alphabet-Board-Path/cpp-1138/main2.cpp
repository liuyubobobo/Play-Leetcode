/// Source : https://leetcode.com/problems/two-sum/description/
/// Author : liuyubobobo
/// Time   : 2019-07-30

#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;


/// Calculate the differant coordinates
/// Time Complexity: O(len(target) * 10)
/// Space Complexity: O(1)
class Solution {
public:
    string alphabetBoardPath(string target) {

        target = "a" + target;
        string res = "";
        for(int i = 1; i < target.size(); i ++)
            res += get_path(target[i - 1], target[i]) + "!";
        return res;
    }

private:
    string get_path(const char a, const char b){

        int x1 = (a - 'a') / 5, y1 = (a - 'a') % 5;
        int x2 = (b - 'a') / 5, y2 = (b - 'a') % 5;

        string res = "";
        if(x1 > x2) res += string(x1 - x2, 'U');
        if(y1 > y2) res += string(y1 - y2, 'L');
        if(y1 < y2) res += string(y2 - y1, 'R');
        if(x1 < x2) res += string(x2 - x1, 'D');

        return res;
    }
};


int main() {

    cout << Solution().alphabetBoardPath("leet") << endl;
    // DDR!UURRR!!DDD!

    cout << Solution().alphabetBoardPath("code") << endl;
    // DDR!UURRR!!DDD!

    cout << Solution().alphabetBoardPath("zdz") << endl;
    // "DDDDD!UUUUURRR!DDDDLLLD!"

    return 0;
}