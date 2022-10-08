/// Source : https://leetcode.cn/problems/600YaG/
/// Author : liuyubobobo
/// Time   : 2022-10-07

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int minNumBooths(vector<string>& demand) {

        vector<int> res(26, 0);
        for(const string& s: demand){
            vector<int> t(26, 0);
            for(char c: s) t[c - 'a'] ++;
            for(int i = 0; i < 26; i ++)
                res[i] = max(res[i], t[i]);
        }
        return accumulate(res.begin(), res.end(), 0);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
