/// Source : https://leetcode.com/problems/longest-repeating-substring/
/// Author : liuyubobobo
/// Time   : 2020-06-19

#include <iostream>
#include <unordered_set>

using namespace std;


/// Binary Search + Hash Table
/// Time Complexity: O(|s|^2 * log|s|)
/// Space Complexity: O(|s|^2)
class Solution {
public:
    int longestRepeatingSubstring(string s) {

        int l = 0, r = s.size() - 1;
        while(l < r){
            int mid = (l + r + 1) / 2;
            if(ok(s, mid)) l = mid;
            else r = mid - 1;
        }
        return l;
    }

private:
    bool ok(const string& s, int len){

        unordered_set<string> hashtable;
        for(int i = 0; i + len <= s.size(); i ++){
            string t = s.substr(i, len);
            if(hashtable.count(t)) return true;
            hashtable.insert(t);
        }
        return false;
    }
};

int main() {

    return 0;
}
