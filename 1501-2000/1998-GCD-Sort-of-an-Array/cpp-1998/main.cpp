/// Source : https://leetcode.com/problems/gcd-sort-of-an-array/
/// Author : liuyubobobo
/// Time   : 2021-09-04

#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;


/// Prime Shieve + UF
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
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
    bool gcdSort(vector<int>& nums) {

        int maxv = *max_element(nums.begin(), nums.end());
        vector<int> table = get_table(maxv + 1);

        int n = nums.size();
        map<int, vector<int>> f2pos;
        for(int i = 0; i < n; i ++){
            set<int> fs = get_factors(nums[i], table);
            for(int f: fs) f2pos[f].push_back(i);
        }

        UF uf(n);
        for(const pair<int, vector<int>>& p: f2pos){
            for(int i = 1; i < p.second.size(); i ++)
                uf.union_elements(p.second[i - 1], p.second[i]);
        }

        map<int, vector<int>> cc;
        for(int i = 0; i < n; i ++)
            cc[uf.find(i)].push_back(i);

        vector<int> res(n);
        for(const pair<int, vector<int>>& p: cc){
            vector<int> data;
            for(int e: p.second) data.push_back(nums[e]);
            sort(data.begin(), data.end());
            for(int i = 0; i < p.second.size(); i ++)
                res[p.second[i]] = data[i];
        }

        for(int i = 1; i < n; i ++)
            if(res[i] < res[i - 1]) return false;
        return true;
    }

private:
    set<int> get_factors(int num, const vector<int>& table){

        set<int> factors;
        while(num != 1){
            factors.insert(table[num]);
            num /= table[num];
        }
        if(factors.size() == 0) factors.insert(1);
        return factors;
    }

    vector<int> get_table(int n){

        vector<int> table(n, 0);
        table[1] = 1;
        for(int i = 2; i < n; i ++)
            if(table[i] == 0)
                for(int j = i; j < n; j += i) table[j] = i;
        return table;
    }
};


int main() {

    vector<int> nums1 = {7, 21, 3};
    cout << Solution().gcdSort(nums1) << endl;
    // 1

    vector<int> nums2 = {5, 2, 6, 2};
    cout << Solution().gcdSort(nums2) << endl;
    // 0

    vector<int> nums3 = {10, 5, 9, 3, 15};
    cout << Solution().gcdSort(nums3) << endl;
    // 1

    return 0;
}
