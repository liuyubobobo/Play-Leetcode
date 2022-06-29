/// Source : https://leetcode.com/problems/queue-reconstruction-by-height/
/// Author : liuyubobobo
/// Time   : 2022-06-29

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Greedy
/// Time Complexity: O(nlogn + n^2)
/// Space Complexity: O(n)
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {

        sort(people.begin(), people.end(),
             [](const vector<int>& p1, const vector<int>& p2){
            if(p1[0] != p2[0]) return p1[0] > p2[0];
            return p1[1] < p2[1];
        });

        vector<vector<int>> res = {people[0]};
        for(int i = 1; i < people.size(); i ++){

            int j = 0, cnt = 0;
            for(; j < (int)res.size() && cnt < people[i][1]; j ++){
                if(res[j][0] >= people[i][0]) cnt ++;
            }

            auto iter = res.begin() + j;
            res.insert(iter, people[i]);
        }
        return res;
    }
};


void print_vec(const vector<vector<int>>& v){
    for(const vector<int>& p: v)
        cout << '(' << p[0] << ',' << p[1] << ')';
    cout << '\n';
}

int main() {

    vector<vector<int>> people1 = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    print_vec(Solution().reconstructQueue(people1));

    return 0;
}
