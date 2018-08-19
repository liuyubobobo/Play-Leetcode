/// Source : https://leetcode.com/problems/fair-candy-swap/description/
/// Author : liuyubobobo
/// Time   : 2018-08-18

#include <iostream>
#include <vector>
#include <unordered_set>
#include <cassert>

using namespace std;


/// Hashing Set
/// Time Complexity: O(len(A) + len(B))
/// Space Complexity: O(len(A) + len(B))
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {

        unordered_set<int> Aset, Bset;
        int sumA = 0, sumB = 0;
        for(int a: A){
            Aset.insert(a);
            sumA += a;
        }

        for(int b: B){
            Bset.insert(b);
            sumB += b;
        }

        int sz = (sumA + sumB) / 2;

        for(int a: A)
            if(Bset.find(sz - (sumA - a)) != Bset.end())
                return {a, sz - (sumA - a)};

        assert(false);
        return {};
    }
};


int main() {

    return 0;
}