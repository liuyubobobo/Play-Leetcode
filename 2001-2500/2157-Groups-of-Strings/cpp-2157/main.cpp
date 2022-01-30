/// Source : https://leetcode.com/problems/groups-of-strings/
/// Author : liuyubobobo
/// Time   : 2022-01-29

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;


/// UF
/// Time Complexity: O(26 * 26 * n)
/// Space Complexity: O(2^26 + n)
class UF{

private:
    vector<int> parent, sz;

public:
    UF(int n) : parent(n), sz(n, 1){
        for(int i = 0 ; i < n ; i ++)
            parent[i] = i;
    }

    int find(int p){
        if(p != parent[p])
            parent[p] = find(parent[p]);
        return parent[p];
    }

    bool is_connected(int p , int q){
        return find(p) == find(q);
    }

    void union_elements(int p, int q){

        int p_root = find(p), q_root = find(q);

        if(p_root == q_root) return;

        parent[p_root] = q_root;
        sz[q_root] += sz[p_root];
    }

    int size(int p){
        return sz[find(p)];
    }
};

class Solution {
public:
    vector<int> groupStrings(vector<string>& words) {

        int n = words.size();

        vector<int> data(n);
        for(int i = 0; i < n; i ++){
            int state = 0;
            for(char c: words[i])
                state |= (1 << (c - 'a'));
            data[i] = state;
        }

        sort(data.begin(), data.end());

        unordered_map<int, int> state2index;
        for(int i = 0; i < n; i ++) state2index[data[i]] = i;

        UF uf(n);
        for(int start = 0, i = 1; i <= n; i ++){

            if(i < n && data[i] == data[start]) continue;

            for(int index = start + 1; index < i; index ++)
                uf.union_elements(start, index);

            for(int p = 0; p < 26; p ++){
                int state = data[start] ^ (1 << p);
                auto iter = state2index.find(state);
                if(iter != state2index.end()){
                    uf.union_elements(start, iter->second);
                }
            }

            for(int p1 = 0; p1 < 26; p1 ++){
                if(data[start] & (1 << p1)) continue;
                // data[i][p1] = 0;
                for(int p2 = 0; p2 < 26; p2 ++){
                    if((data[start] & (1 << p2)) == 0) continue;
                    // data[i][p2] = 1;
                    int state = data[start] ^ (1 << p1) ^ (1 << p2);
                    auto iter = state2index.find(state);
                    if(iter != state2index.end()){
                        uf.union_elements(start, iter->second);
                    }
                }
            }

            start = i;
        }

        unordered_set<int> groups;
        int max_sz = 0;
        for(int i = 0; i < n; i ++){
            groups.insert(uf.find(i));
            max_sz = max(max_sz, uf.size(i));
        }
        return {(int)groups.size(), max_sz};
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << ' '; cout << '\n';
}

int main() {

    vector<string> words1 = {"a", "b", "ab", "cde"};
    print_vec(Solution().groupStrings(words1));
    // 2, 3

    vector<string> words2 = {"a", "ab", "abc"};
    print_vec(Solution().groupStrings(words2));
    // 1, 3

    vector<string> words3 = {"a", "b", "bc", "cd"};
    print_vec(Solution().groupStrings(words3));
    // 1, 4

    vector<string> words4 = {"a", "z", "bc", "zb"};
    print_vec(Solution().groupStrings(words4));
    // 1, 4

    return 0;
}
