/// Source : https://leetcode.com/problems/finding-3-digit-even-numbers/
/// Author : liuyubobobo
/// Time   : 2021-12-04

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^3)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& d) {

        int n = d.size();

        set<int> res;
        for(int i = 0; i < n; i ++)
            for(int j = i + 1; j < n; j ++)
                for(int k = j + 1; k < n; k ++){
                    if(d[i]){
                        if(d[k] % 2 == 0) res.insert(d[i] * 100 + d[j] * 10 + d[k]);
                        if(d[j] % 2 == 0) res.insert(d[i] * 100 + d[k] * 10 + d[j]);
                    }
                    if(d[j]){
                        if(d[k] % 2 == 0) res.insert(d[j] * 100 + d[i] * 10 + d[k]);
                        if(d[i] % 2 == 0) res.insert(d[j] * 100 + d[k] * 10 + d[i]);
                    }
                    if(d[k]){
                        if(d[j] % 2 == 0) res.insert(d[k] * 100 + d[i] * 10 + d[j]);
                        if(d[i] % 2 == 0) res.insert(d[k] * 100 + d[j] * 10 + d[i]);
                    }
                }

        return vector<int>(res.begin(), res.end());
    }
};


int main() {

    return 0;
}
