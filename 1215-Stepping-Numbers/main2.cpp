/// Source : https://leetcode.com/problems/stepping-numbers/
/// Author : liuyubobobo
/// Time   : 2019-10-06

#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;


/// BFS
/// Time Complexity: O(2^10)
/// Space Complexity: O(2^10)
class Solution {
public:
    vector<int> countSteppingNumbers(long long low, long long high) {

        set<int> set;
        if(low == 0) set.insert(0);

        queue<long long> q;
        for(int i = 1; i <= 9; i ++) q.push(i);
        while(!q.empty()){
            long long num = q.front();
            q.pop();

            if(low <= num && num <= high) set.insert(num);
            else if(num > high) continue;

            int last = num % 10;
            if(last - 1 >= 0) q.push(num * 10ll + (last - 1ll));
            if(last + 1 <= 9) q.push(num * 10ll + (last + 1ll));
        }

        return vector<int>(set.begin(), set.end());
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