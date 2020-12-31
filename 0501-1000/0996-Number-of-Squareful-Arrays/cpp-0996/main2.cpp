/// Source : https://leetcode.com/problems/number-of-squareful-arrays/
/// Author : liuyubobobo
/// Time   : 2019-02-19

#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <unordered_set>

using namespace std;


/// Backtrack
/// Using HashMap to record the same value
/// Time Complexity: O(n^n)
/// Space Complexity: O(n)
class Solution {

private:
    int n;

public:
    int numSquarefulPerms(vector<int>& A) {

        n = A.size();
        unordered_map<int, int> freq;
        unordered_set<int> elements;
        for(int e: A){
            freq[e] ++;
            elements.insert(e);
        }

        unordered_map<int, unordered_set<int>> g;
        for(int i = 0; i < n; i ++)
            for(int j = i + 1; j < n; j ++)
                if(perfectSquare(A[i] + A[j])){
                    g[A[i]].insert(A[j]);
                    g[A[j]].insert(A[i]);
                }

        int res = 0;
        for(int e: elements){
            freq[e] --;
            res += dfs(g, e, 1, freq);
            freq[e] ++;
        }
        return res;
    }

private:
    int dfs(unordered_map<int, unordered_set<int>>& g,
            int e, int index, unordered_map<int, int>& freq){

        if(index == n)
            return 1;

        int res = 0;
        for(int next: g[e])
            if(freq[next]){
                freq[next] --;
                res += dfs(g, next, index + 1, freq);
                freq[next] ++;
            }
        return res;
    }

    bool perfectSquare(int x){
        int t = sqrt(x);
        return t * t == x;
    }
};


int main() {

    vector<int> A1 = {1, 17, 8};
    cout << Solution().numSquarefulPerms(A1) << endl;
    // 2

    vector<int> A2 = {2, 2, 2};
    cout << Solution().numSquarefulPerms(A2) << endl;
    // 1

    vector<int> A3(12, 0);
    cout << Solution().numSquarefulPerms(A3) << endl;
    // 1

    return 0;
}