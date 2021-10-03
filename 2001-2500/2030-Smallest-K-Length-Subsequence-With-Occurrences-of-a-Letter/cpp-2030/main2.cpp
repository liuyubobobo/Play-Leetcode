/// Source : https://leetcode.com/problems/smallest-k-length-subsequence-with-occurrences-of-a-letter/
/// Author : liuyubobobo
/// Time   : 2021-10-03

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Greedy using Stack
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

public:
    string smallestSubsequence(string s, int k, char target, int reps) {

        int n = s.size();

        int target_num = 0;
        for(char c: s) target_num += (c == target);

        string res = "";
        for(int i = 0; i < n; i ++){

            while(!res.empty() &&
                  s[i] < res.back() && n - i >= k + 1 && target_num >= reps + (res.back() == target)){

                reps += (res.back() == target);
                k ++;
                res.pop_back();
            }

            if(k && k - 1 >= reps - (s[i] == target)){
                reps -= (s[i] == target);
                k --;
                res += s[i];
            }

            target_num -= (s[i] == target);
        }

        return res;
    }
};


int main() {

    cout << Solution().smallestSubsequence("leet", 3, 'e', 1) << endl;
    // eet

    cout << Solution().smallestSubsequence("leetcode", 4, 'e', 2) << endl;
    // ecde

    cout << Solution().smallestSubsequence("bb", 2, 'b', 2) << endl;
    // bb

    cout << Solution().smallestSubsequence("aaabbbcccddd", 3, 'b', 2) << endl;
    // abb

    cout << Solution().smallestSubsequence("exexe", 3, 'e', 2) << endl;
    // eee

    cout << Solution().smallestSubsequence("eeeexeeeyexyyeyxeyexyxeyexeexyexxxxyxeye", 7, 'e', 2) << endl;
    // eeeeeee

    return 0;
}
