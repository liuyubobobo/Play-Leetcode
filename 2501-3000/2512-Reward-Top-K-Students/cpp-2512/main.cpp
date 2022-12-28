/// Source : https://leetcode.com/problems/reward-top-k-students/description/
/// Author : liuyubobobo
/// Time   : 2022-10-28

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


/// Brute Force
/// Time Complexity: O(nlogn)
/// Space Complexity: O(|pset| + |nset| + n)
class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {

        set<string> pset(positive_feedback.begin(), positive_feedback.end());
        set<string> nset(negative_feedback.begin(), negative_feedback.end());

        int n = report.size();
        vector<pair<int, int>> v(n); // score, id;
        for(int i = 0; i < n; i ++)
            v[i] = {get_score(report[i], pset, nset), student_id[i]};

        sort(v.begin(), v.end(), [](const pair<int, int>& p1, const pair<int, int>& p2){
            if(p1.first != p2.first) return p1.first > p2.first;
            return p1.second < p2.second;
        });

        vector<int> res(k);
        for(int i = 0; i < k; i ++) res[i] = v[i].second;
        return res;
    }

private:
    int get_score(const string& s, const set<string>& pset, const set<string>& nset){

        int res = 0, n = s.size();
        for(int start = 0, i = 1; i <= n; i ++){
            if(i == n || s[i] == ' '){
                string word = s.substr(start, i - start);
                if(pset.count(word)) res += 3;
                if(nset.count(word)) res -= 1;

                start = i + 1;
                i = start;
            }
        }
        return res;
    }
};


int main() {

    return 0;
}
