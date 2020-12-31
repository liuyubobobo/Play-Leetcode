/// Source : https://leetcode.com/problems/minimum-number-of-frogs-croaking/
/// Author : liuyubobobo
/// Time   : 2020-04-18

#include <iostream>
#include <vector>

using namespace std;


/// Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int minNumberOfFrogs(string s) {

        if(s.size() % 5) return -1;

        for(char& c: s)
            if(c == 'c') c = 'a';
            else if(c == 'r') c = 'b';
            else if(c == 'o') c = 'c';
            else if(c == 'a') c = 'd';
            else if(c == 'k') c = 'e';
            else return -1;

        vector<int> record(5, 0);
        int res = 0;
        for(char c: s){

            for(char x = 'a'; x < c; x ++)
                if(record[x - 'a'] <= record[c - 'a']) return -1;

            record[c -'a'] ++;
            res = max(res, record[c -'a']);
            if(c == 'e')
                for(int& e: record) e --;
        }
        return res;
    }
};


int main() {

    cout << Solution().minNumberOfFrogs("croakcroak") << endl;
    // 1

    cout << Solution().minNumberOfFrogs("crcoakroak") << endl;
    // 2

    cout << Solution().minNumberOfFrogs("croakcrook") << endl;
    // -1

    cout << Solution().minNumberOfFrogs("croakcroa") << endl;
    // -1

    return 0;
}
