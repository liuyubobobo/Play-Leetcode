/// Source : https://leetcode.com/problems/find-good-days-to-rob-the-bank/
/// Author : liuyubobobo
/// Time   : 2021-12-12

#include <iostream>
#include <vector>

using namespace std;


/// DP
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {

        int n = security.size();

        vector<int> a(n, 1), b(n, 1);
        for(int i = 1; i < n; i ++)
            if(security[i] <= security[i - 1]) a[i] = a[i - 1] + 1;
//        for(int e: a) cout << e << ' '; cout << '\n';

        for(int i = n - 2; i >= 0; i --)
            if(security[i] <= security[i + 1]) b[i] = b[i + 1] + 1;
//        for(int e: b) cout << e << ' '; cout << '\n';

        vector<int> res;
        for(int i = 0; i < n; i ++)
            if(a[i] >= time + 1 && b[i] >= time + 1) res.push_back(i);
        return res;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << ' '; cout << '\n';
}

int main() {

    vector<int> security1 = {5, 3, 3, 3, 5, 6, 2};
    print_vec(Solution().goodDaysToRobBank(security1, 2));
    // 2 3

    vector<int> security2 = {1, 1, 1, 1, 1};
    print_vec(Solution().goodDaysToRobBank(security2, 0));
    // 0 1 2 3 4

    vector<int> security3 = {1, 2, 3, 4, 5, 6};
    print_vec(Solution().goodDaysToRobBank(security3, 2));
    // empty

    vector<int> security4 = {1};
    print_vec(Solution().goodDaysToRobBank(security4, 5));
    // empty

    return 0;
}
