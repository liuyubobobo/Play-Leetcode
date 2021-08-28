/// Source : https://leetcode.com/problems/longest-uncommon-subsequence-ii/
/// Author : liuyubobobo
/// Time   : 2021-08-27

#include <iostream>
#include <vector>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(n^2 * |len|)
/// Space Complexity: O(1)
class Solution {
public:
    int findLUSlength(vector<string>& strs) {

        int res = 0;
        for(int i = 0; i < strs.size(); i ++){
            int j = 0;
            for(j = 0; j < strs.size(); j ++){
                if(i == j) continue;
                if(is_subseq(strs[i], strs[j]))
                    break;
            }
            if(j == strs.size())
                res = max(res, (int)strs[i].size());
        }
        return res == 0 ? - 1: res;
    }

private:
    // see if a is b's sub seq
    bool is_subseq(const string& a, const string& b){

        if(a.size() > b.size()) return false;

        int i = 0;
        for(int j = 0; j < b.size(); j ++)
            if(a[i] == b[j]) i ++;
        return i == a.size();
    }
};


int main() {

    return 0;
}
