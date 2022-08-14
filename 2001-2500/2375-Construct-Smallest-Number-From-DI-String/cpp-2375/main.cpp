/// Source : https://leetcode.com/problems/construct-smallest-number-from-di-string/
/// Author : liuyubobobo
/// Time   : 2022-08-13

#include <iostream>
#include <vector>

using namespace std;


/// Backtrck
/// Time Complexity: O(|pattern|!)
/// Space Complexity: O(|pattern|)
class Solution {
public:
    string smallestNumber(string pattern) {

        int n = pattern.size();
        string res(n + 1, '0');
        for(int d = 1; d <= 9; d ++){
            res[0] = (char)('0' + d);
            if(dfs(pattern, 0, res, 1 << d))
                break;
        }
        return res;
    }

private:
    bool dfs(const string& pattern, int index, string& res, int state){

        if(index == pattern.size()) return true;

        if(pattern[index] == 'I'){
            for(int d = res[index] - '0' + 1; d <= 9; d ++){
                if((state & (1 << d)) == 0){
                    res[index + 1] = (char)('0' + d);
                    if(dfs(pattern, index + 1, res, state | (1 << d))) return true;
                }
            }
        }
        else{
            for(int d = 1; d < res[index] - '0'; d ++){
                if((state & (1 << d)) == 0){
                    res[index + 1] = (char)('0' + d);
                    if(dfs(pattern, index + 1, res, state | (1 << d))) return true;
                }
            }
        }
        return false;
    }
};


int main() {

    cout << Solution().smallestNumber("IIIDIDDD") << '\n';
    // 123549876

    cout << Solution().smallestNumber("DDD") << '\n';
    // 4321

    return 0;
}
