/// Source : https://leetcode.com/problems/count-pairs-of-equal-substrings-with-minimum-difference/
/// Author : liuyubobobo
/// Time   : 2021-03-21

#include <iostream>
#include <vector>

using namespace std;


/// Greedy
/// Time Compleixty: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int countQuadruples(string s1, string s2) {

        vector<int> first(26, -1), last(26, -1);
        for(int i = 0; i < s1.size(); i ++)
            if(first[s1[i] - 'a'] == -1)
                first[s1[i] - 'a'] = i;

        for(int i = s2.size() - 1; i >= 0; i --)
            if(last[s2[i] - 'a'] == -1)
                last[s2[i] - 'a'] = i;

        int minv = INT_MAX, minc = -1;
        for(int i = 0; i < 26; i ++)
            if(first[i] != -1 && last[i] != -1){
                if(first[i] - last[i] < minv)
                    minv = first[i] - last[i], minc = i;
                else if(first[i] - last[i] == minv && first[i] < first[minc])
                    minc = i;
            }

        if(minc == -1) return 0;

        int res = 0, i = first[minc], j = last[minc];
        while(i < s1.size() && j < s2.size() && s1[i] == s2[j])
            res ++, i ++, j ++;
        return res;
    }
};


int main() {

    cout << Solution().countQuadruples("abcd", "bccda") << endl;
    // 1

    cout << Solution().countQuadruples("ab", "cd") << endl;
    // 0

    cout << Solution().countQuadruples("dwtgmqucavlta", "gupciaqadwtgm") << endl;
    // 5

    cout << Solution().countQuadruples("rzsntggflhavoq", "qshrzsn") << endl;
    // 4

    return 0;
}
