/// Source : https://leetcode.com/problems/describe-the-painting/
/// Author : liuyubobobo
/// Time   : 2021-07-24

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Diff Array
/// Time Compelxity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {

        int n = 0;
        for(const vector<int>& seg: segments)
            n = max(n, seg[1] - 1);
        n ++;

        set<int> boundaries;
        vector<long long> diff(n + 1, 0ll);
        for(const vector<int>& seg: segments){
            int a = seg[0] - 1, b = seg[1] - 1;
            diff[a] += seg[2], diff[b] -= seg[2];
            boundaries.insert(a);
            boundaries.insert(b);
        }

        vector<long long> res(n - 1, diff[0]);
        long long sum = diff[0];
        for(int i = 1; i + 1 < n; i ++){
            sum += diff[i];
            res[i] = sum;
        }

        vector<int> bv(boundaries.begin(), boundaries.end());
//        for(int b: bv) cout << b << ' '; cout << endl;

        vector<vector<long long>> ret;
        for(int i = 1; i < boundaries.size(); i ++)
            if(res[bv[i - 1]])
                ret.push_back({bv[i - 1] + 1, bv[i] + 1, res[bv[i - 1]]});

        return ret;
    }
};


void print_vec(const vector<vector<long long>>& res){
    for(const vector<long long>& row: res){
        cout << '{';
        for(long long e: row) cout << e << ' ';
        cout << "} ";
    }
    cout << endl;
}

int main() {

    vector<vector<int>> segments1 = {{1, 4, 5}, {4, 7, 7}, {1, 7, 9}};
    print_vec(Solution().splitPainting(segments1));
    // {1, 4, 14}, {4, 7, 16}

    vector<vector<int>> segments2 = {{1, 7, 9}, {6, 8, 15}, {8, 10, 7}};
    print_vec(Solution().splitPainting(segments2));
    // {1, 6, 9}, {6, 7, 24}, {7, 8, 15}, {8, 10, 7}

    vector<vector<int>> segments3 = {{1, 4, 5}, {1, 4, 7}, {4, 7, 1}, {4, 7, 11}};
    print_vec(Solution().splitPainting(segments3));
    // {1, 4, 12}, {4, 7, 12}

    vector<vector<int>> segments4 = {{4,16,12},{9,10,15},{18,19,13},{3,13,20},{12,16,3},{2,10,10},{3,11,4},{13,16,6}};
    print_vec(Solution().splitPainting(segments4));
    // {1, 4, 12}, {4, 7, 12}

    return 0;
}
