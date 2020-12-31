/// Source : https://leetcode.com/problems/queries-on-a-permutation-with-key/
/// Author : liuyubobobo
/// Time   : 2020-04-11

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(m^2)
/// Space Complexity: O(m)
class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {

        vector<int> p(m);
        for(int i = 1; i <= m; i ++) p[i - 1] = i;

        vector<int> res;
        for(int q: queries){

            int i = 0;
            for(; i < m; i ++) if(p[i] == q){res.push_back(i); break;}
            for(int j = i - 1; j >= 0; j --) p[j + 1] = p[j];
            p[0] = q;
        }
        return res;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << " "; cout << endl;
}

int main() {

    vector<int> q1 = {3, 1, 2, 1};
    print_vec(Solution().processQueries(q1, 5));
    // 2 1 2 1

    vector<int> q2 = {4, 1, 2, 2};
    print_vec(Solution().processQueries(q2, 4));
    // 3 1 2 0

    vector<int> q3 = {7,5,5,8,3};
    print_vec(Solution().processQueries(q3, 8));
    // 6,5,0,7,5

    return 0;
}
