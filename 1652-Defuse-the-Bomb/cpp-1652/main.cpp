/// Source : https://leetcode.com/problems/defuse-the-bomb/
/// Author : liuyubobobo
/// Time   : 2020-11-14

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n * k)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {

        int n = code.size();
        vector<int> res(n, 0);

        if(k == 0) return res;

        if(k > 0){
            for(int i = 0; i < n; i ++)
                for(int j = 1; j <= k; j ++)
                    res[i] += code[(i + j)% n];
        }
        else{
            for(int i = 0; i < n; i ++)
                for(int j = 1; j <= -k; j ++)
                    res[i] += code[(i - j + n) % n];
        }
        return res;
    }
};


int main() {

    return 0;
}
