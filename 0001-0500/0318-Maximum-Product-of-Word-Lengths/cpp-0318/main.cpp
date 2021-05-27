/// Source : https://leetcode.com/problems/maximum-product-of-word-lengths/
/// Author : liuyubobobo
/// Time   : 2021-05-27

#include <iostream>
#include <vector>

using namespace std;


/// bitwise + brute force
/// Time Complexity: O(n * average_words_len + n^2)
/// Space Complexity: O(n)
class Solution {
public:
    int maxProduct(vector<string>& words) {

        int n = words.size();
        vector<int> bits(n, 0);
        for(int i = 0; i < n; i ++)
            for(char c: words[i])
                bits[i] |= (1 << (c - 'a'));

        int res = 0;
        for(int i = 0; i < n; i ++)
            for(int j = i + 1; j < n; j ++)
                if((bits[i] & bits[j]) == 0)
                    res = max(res, (int)words[i].size() * (int)words[j].size());
        return res;
    }
};


int main() {

    vector<string> words1 = {"abcw","baz","foo","bar","xtfn","abcdef"};
    cout << Solution().maxProduct(words1) << endl;
    // 16

    return 0;
}
