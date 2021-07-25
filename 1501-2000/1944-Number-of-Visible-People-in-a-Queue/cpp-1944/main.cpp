/// Source : https://leetcode.com/problems/number-of-visible-people-in-a-queue/
/// Author : liuyubobobo
/// Time   : 2021-07-24

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


/// Mono Stack + Bknary Search
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {

        int n = heights.size();

        vector<int> stack;
        vector<int> res(n, 0);
        if(n == 1) return res;

        stack.push_back(heights.back());
        for(int i = n - 2; i >= 0; i --){
//            int x = upper(stack, heights[i]);
//            if(x == -1) res[i] = stack.size();
//            else res[i] = stack.size() - x;

            if(!stack.empty() && heights[i] > stack[0])
                res[i] = stack.size();
            else
                res[i] = stack.size() - upper(stack, heights[i]);

            while(!stack.empty() && stack.back() < heights[i])
                stack.pop_back();
            stack.push_back(heights[i]);
        }
        return res;
    }

private:
    int upper(const vector<int>& v, int t){

//        for(int e: v) cout << e << ' '; cout << '\n';
        auto iter = upper_bound(v.rbegin(), v.rend(), t);
        if(iter == v.rend()){
//            cout << "no solution" << endl;
            return -1;
        }

//        cout << "find " << t << " get " << *iter << endl;
//        cout << "index = " << (iter - v.rbegin()) << endl;
        int index = iter - v.rbegin();
        return v.size() - 1 - index;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << ' '; cout << endl;
}

int main() {

    vector<int> heights1 = {10, 6, 8, 5, 11, 9};
    print_vec(Solution().canSeePersonsCount(heights1));
    // 3 1 2 1 1 0

    vector<int> heights2 = {5, 1, 2, 3, 10};
    print_vec(Solution().canSeePersonsCount(heights2));
    // 4 1 1 1 0

    vector<int> heights3 = {3, 1, 5, 8, 6};
    print_vec(Solution().canSeePersonsCount(heights3));
    // 2 1 1 1 0

    vector<int> heights4 = {2, 10, 3, 4, 8};
    print_vec(Solution().canSeePersonsCount(heights4));
    // 1 3 1 1 0

    return 0;
}
