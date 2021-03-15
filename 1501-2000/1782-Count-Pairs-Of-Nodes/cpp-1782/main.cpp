/// Source : https://leetcode.com/problems/count-pairs-of-nodes/
/// Author : liuyubobobo
/// Time   : 2021-03-15

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// inclusive-exclusive
/// Time Complexity: O(eloge + q * (nlogn + e))
/// Space Complexity: O(e)
class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {

        vector<int> degrees(n);
        map<pair<int, int>, int> edge_table;

        for(vector<int>& e: edges){
            e[0] --, e[1] --;
            edge_table[{min(e[0], e[1]), max(e[0], e[1])}] ++;
            degrees[e[0]] ++, degrees[e[1]] ++;
        }

        vector<int> sorted_degrees = degrees;
        sort(sorted_degrees.begin(), sorted_degrees.end());

        vector<int> res;
        for(int q: queries){

            int num = greater_pairs(sorted_degrees, q);
            for(const pair<pair<int, int>, int>& p: edge_table){
                int e0 = p.first.first, e1 = p.first.second, f = p.second;
                if(degrees[e0] + degrees[e1] > q && degrees[e0] + degrees[e1] - f <= q)
                    num --;
            }
            res.push_back(num);
        }
        return res;
    }

private:
    int greater_pairs(const vector<int>& data, int k){

        int res = 0;
        for(int i = 0; i < data.size(); i ++){
            vector<int>::const_iterator iter = upper_bound(data.begin() + (i + 1), data.end(), k - data[i]);
            res += (data.end() - iter);
        }
        return res;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << " "; cout << endl;
}

int main() {

    vector<vector<int>> edges1 = {
            {1, 5}, {1, 5}, {3, 4}, {2, 5}, {1, 3}, {5, 1}, {2, 3}, {2, 5}
    };
    vector<int> queries1 = {1, 2, 3, 4, 5};
    print_vec(Solution().countPairs(5, edges1, queries1));
    // 10 10 9 8 6

    return 0;
}
