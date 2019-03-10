/// Source : https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/
/// Author : liuyubobobo
/// Time   : 2019-03-09

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {

        int n = A.size();
        unordered_set<int> set = {A[0], B[0]};
        for(int i = 1; i < n; i ++)
            set = intersection(set, A[i], B[i]);

        if(set.size() == 0) return -1;

        int target = *set.begin();
        return min(go(A, target), go(B, target));
    }

private:
    int go(const vector<int>& v, int target){

        int res = 0;
        for(int e: v)
            if(e != target) res ++;
        return res;
    }

    unordered_set<int> intersection(const unordered_set<int>& set, int a, int b){

        unordered_set<int> res;
        if(set.count(a)) res.insert(a);
        if(set.count(b)) res.insert(b);
        return res;
    }
};


int main() {

    return 0;
}