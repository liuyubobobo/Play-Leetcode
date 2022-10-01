/// Source : https://leetcode-cn.com/problems/qi-wang-ge-shu-tong-ji/
/// Author : liuyubobobo
/// Time   : 2020-04-25

#include <iostream>
#include <vector>

using namespace std;


/// Sorting and Linear remove duplicates
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int expectNumber(vector<int>& scores) {

        sort(scores.begin(), scores.end());

        int res = 0;
        for(int start = 0, i = 1; i <= scores.size(); )
            if(i == scores.size() || scores[i] != scores[start]){
                int x = i - start;
                if(x) res ++;
                start = i;
                i = start + 1;
            }
            else i ++;

        return res;
    }
};


int main() {

    vector<int> scores1 = {1, 2, 3};
    cout << Solution().expectNumber(scores1) << endl;
    // 3

    vector<int> scores2 = {1, 1};
    cout << Solution().expectNumber(scores2) << endl;
    // 1

    vector<int> scores3 = {1, 1, 2};
    cout << Solution().expectNumber(scores3) << endl;
    // 2

    return 0;
}
