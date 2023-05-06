/// Source : https://leetcode.com/problems/minimum-number-of-frogs-croaking/
/// Author : liuyubobobo
/// Time   : 2020-04-18
/// Updated: 2023-05-05

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

        vector<int> waitfor(5, 0);
        int res = 0;
        for(char c: s){

            int v = c - 'a';
            if(v == 0 && waitfor[0] == 0) res ++, waitfor[1] ++;
            else{
                if(waitfor[v] == 0) return -1;
                waitfor[v] --;
                waitfor[(v + 1) % 5] ++;
            }
        }
        return waitfor[0] == res ? res : -1;
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
