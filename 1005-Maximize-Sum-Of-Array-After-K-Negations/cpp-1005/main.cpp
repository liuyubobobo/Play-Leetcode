#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {

        vector<int> indegrees(N, 0), outdegrees(N, 0);
        for(const vector<int>& e: trust)
            outdegrees[e[0] - 1] ++,
            indegrees[e[1] - 1] ++;

        for(int i = 0; i < N; i ++)
            if(indegrees[i] == N - 1 && outdegrees[i] == 0)
                return i + 1;
        return -1;
    }
};


int main() {

    return 0;
}