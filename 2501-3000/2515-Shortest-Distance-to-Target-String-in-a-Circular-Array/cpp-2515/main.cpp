/// Source : https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/description/
/// Author : liuyubobobo
/// Time   : 2022-12-26

#include <iostream>
#include <vector>
#include <climits>

using namespace std;


/// Brute Force
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {

        auto iter = find(words.begin(), words.end(), target);
        if(iter == words.end()) return -1;

        vector<int> v;
        while(iter != words.end()) {
            int targetIndex = iter - words.begin();
            v.push_back(targetIndex);
            iter = find(words.begin() + targetIndex + 1, words.end(), target);
        }

        int n = words.size(), res = INT_MAX;
        for(int targetIndex: v){
            int a = (targetIndex - startIndex + n) % n;
            int b = (startIndex - targetIndex + n) % n;
            res = min(res, min(a, b));
        }
        return res;
    }
};


int main() {

    return 0;
}
