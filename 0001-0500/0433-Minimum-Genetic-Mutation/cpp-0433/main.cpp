/// Source : https://leetcode.com/problems/minimum-genetic-mutation/
/// Author : liuyubobobo
/// Time   : 2022-05-06

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;


/// BFS
/// Time Complexity: O(n * |start|)
/// Space Complexity: O(n)
class Solution {

private:
    const vector<char> gene = {'A', 'C', 'G', 'T'};

public:
    int minMutation(string start, string end, vector<string>& bank) {

        set<string> bank_set(bank.begin(), bank.end());
        map<string, int> dis;

        queue<string> q;
        q.push(start);
        dis[start] = 0;
        while(!q.empty()){
            string cur = q.front();
            int d = dis[cur];
            q.pop();

            if(cur == end) return d;

            for(int i = 0; i < cur.size(); i ++) {
                char o_gene = cur[i];
                for (int j = 0; j < 4; j++) {
                    cur[i] = gene[j];
                    if(bank_set.count(cur) && !dis.count(cur)){
                        dis[cur] = d + 1;
                        q.push(cur);
                    }
                    cur[i] = o_gene;
                }
            }

        }
        return -1;
    }
};


int main() {

    return 0;
}
