/// Source : https://leetcode.com/problems/stepping-numbers/
/// Author : liuyubobobo
/// Time   : 2019-10-06

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// DFS
/// Time Complexity: O(2^10)
/// Space Complexity: O(2^10)
class Solution {
public:
    vector<int> countSteppingNumbers(int low, int high) {

        set<int> set;
        if(low == 0) set.insert(0);
        for (int start = 1; start <= 9; start++)
            dfs(to_string(high).size(), 1, (long long) start, low, high, set);


        return vector<int>(set.begin(), set.end());
    }

private:
    void dfs(int len, int index, long long num, long long low, long long high,
             set<int>& set){

        if(low <= num && num <= high) set.insert(num);

        if(index < len){
            int last = num % 10;
            if(last - 1 >= 0) dfs(len, index + 1, num * 10ll + (last - 1ll), low, high, set);
            if(last + 1 <= 9) dfs(len, index + 1, num * 10ll + (last + 1ll), low, high, set);
        }
    }
};


void print_vec(const vector<int>& vec){
    for(int e: vec) cout << e << " "; cout << endl;
}

int main() {

    print_vec(Solution().countSteppingNumbers(0, 21));
    // 0,1,2,3,4,5,6,7,8,9,10,12,21

    return 0;
}