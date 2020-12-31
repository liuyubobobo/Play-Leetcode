/// Source : https://leetcode.com/problems/special-binary-string/
/// Author : liuyubobobo
/// Time   : 2020-04-24

#include <iostream>
#include <vector>

using namespace std;


/// Recursion
/// Time Complexity: O(n^2)
/// Space Complexity: O(n^2)
class Solution {
public:
    string makeLargestSpecial(string S) {

        if(S == "") return "";

        vector<string> v;
        int cnt = 0;
        for(int start = 0, i = 0; i < S.size(); i ++){
            cnt += (S[i] == '1' ? 1 : -1);
            if(!cnt){
                v.push_back("1" + makeLargestSpecial(S.substr(start + 1, i - start - 1)) + "0");
                start = i + 1;
            }
        }

        sort(v.begin(), v.end(), greater<string>());
        string res = "";
        for(const string& e: v) res += e;
        return res;
    }
};


int main() {

    cout << Solution().makeLargestSpecial("11011000") << endl;
    // 11100100

    return 0;
}
