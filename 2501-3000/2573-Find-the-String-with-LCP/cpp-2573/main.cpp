/// Source : https://leetcode.com/problems/find-the-string-with-lcp/description/
/// Author : liuyubobobo
/// Time   : 2023-02-22

#include <iostream>
#include <vector>

using namespace std;


/// Construction and LCP
/// Time Complexity: O(n^2)
/// Space Complexity: O(n^2)
class UF{

private:
    vector<int> parent;

public:
    UF(int n) : parent(n){
        for(int i = 0 ; i < n ; i ++)
            parent[i] = i;
    }

    int find(int p){
        if(p != parent[p])
            parent[p] = find(parent[p]);
        return parent[p];
    }

    bool is_connected(int p, int q){
        return find(p) == find(q);
    }

    void union_elements(int p, int q){

        int p_root = find(p), q_root = find(q);

        if(p_root == q_root) return;

        parent[p_root] = q_root;
    }
};

class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {

        int n = lcp.size();
        UF uf(n);
        for(int i = 0 ; i < n; i ++)
            for(int j = 0 ; j < n; j ++)
                if(lcp[i][j] >= 1)
                    uf.union_elements(i, j);

        vector<char> parent2char(n, ' ');
        char next_char = 'a';
        string res(n, ' ');
        bool ok = true;
        for(int i = 0 ; i < n && ok; i ++){
            int p = uf.find(i);
            if(parent2char[p] == ' '){
                if(next_char > 'z') ok = false;
                else parent2char[p] = next_char ++;
            }
            res[i] = parent2char[p];
        }
        if(!ok) return "";

        if(check(n, res, lcp)) return res;
        return "";
    }

private:
    bool check(int n, const string& s, const vector<vector<int>>& A){
        vector<vector<int>> lcp(n, vector<int>(n, 0));
        for(int i = n - 1 ; i >= 0 ; i --)
            for(int j = n - 1 ; j >= 0 ; j --)
                if(s[i] == s[j]){
                    lcp[i][j] = 1 + ((i + 1 < n && j + 1 < n) ? lcp[i + 1][j + 1] : 0);
                }
        return lcp == A;
    }
};


int main() {

    vector<vector<int>> lcp2 = {{4,3,2,1},
                                {3,3,2,1},
                                {2,2,2,1},
                                {1,1,1,1}};
    cout << Solution().findTheString(lcp2) << endl;

    return 0;
}
