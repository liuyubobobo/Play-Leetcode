/// Source : https://leetcode-cn.com/problems/deep-dark-fraction/
/// Author : liuyubobobo
/// Time   : 2020-04-30

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Actually, it's no need to run gcd for this problem
/// Here's a goog explanation: https://leetcode-cn.com/problems/deep-dark-fraction/solution/bu-yong-yue-fen-by-jriver/
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> fraction(vector<int>& cont) {

        int n = cont.size();
        if(n == 1 || cont[n - 1] == 0) return {cont[0], 1};

        vector<int> res = {cont[n - 1], 1};
        for(int i = n - 2; i >= 0; i --){
            swap(res[0], res[1]);
            res[0] += cont[i] * res[1];
        }
        return res;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << " "; cout << endl;
}

int main() {

    vector<int> cont1 = {3, 2, 0, 2};
    print_vec(Solution().fraction(cont1));
    // 13 4

    vector<int> cont2 = {0, 0, 3};
    print_vec(Solution().fraction(cont2));
    // 3 1

    vector<int> cont3 = {6, 1, 4, 7, 6, 2, 1, 4, 8, 0};
    print_vec(Solution().fraction(cont3));
    // 3 1

    return 0;
}