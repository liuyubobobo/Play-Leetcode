/// Source : https://leetcode.com/problems/lexicographically-smallest-equivalent-string/description/
/// Author : liuyubobobo
/// Time   : 2023-01-14

#include <iostream>
#include <vector>

using namespace std;


/// UF
/// Time Complexity: O(n)
/// Space Compelxity: O(1)
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
    string smallestEquivalentString(string s1, string s2, string baseStr) {

        UF uf(26);
        for(int i = 0; i < s1.size(); i ++)
            uf.union_elements(s1[i] - 'a', s2[i] - 'a');

        vector<char> min_char(26, 'z');
        for(int i = 0; i < 26; i ++){
            int p = uf.find(i);
            min_char[p] = min(min_char[p], (char)('a' + i));
        }

        string res(baseStr.size(), ' ');
        for(int i = 0; i < baseStr.size(); i ++)
            res[i] = min_char[uf.find(baseStr[i] - 'a')];
        return res;
    }
};


int main() {

    return 0;
}
