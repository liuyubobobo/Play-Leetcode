/// Source : https://leetcode-cn.com/contest/cnunionpay-2022spring/problems/lCh58I/
/// Author : liuyubobobo
/// Time   : 2022-03-13

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Using Hash and Map
/// It seems in Leetcode, unordered_map is faster than map in most cases
/// Especially when the test data is large
/// But unprdered_map is dangerouse in codeforces...
///
/// Time Complexity: O(n * 2^4)
/// Space Complexity: O(n + max_skills^2)
class Solution {

private:
    const long long MOD = 1e9 + 7;

public:
    int coopDevelop(vector<vector<int>>& skills) {

        for(vector<int>& skill: skills)
            sort(skill.begin(), skill.end());
        sort(skills.begin(), skills.end(),
             [](const vector<int>& skill1, const vector<int>& skill2){
                 return skill1.size() < skill2.size();
             });

        unordered_map<long long, int> f;
        long long no = 0;
        for(const vector<int>& skill: skills){
            no += contains(f, skill);
            f[get_hash(skill)] ++;
        }

        long long n = skills.size();
        return (n * (n - 1) / 2 - no) % MOD;
    }

private:
    long long contains(const unordered_map<long long, int> & f,
                       const vector<int>& skills){

        long long res = 0;
        for(int i = 0; i < skills.size(); i ++){
            auto iter = f.find(get_hash({skills[i]}));
            res += iter == f.end() ? 0 : iter->second;
        }

        if(skills.size() == 1) return res;

        for(int i = 0; i < skills.size(); i ++)
            for(int j = i + 1; j < skills.size(); j ++){
                auto iter = f.find(get_hash({skills[i], skills[j]}));
                res += iter == f.end() ? 0 : iter->second;
            }

        if(skills.size() == 2) return res;

        for(int i = 0; i < skills.size(); i ++)
            for(int j = i + 1; j < skills.size(); j ++)
                for(int k = j + 1; k < skills.size(); k ++){
                    auto iter = f.find(get_hash({skills[i], skills[j], skills[k]}));
                    res += iter == f.end() ? 0 : iter->second;
                }

        if(skills.size() == 3) return res;

        res += f.find(get_hash(skills)) != f.end();
        return res;
    }

    long long get_hash(const vector<int>& v){
        long long res = 0;
        for(int e: v)
            res = res * 1001ll + e;
        return res;
    }
};


int main() {

    vector<vector<int>> skills1 = {{1, 2, 3}, {3}, {2, 4}};
    cout << Solution().coopDevelop(skills1) << '\n';
    // 2

    vector<vector<int>> skills2 = {{3}, {6}};
    cout << Solution().coopDevelop(skills2) << '\n';
    // 1

    vector<vector<int>> skills3 = {{2},{3,5,7},{2,3,5,6},{3,4,8},{2,6},{3,4,8},{3}};
    cout << Solution().coopDevelop(skills3) << '\n';
    // 13

    return 0;
}
