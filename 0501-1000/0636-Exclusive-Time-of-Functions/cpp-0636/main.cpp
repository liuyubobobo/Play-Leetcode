/// Source : https://leetcode.com/problems/exclusive-time-of-functions/
/// Author : liuyubobobo
/// Time   : 2022-08-08

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Using Stack
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {

        vector<int> res(n, 0);

        vector<pair<pair<int, int>, char>> data; // id, ts, s or e
        for(const string& log: logs)
            data.push_back(parse(log));

        vector<pair<int, int>> stack; // id, ts
        for(const pair<pair<int, int>, char>& e: data){
            int id = e.first.first, ts = e.first.second;
            char s_or_e = e.second;

            if(s_or_e == 's'){
                if(!stack.empty()){
                    res[stack.back().first] += ts - stack.back().second;
                    stack.back().second = -1;
                }
                stack.push_back({id, ts});
            }
            else{
                assert(!stack.empty() && stack.back().first == id);
                res[stack.back().first] += ts - stack.back().second + 1;
                stack.pop_back();

                if(!stack.empty()){
                    stack.back().second = ts + 1;
                }
            }
        }
        return res;
    }

private:
    pair<pair<int, int>, char> parse(const string& log){

        int c1 = log.find(':'), c2 = log.find(':', c1 + 1);

        int id = atoi(log.substr(0, c1).c_str());
        char s_or_e =log[c1 + 1];
        int ts = atoi(log.substr(c2 + 1).c_str());
        return {{id, ts}, s_or_e};
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << ' '; cout << '\n';
}

int main() {

    vector<string> logs1 = {"0:start:0","1:start:2","1:end:5","0:end:6"};
    print_vec(Solution().exclusiveTime(2, logs1));
    // 3 4

    vector<string> logs2 = {"0:start:0","0:start:2","0:end:5","0:start:6","0:end:6","0:end:7"};
    print_vec(Solution().exclusiveTime(1, logs2));
    // 8

    return 0;
}
