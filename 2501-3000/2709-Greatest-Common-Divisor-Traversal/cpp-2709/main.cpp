/// Source : https://leetcode.com/problems/greatest-common-divisor-traversal/description/
/// Author : liuyubobobo
/// Time   : 2023-05-27

#include <iostream>
#include <vector>
#include <cassert>
#include <map>
#include <list>

using namespace std;


/// Sieve Table + UF
/// Time Complexity: O(n * log(max(nums[i])))
/// Space Complexity: O(n * log(max(nums[i])))
class UF{

private:
    vector<int> parent;
    int total;

public:
    UF(int n) : parent(n), total(n){
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
        total --;
    }

    int get_total(){
        return total;
    }
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {

        vector<int> sieve_table = sieve(*max_element(nums.begin(), nums.end()));
        map<int, vector<int>> table; // d -> index list
        for(int i = 0; i < nums.size(); i ++){
            int e = nums[i];
            while(e > 1){
                int p = sieve_table[e];
                table[p].push_back(i);
                while(e % p == 0) e /= p;
            }
        }

        UF uf(nums.size());
        for(const pair<int, vector<int>>& row: table){
            for(int i = 1; i < row.second.size(); i ++)
                uf.union_elements(row.second[i - 1], row.second[i]);
        }
        return uf.get_total() == 1;
    }

private:
    vector<int> sieve(int n){

        vector<int> table(n + 1, 0);
        vector<int> primes;
        table[0] = table[1] = 1;
        for(int i = 2; i <= n; i ++){
            if(table[i] == 0) {
                primes.push_back(i);
                table[i] = i;
            }
            for(int j = 0; j < primes.size() && primes[j] <= table[i] && i * primes[j] <= n; j ++)
                table[i * primes[j]] = primes[j];
        }
        return table;
    }
};


int main() {

    return 0;
}
