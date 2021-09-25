/// Source : https://leetcode-cn.com/problems/05ZEDJ/
/// Author : liuyubobobo
/// Time   : 2021-09-25

#include <iostream>
#include <vector>

using namespace std;


/// Reverse
/// Time Complexity: O(|plan| * n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> volunteerDeployment(vector<int>& finalCnt, long long totalNum, vector<vector<int>>& edges, vector<vector<int>>& plans) {

        int n = finalCnt.size() + 1;
        vector<vector<int>> g(n);
        for(const vector<int>& edge: edges){
            int a = edge[0], b = edge[1];
            g[a].push_back(b), g[b].push_back(a);
        }

        vector<pair<long long, long long>> coef(n);
        coef[0].first = 1, coef[0].second = 0ll;
        for(int i = 0; i < finalCnt.size(); i ++){
            coef[i + 1].first = 0ll;
            coef[i + 1].second = finalCnt[i];
        }

        for(int i = (int)plans.size() - 1; i >= 0; i --){
            int type = plans[i][0], id = plans[i][1];

            if(type == 1){
                coef[id].first *= 2;
                coef[id].second *= 2;
            }
            else if(type == 2){
                for(int i: g[id])
                    coef[i] = minus(coef[i], coef[id]);
            }
            else{
                assert(type == 3);
                for(int i: g[id])
                    coef[i] = add(coef[i], coef[id]);
            }
        }

        pair<long long, long long> res = {0, 0};
        for(const pair<long long, long long>& p: coef)
            res.first += p.first, res.second += p.second;
        long long x = (totalNum - res.second) / res.first;

        vector<int> ret(n);
        for(int i = 0; i < n; i ++)
            ret[i] = coef[i].first * x  + coef[i].second;
        return ret;
    }

private:
    pair<long long, long long> minus(pair<long long, long long> a, pair<long long, long long> b){
        return {a.first - b.first, a.second - b.second};
    }

    pair<long long, long long> add(pair<long long, long long> a, pair<long long, long long> b){
        return {a.first + b.first, a.second + b.second};
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << ' ';
    cout << '\n';
}

int main() {

    vector<int> finalCut1 = {1, 16}; long long totalNum1 = 21;
    vector<vector<int>> edges1 = {{0, 1}, {1, 2}};
    vector<vector<int>> plan1 = {{2, 1}, {1, 0}, {3, 0}};
    print_vec(Solution().volunteerDeployment(finalCut1, totalNum1, edges1, plan1));
    // 5 7 9

    vector<int> finalCut2 = {4,13,4,3,8}; long long totalNum2 = 54;
    vector<vector<int>> edges2 = {{0, 3}, {1, 3}, {4, 3}, {2, 3}, {2, 5}};
    vector<vector<int>> plan2 = {{1, 1}, {3, 3}, {2, 5}, {1, 0}};
    print_vec(Solution().volunteerDeployment(finalCut2, totalNum2, edges2, plan2));
    // 10 16 9 4 7 8

    return 0;
}
