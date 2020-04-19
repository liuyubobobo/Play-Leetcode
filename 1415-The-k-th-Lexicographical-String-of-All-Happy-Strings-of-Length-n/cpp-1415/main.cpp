/// Source : https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/
/// Author : liuyubobobo
/// Time   : 2020-04-19

#include <iostream>

using namespace std;


/// Brute Force
/// Time Complexity: O(3^n)
/// Space Complexity:O(n)
class Solution {
public:
    string getHappyString(int n, int k) {

        string res(n, ' ');
        int i = 0;
        if(dfs(res, 0, i, n, k)) return res;
        return "";
    }

private:
    bool dfs(string& s, int index, int& cnt, int n, int k){

        if(index == n){
            cnt ++;
//            cout << s << endl;
            return cnt == k;
        }

        for(char c: {'a', 'b', 'c'})
            if(!index || c != s[index - 1]){
                s[index] = c;
                if(dfs(s, index + 1, cnt, n, k)) return true;
            }
        return false;
    }
};


int main() {

    cout << Solution().getHappyString(1, 3) << endl;
    // c

    cout << Solution().getHappyString(1, 4) << endl;
    // ""

    cout << Solution().getHappyString(3, 9) << endl;
    // cab

    cout << Solution().getHappyString(2, 7) << endl;
    // ""

    cout << Solution().getHappyString(10, 100) << endl;
    // abacbabacb

    return 0;
}
