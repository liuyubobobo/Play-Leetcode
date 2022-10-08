/// Source : https://leetcode-cn.com/problems/WqXACV/
/// Author : liuyubobobo
/// Time   : 2021-06-19

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int halfQuestions(vector<int>& questions) {

        int N = questions.size() / 2;

        unordered_map<int, int> f;
        for(int e: questions) f[e] ++;

        vector<int> data;
        for(const pair<int, int>& p: f)
            data.push_back(p.second);
        sort(data.rbegin(), data.rend());

        int res = 0;
        for(int cur = 0, i = 0; i < data.size() && cur < N; i ++){
            res ++;
            cur += data[i];
        }
        return res;
    }
};


int main() {

    vector<int> q1 = {2, 1, 6, 2};
    cout << Solution().halfQuestions(q1) << endl;
    // 1

    vector<int> q2 = {1,5,1,3,4,5,2,5,3,3,8,6};
    cout << Solution().halfQuestions(q2) << endl;
    // 2

    return 0;
}
