/// Source : https://leetcode.com/problems/number-of-squareful-arrays/
/// Author : liuyubobobo
/// Time   : 2019-02-16

#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>

using namespace std;


/// Backtrack
/// Using string hash to record the same value
/// Time Complexity: O(n^n)
/// Space Complexity: O(n)
class Solution {

private:
    int n;

public:
    int numSquarefulPerms(vector<int>& A) {

        n = A.size();
        vector<vector<int>> ok(n);
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < n; j ++)
                if(j != i && perfectSquare(A[i] + A[j]))
                    ok[i].push_back(j);

        int res = 0;
        unordered_set<string> hashset;
        for(int i = 0; i < n; i ++){
            vector<bool> visited(n, false);
            visited[i] = true;

            vector<int> seqindex = {i};

            string hash = to_string(A[i]);
            hashset.insert(hash);

            res += dfs(A, ok, 1, seqindex, hash, visited, hashset);
        }
        return res;
    }

private:
    int dfs(const vector<int>& A, const vector<vector<int>>& ok,
            int index, vector<int>& seqindex, const string& hash, vector<bool>& visited,
            unordered_set<string>& hashset){

        if(index == n)
            return 1;

        int res = 0;
        for(int next: ok[seqindex[index - 1]])
            if(!visited[next]){

                string newhash = hash + "#" + to_string(A[next]);
                if(!hashset.count(newhash)){
                    hashset.insert(newhash);

                    seqindex.push_back(next);
                    visited[next] = true;
                    res += dfs(A, ok, index + 1, seqindex, newhash, visited, hashset);
                    visited[next] = false;
                    seqindex.pop_back();
                }
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