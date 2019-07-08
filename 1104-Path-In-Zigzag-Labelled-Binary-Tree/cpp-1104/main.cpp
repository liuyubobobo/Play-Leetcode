/// Source : https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/
/// Author : liuyubobobo
/// Time   : 2019-06-30

#include <iostream>
#include <vector>

using namespace std;


/// Mathematics
/// Time Complexity: O(log(label))
/// Space Complexity: O(log(label))
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {

        if(label == 1) return {1};

        vector<int> power2 = {1};
        int e = 1;
        for(int i = 1; power2.back() < label; i ++)
            e *= 2, power2.push_back(power2.back() + e);

        vector<int> res = {label};
        bool rev = true;
        for(int level = power2.size() - 2; res.back() != 1; level --){
            label /= 2;
            if(level && rev)
                res.push_back(power2[level - 1] + 1 + power2[level] - label);
            else
                res.push_back(label);
            rev = !rev;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};


void print_vec(const vector<int>& vec){
    for(int e: vec) cout << e << " "; cout << endl;
}

int main() {

    print_vec(Solution().pathInZigZagTree(14));
    // 1 3 4 14

    print_vec(Solution().pathInZigZagTree(26));
    // 1 2 6 10 26

    return 0;
}