/// Source : https://leetcode.com/problems/find-the-divisibility-array-of-a-string/description/
/// Author : liuyubobobo
/// Time   : 2023-02-27

#include <iostream>
#include <vector>

using namespace std;


/// Math
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> divisibilityArray(string word, long long m) {

        int n = word.size();
        vector<int> res(n, 0);
        long long cur = 0ll;
        for(int i = 0; i < n; i++){
            cur = (cur * 10 + word[i] - '0') % m;
            res[i] = cur == 0;
        }
        return res;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
