/// Source : https://leetcode.com/problems/neighboring-bitwise-xor/description/
/// Author : liuyubobobo
/// Time   : 2023-05-13

#include <iostream>
#include <vector>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {

        int n = derived.size();
        return check(n, 0, derived) || check(n, 1, derived);
    }

private:
    bool check(int n, int first, const vector<int>& derived){

        vector<int> v(n, first);
        for(int i = 1; i < n; i ++) v[i] = v[i - 1] ^ derived[i - 1];
        return v.back() ^ v[0] == derived.back();
    }
};


int main() {

    return 0;
}
