/// Source : https://leetcode.com/problems/longest-substring-of-one-repeating-character/
/// Author : liuyubobobo
/// Time   : 2022-03-19

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <climits>
#include <cassert>

using namespace std;


/// Using Tree Map and TreeSet to store segments
/// Time Complexity: O(nlogn + qlogn)
/// Space Complexity: O(n)
class Solution {
private:
    map<pair<int, int>, char> segs;
    multiset<int> lens;

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {

        for(int start = 0, i = 1; i <= s.size(); i ++)
            if(i == s.size() || s[i] != s[start]){
                segs[{start, i - 1}] = s[start];
                lens.insert(i - start);
                start = i;
            }

        vector<int> res(queryCharacters.size());
        for(int q = 0; q < queryCharacters.size(); q ++){
            int index = queryIndices[q], qch = queryCharacters[q];

            auto iter = segs.upper_bound({index, INT_MAX});
            iter --;

            int l = iter->first.first, r = iter->first.second;
            char och = iter->second;
            if(qch != och){

                segs.erase(iter);
                lens.erase(lens.find(r - l + 1));

                if(l <= index - 1){
                    segs[{l, index - 1}] = och;
                    lens.insert(index - 1 - l + 1);
                }
                if(index + 1 <= r){
                    segs[{index + 1, r}] = och;
                    lens.insert(r - (index + 1) + 1);
                }
                insert(index, index, qch);
            }

            res[q] = *lens.rbegin();
        }
        return res;
    }

private:
    void insert(int insert_l, int insert_r, char ch){

        auto iter = segs.upper_bound({insert_l, INT_MAX});
        if(iter != segs.end() && iter->second == ch){
            int l = iter->first.first, r = iter->first.second;
            segs.erase(iter);
            lens.erase(lens.find(r - l + 1));

            insert(insert_l, r, ch);
            return;
        }

        iter = segs.upper_bound({insert_l, INT_MAX});
        if(iter != segs.begin()){
            iter --;
            if(iter->second == ch){
                int l = iter->first.first, r = iter->first.second;
                segs.erase(iter);
                lens.erase(lens.find(r - l + 1));

                segs[{l, insert_r}] = ch;
                lens.insert(insert_r - l + 1);
                return;
            }
        }

        segs[{insert_l, insert_r}] = ch;
        lens.insert(insert_r - insert_l + 1);
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << ' '; cout << '\n';
}

int main() {

    vector<int> q1 = {1, 3, 3};
    print_vec(Solution().longestRepeating("babacc", "bcb", q1));
    // 3 3 4

    vector<int> q2 = {2, 1};
    print_vec(Solution().longestRepeating("abyzz", "aa", q2));
    // 2 3

    return 0;
}
