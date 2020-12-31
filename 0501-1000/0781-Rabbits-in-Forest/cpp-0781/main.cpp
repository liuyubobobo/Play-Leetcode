/// Source : https://leetcode.com/problems/rabbits-in-forest/description/
/// Author : liuyubobobo
/// Time   : 2010-02-11

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/// Count
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int numRabbits(vector<int>& answers) {

        unordered_map<int, int> count;
        for(int ans: answers)
            count[ans] ++;

        int res = 0;
        for(const pair<int, int>& p: count){
            int group_num = p.second / (p.first + 1);
            if(p.second % (p.first + 1))
                group_num ++;

            res += group_num * (p.first + 1);
        }

        return res;
    }
};

int main() {

    vector<int> answers1 = {1, 1, 2};
    cout << Solution().numRabbits(answers1) << endl;

    vector<int> answers2 = {10, 10, 10};
    cout << Solution().numRabbits(answers2) << endl;

    vector<int> answers3 = {};
    cout << Solution().numRabbits(answers3) << endl;

    return 0;
}