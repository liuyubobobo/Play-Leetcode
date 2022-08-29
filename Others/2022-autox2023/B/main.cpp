/// Source : https://leetcode.cn/contest/autox2023/problems/8p6t8R/
/// Author : liuyubobobo
/// Time   : 2022-08-28

#include <iostream>
#include <vector>

using namespace std;


/// Ad-Hoc
/// Time Complexity: type 1, 2, 3: O(1)
///                  type 4: O(maxv)
/// Space Complexity: O(maxv)
class Solution {
public:
    vector<double> honeyQuotes(vector<vector<int>>& handle) {

        vector<int> f(101, 0);
        int sz = 0;
        long long sum = 0;

        vector<double> res;
        for(const vector<int>& h: handle){
            int type = h[0];
            if(type == 1){
                f[h[1]] ++;
                sz ++;
                sum += h[1];
            }
            else if(type == 2){
                f[h[1]] --;
                sz --;
                sum -= h[1];
            }
            else if(type == 3){
                if(sz == 0) res.push_back(-1);
                else res.push_back((double)sum / sz);
            }
            else{

                if(sz == 0){
                    res.push_back(-1);
                    continue;
                }

                double mean = (double)sum / sz;

                double upper = 0.0;
                for(int v = 0; v <= 100; v ++){
                    if(f[v] == 0) continue;
                    upper += (v - mean) * (v - mean) * f[v];
                }
                res.push_back(upper / sz);
            }
        }
        return res;
    }
};


int main() {

    return 0;
}
