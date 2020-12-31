/// Source : https://leetcode.com/problems/k-similar-strings/description/
/// Author : liuyubobobo
/// Time   : 2018-06-21

#include <iostream>
#include <vector>
#include <cassert>
#include <unordered_map>

using namespace std;


/// Enumerate all circle combinations and using Memory Search
/// There're 55 different circle combinations in total!
///
/// Time Complexity: O(2^6 * 2^n)
/// Space Complexity: O(2^6 * 2^n)
class Solution {

private:
    unordered_map<string, int> dp;
    string empty_g;

public:
    int kSimilarity(string A, string B) {

        assert(A.size() == B.size());
        assert(A.size() > 0);
        if(A.size() == 1){
            assert(A[0] == B[0]);
            return 0;
        }

        vector<int> g(36, 0);
        empty_g = hash(g);
        int total_edge = 0;
        for(int i = 0 ; i < A.size() ; i ++)
            if(B[i] != A[i]) {
                g[(B[i] - 'a') * 6 + (A[i] - 'a')]++;
                total_edge ++;
            }

        vector<string> circles;
        for(int circle_length = 2 ; circle_length <= min(6, (int)A.size()) ; circle_length ++){
            vector<string> char_sets = pick(circle_length);
            for(string& p: char_sets){
                do{
                    bool ok = true;
                    for(int i = 1 ; i < p.size() ; i ++)
                        if(p[i] < p[0]){
                            ok = false;
                            break;
                        }

                    if(ok)
                        circles.push_back(p);
                }while(next_permutation(p.begin(), p.end()));
            }
        }
        // cout << "circles size : " << circles.size() << endl;
        // 55

        dp.clear();
        return total_edge - max_circle_num(g, circles);
    }

private:
    string hash(const vector<int>& g){
        string res = "";
        for(int i = 0 ; i < g.size() ; i ++)
            res += to_string(g[i]) + "#";
        return res;
    }

    int max_circle_num(vector<int>& g, const vector<string>& circles){

        string hashcode = hash(g);
        if(hashcode == empty_g)
            return 0;

        unordered_map<string, int>::iterator iter = dp.find(hashcode);
        if(iter != dp.end())
            return iter->second;

        int res = 0;
        for(const string& circle: circles)
            if(contains_circle(g, circle)){
                for(int i = 0 ; i < circle.size() ; i ++){
                    int u = circle[i] - 'a';
                    int v = circle[(i+1)%circle.size()] - 'a';
                    g[u * 6 + v] --;
                }

                res = max(res, 1 + max_circle_num(g, circles));

                for(int i = 0 ; i < circle.size() ; i ++){
                    int u = circle[i] - 'a';
                    int v = circle[(i+1)%circle.size()] - 'a';
                    g[u * 6 + v] ++;
                }
            }

        dp[hashcode] = res;
        return res;
    }

    bool contains_circle(const vector<int> g, const string& circle){
        for(int i = 0 ; i < circle.size() ; i ++){
            int u = circle[i] - 'a';
            int v = circle[(i + 1) % circle.size()] - 'a';
            if(g[u * 6 + v] == 0)
                return false;
        }
        return true;
    }

    vector<string> pick(int num){
        vector<string> res;
        pick("abcdef", num, res, 0, "");
        return res;
    }

    void pick(const string& s, int num, vector<string>& res, int start, const string& cur){
        if(num == 0){
            res.push_back(cur);
            return;
        }

        for(int i = start ; i <= (int)s.size() - num ; i ++)
            pick(s, num - 1, res, i + 1, cur + s[i]);

        return;
    }
};

int main() {

    string A1 = "ab";
    string B1 = "ba";
    cout << Solution().kSimilarity(A1, B1) << endl;
    // 1

    string A2 = "abc";
    string B2 = "bca";
    cout << Solution().kSimilarity(A2, B2) << endl;
    // 2

    string A3 = "abac";
    string B3 = "baca";
    cout << Solution().kSimilarity(A3, B3) << endl;
    // 2

    string A4 = "aabc";
    string B4 = "abca";
    cout << Solution().kSimilarity(A4, B4) << endl;
    // 2

    string A5 = "abcdefabcdefabcdef";
    string B5 = "edcfbebceafcfdabad";
    cout << Solution().kSimilarity(A5, B5) << endl;
    // 10

    return 0;
}