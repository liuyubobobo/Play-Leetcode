/// Source : https://leetcode-cn.com/problems/UEcfPD/
/// Author : liuyubobobo
/// Time   : 2022-04-16

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(2^|cookbooks| * |cookbooks|)
/// Space Complexity: O(1)
class Solution {
public:
    int perfectMenu(vector<int>& materials, vector<vector<int>>& cookbooks,
                    vector<vector<int>>& attribute, int limit) {

        int n = cookbooks.size();
        int best_x = -1;
        for(int state = 1; state < (1 << n); state ++){

            int total_x = 0, total_y = 0;
            vector<int> total_m(5, 0);
            for(int i = 0; i < n; i ++)
                if(state & (1 << i)){
                    total_x += attribute[i][0];
                    total_y += attribute[i][1];
                    add(total_m, cookbooks[i]);
                }
            if(total_y >= limit && greater_or_equal(materials, total_m))
                best_x = max(best_x, total_x);
        }
        return best_x;
    }

private:
    // v += a
    void add(vector<int>& v, const vector<int>& a){
        for(int i = 0; i < v.size(); i ++) v[i] += a[i];
    }

    bool greater_or_equal(const vector<int>& a, const vector<int>& b){
        for(int i = 0; i < a.size(); i ++)
            if(a[i] < b[i]) return false;
        return true;
    }
};


int main() {

    vector<int> materials1 = {3,2,4,1,2};
    vector<vector<int>> cookbooks1 = {{1,1,0,1,2},{2,1,4,0,0},{3,2,4,1,0}};
    vector<vector<int>> attribute1 = {{3,2},{2,4},{7,6}};
    int limit1 = 5;
    cout << Solution().perfectMenu(materials1, cookbooks1, attribute1, limit1) << '\n';
    // 7

    return 0;
}
