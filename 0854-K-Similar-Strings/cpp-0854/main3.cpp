/// Source : https://leetcode.com/problems/k-similar-strings/description/
/// Author : liuyubobobo
/// Time   : 2018-06-21

#include <iostream>
#include <queue>
#include <cassert>
#include <unordered_set>

using namespace std;


/// Greedy + BFS
/// Time Complexity: O(2^n)
/// Space Complexity: O(2^n)
class Solution {

public:
    int kSimilarity(string A, string B) {

        assert(A.size() == B.size());
        assert(A.size() > 0);
        if(A.size() == 1){
            assert(A[0] == B[0]);
            return 0;
        }

        queue<pair<string, int>> q;
        q.push(make_pair(A, 0));

        unordered_set<string> visited;
        visited.insert(A);

        while(!q.empty()){
            string curS = q.front().first;
            int curStep = q.front().second;

            if(curS == B)
                return curStep;

            q.pop();

            int start = 0;
            for( ; start < curS.size() ; start ++)
                if(curS[start] != B[start])
                    break;

            for(int i = start + 1 ; i < curS.size() ; i ++)
                if(curS[i] == B[start]){
                    swap(curS[start], curS[i]);
                    if(visited.find(curS) == visited.end()){
                        visited.insert(curS);
                        q.push(make_pair(curS, curStep + 1));
                    }
                    swap(curS[start], curS[i]);
                }
        }

        assert(false);
        return -1;
    }
};

int main() {

    string A1 = "ab";
    string B1 = "ba";
    cout << Solution().kSimilarity(A1, B1) << endl;
    // 1

    string A2 = "abc";
    string B2 = "bca";
    cout << Solution().kSimilarity(A2, B2) << endl;
    // 2

    string A3 = "abac";
    string B3 = "baca";
    cout << Solution().kSimilarity(A3, B3) << endl;
    // 2

    string A4 = "aabc";
    string B4 = "abca";
    cout << Solution().kSimilarity(A4, B4) << endl;
    // 2

    string A5 = "abcdefabcdefabcdef";
    string B5 = "edcfbebceafcfdabad";
    cout << Solution().kSimilarity(A5, B5) << endl;
    // 10

    return 0;
}