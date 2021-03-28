/// Source : https://leetcode.com/problems/minimum-number-of-operations-to-reinitialize-a-permutation/
/// Author : liuyubobobo
/// Time   : 2021-03-27

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    int reinitializePermutation(int n) {

        vector<int> a(n);
        for(int i = 0; i < n; i ++) a[i] = i;

        int res = 0;
        do{
            res ++;
            a = change(a);
        }while(!in_order(a));
        return res;
    }

private:
    bool in_order(const vector<int>& a){

        for(int i = 0; i < a.size(); i ++)
            if(a[i] != i) return false;
        return true;
    }

    vector<int> change(const vector<int>& a){

        vector<int> res(a.size());
        for(int i = 0; i < a.size(); i ++)
            if(i % 2 == 0) res[i] = a[i / 2];
            else res[i] = a[a.size() / 2 + (i - 1) / 2];
        return res;
    }
};


int main() {

    cout << Solution().reinitializePermutation(2) << endl;
    // 1

    cout << Solution().reinitializePermutation(4) << endl;
    // 2

    cout << Solution().reinitializePermutation(6) << endl;
    // 4

    cout << Solution().reinitializePermutation(8) << endl;
    // 3

    cout << Solution().reinitializePermutation(1000) << endl;
    // 36

    return 0;
}
