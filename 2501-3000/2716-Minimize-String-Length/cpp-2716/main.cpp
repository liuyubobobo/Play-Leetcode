/// Source : https://leetcode.com/problems/minimize-string-length/description/
/// Author : liuyubobobo
/// Time   : 2023-06-04

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int minimizedStringLength(string s) {

        vector<bool> visited(26, false);
        for(char c: s) visited[c - 'a'] = true;
        return accumulate(visited.begin(), visited.end(), 0);
    }
};


int main() {

    return 0;
}
