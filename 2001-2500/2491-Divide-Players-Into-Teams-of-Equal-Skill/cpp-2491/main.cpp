/// Source : https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/description/
/// Author : liuyubobobo
/// Time   : 2022-12-19

#include <iostream>
#include <set>
#include <vector>

using namespace std;


/// Using Set
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {

        int n = skill.size();

        multiset<int> s;
        int sum = 0;
        for(int e: skill) s.insert(e), sum += e;

        if(sum % (n / 2)) return -1;
        int t = sum / (n / 2);

        long long res = 0;
        while(!s.empty()){
            int a = *s.begin();
            s.erase(s.begin());
            int b = t - a;
            auto iter = s.find(b);
            if(iter == s.end()) return -1;
            s.erase(iter);
            res += a * b;
        }
        return res;
    }
};


int main() {

    return 0;
}
