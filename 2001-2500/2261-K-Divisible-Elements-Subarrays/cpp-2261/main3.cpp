/// Source : https://leetcode.com/problems/k-divisible-elements-subarrays/
/// Author : liuyubobobo
/// Time   : 2022-05-01

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Trie
/// Time Complexity: O(n^3)
/// Space Complexity: O(n^3)
class Trie {

private:
    class Node{

    public:
        map<int, Node*> next;
        bool is_end;

        Node() : is_end(false) {};
    };

    Node* root;
    int sz;

public:
    Trie() : root(new Node()), sz(0) {}

    void insert(const vector<int>& word, int l, int r) {

        Node* cur = root;
        for(int i = l; i <= r; i ++){
            int c = word[i];
            if(!cur->next.count(c))
                cur->next[c] = new Node();
            cur = cur->next[c];

            if(!cur->is_end)
                cur->is_end = true, sz ++;
        }
    }

    int size(){
        return sz;
    }
};

class Solution {

public:
    int countDistinct(vector<int>& nums, int k, int p) {

        int n = nums.size();
        vector<int> k_divisible(n, 0);
        for(int i = 0; i < n; i ++) k_divisible[i] = (nums[i] % p == 0);

        vector<int> presum(n + 1, 0);
        for(int i = 0; i < n; i ++) presum[i + 1] = presum[i] + k_divisible[i];

        Trie trie;
        for(int l = 0; l < n; l ++){
            auto iter = upper_bound(presum.begin(), presum.end(), presum[l] + k);
            int index = iter - presum.begin() - 1;
            int r = index - 1;
            if(l <= r)
                trie.insert(nums, l, r);
        }
        return trie.size();
    }
};


int main() {

    vector<int> nums1 = {2, 3, 3, 2, 2};
    cout << Solution().countDistinct(nums1, 2, 2) << '\n';
    // 11

    vector<int> nums2 = {1, 2, 3, 4};
    cout << Solution().countDistinct(nums2, 4, 1) << '\n';
    // 10

    return 0;
}
