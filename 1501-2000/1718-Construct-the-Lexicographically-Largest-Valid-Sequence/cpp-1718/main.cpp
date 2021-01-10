/// Source : https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/
/// Author : liuyubobobo
/// Time   : 2021-01-10

#include <iostream>
#include <vector>

using namespace std;


/// Backtracking
/// Time Complexity: O(n!)
/// Space Complexity: O(n)
class Solution {

private:
    int n;

public:
    vector<int> constructDistancedSequence(int n) {

        this->n = n;

        vector<int> res(2 * n - 1, -1);
        vector<bool> visited(n + 1, false);
        dfs(0, res, 2 * n - 1, visited);

        return res;
    }

private:
    bool dfs(int index, vector<int>& res, int len, vector<bool>& visited){

        if(index == len) return true;
        if(res[index] != -1) return dfs(index + 1, res, len, visited);

        for(int x = n; x > 1; x --)
            if(!visited[x] && index + x < res.size() && res[index + x] == -1){
                res[index] = res[index + x] = x;
                visited[x] = true;
                if(dfs(index + 1, res, len, visited)) return true;
                res[index] = res[index + x] = -1;
                visited[x] = false;
            }

        if(!visited[1]){
            res[index] = 1;
            visited[1] = true;
            if(dfs(index + 1, res, len, visited)) return true;
            res[index] = -1;
            visited[1] = false;
        }
        return false;
    }
};


void print_vec(const vector<int>& v){
    for(int x: v) cout << x << " "; cout << endl;
}

int main() {

    print_vec(Solution().constructDistancedSequence(3));
    // 3 1 2 3 2

    print_vec(Solution().constructDistancedSequence(5));
    // 5,3,1,4,3,5,2,4,2

    return 0;
}
