/// Source : https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/
/// Author : liuyubobobo
/// Time   : 2020-09-19

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Backtracking
/// Time Complexity: O(|s|^|s|)
/// Space Complexity: O(|s|^2)
class Solution {
public:
    int maxUniqueSplit(string s) {

        set<string> bag;
        return dfs(s, 0, bag);
    }

private:
    int dfs(const string& s, int start, set<string>& bag){

        if(start == s.size())
            return bag.size();

        int res = 0;
        for(int end = start; end <= s.size(); end ++)
            if(!bag.count(s.substr(start, end - start + 1))){
                bag.insert(s.substr(start, end - start + 1));
                res = max(res, dfs(s, end + 1, bag));
                bag.erase(s.substr(start, end - start + 1));
            }
        return res;
    }
};


int main() {

    cout << Solution().maxUniqueSplit("ababccc") << endl;
    // 5

    cout << Solution().maxUniqueSplit("aba") << endl;
    // 2

    cout << Solution().maxUniqueSplit("aa") << endl;
    // 1

    return 0;
}