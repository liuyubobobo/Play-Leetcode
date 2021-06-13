/// Source : https://leetcode.com/problems/maximum-number-of-removable-characters/
/// Author : liuyubobobo
/// Time   : 2021-06-12

#include <iostream>
#include <vector>

using namespace std;


/// Binary Search
/// Time Complexity: O(|s| * log|removable|)
/// Space Complexity: O(|s|)
class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {

        int l = 0, r = removable.size();
        while(l < r){
            int mid = (l + r + 1) / 2;
            if(ok(s, p, removable, mid)) l = mid;
            else r = mid - 1;
        }
        return l;
    }

private:
    bool ok(string s, const string& p, const vector<int>& removable, int k){

        for(int i = 0; i < k; i ++)
            s[removable[i]] = ' ';

        int j = 0;
        for(int i = 0; i < s.size() && j < p.size(); i ++)
            if(s[i] == p[j]) j ++;
        return j == p.size();
    }
};


int main() {

    vector<int> removable1 = {3, 1, 0};
    cout << Solution().maximumRemovals("abcacb", "ab", removable1) << endl;
    // 2

    vector<int> removable2 = {3, 2, 1, 4, 5, 6};
    cout << Solution().maximumRemovals("abcbddddd", "abcd", removable2) << endl;
    // 1

    vector<int> removable3 = {0, 1, 2, 3, 4};
    cout << Solution().maximumRemovals("abcab", "abc", removable3) << endl;
    // 0

    return 0;
}
