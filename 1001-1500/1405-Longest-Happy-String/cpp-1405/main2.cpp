/// Source : https://leetcode.com/problems/longest-happy-string/
/// Author : liuyubobobo
/// Time   : 2020-04-08

#include <iostream>
#include <vector>
#include <cassert>
#include <queue>

using namespace std;


/// Greedy with a priority queue
/// Time Complexity: O(a + b + c)
/// Space Complexity: O(1)
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {

        priority_queue<pair<int, char>> pq;
        if(a) pq.push(make_pair(a, 'a'));
        if(b) pq.push(make_pair(b, 'b'));
        if(c) pq.push(make_pair(c, 'c'));

        string res = "";
        while(!pq.empty()){
            char a = pq.top().second;
            int aleft = pq.top().first;
            pq.pop();

            if(res.size() && res.back() == a) break;

            int anum = min(aleft, 2);
            res += string(anum, a);
            aleft -= anum;

            if(pq.empty()) break;

            char b = pq.top().second;
            int bleft = pq.top().first;
            pq.pop();

            if(bleft){
                int bnum = (bleft >= 2 && aleft < bleft) ? 2 : 1;
                res += string(bnum, b);
                bleft -= bnum;
            }

            if(aleft) pq.push(make_pair(aleft, a));
            if(bleft) pq.push(make_pair(bleft, b));
        }
        return res;
    }
};


int main() {

    cout << Solution().longestDiverseString(1, 1, 7) << endl;
    cout << "ccaccbcc" << endl;
    // ccaccbcc
    cout << endl;

    cout << Solution().longestDiverseString(2, 2, 1) << endl;
    cout << "aabbc" << endl;
    // aabbc
    cout << endl;

    cout << Solution().longestDiverseString(7, 1, 0) << endl;
    cout << "aabaa" << endl;
    // aabaa
    cout << endl;

    cout << Solution().longestDiverseString(0, 8, 11) << endl;
    cout << "ccbccbbccbbccbbccbc" << endl;
    // ccbccbbccbbccbbccbc
    cout << endl;

    cout << Solution().longestDiverseString(4, 4, 3) << endl;
    cout << "aabbccaabbc" << endl;
    // aabbccaabbc
    cout << endl;

    cout << Solution().longestDiverseString(1, 1, 7) << endl;
    cout << "ccaccbcc" << endl;
    // ccaccbcc
    cout << endl;

    return 0;
}