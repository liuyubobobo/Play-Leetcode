/// Source : https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
/// Author : liuyubobobo
/// Time   : 2021-05-16

#include <iostream>
#include <vector>

using namespace std;


/// Trie
/// Time Complexity: O(nlog(max_num)
/// Space Complexity: O(n * log(max_num))
class Trie{

private:
    class Node{
    public:
        Node* next[2];
        Node(){
            next[0] = next[1] = nullptr;
        };
    };

    Node* root;

public:
    Trie(){
        root = new Node();
    }

    void add(const vector<int>& nums){

        Node* pre = root;
        for(int e: nums){
            if(!pre->next[e])
                pre->next[e] = new Node();
            pre = pre->next[e];
        }
    }

    int query(int num, const vector<int>& nums){

        Node* pre = root;
        int x = 0;
        for(int e: nums){
            if(pre->next[1 - e])
                x = x * 2 + (1 - e), pre = pre->next[1 - e];
            else
                x = x * 2 + e, pre = pre->next[e];
        }
        return num^x;
    }
};

class Solution {

public:
    int findMaximumXOR(vector<int>& nums) {

        int maxv = *max_element(nums.begin(), nums.end());
        int B = 0;
        while(maxv) B ++, maxv >>= 1;

        Trie trie;
        int res = 0;
        for(int num: nums){

            vector<int> numb = get_binary(num, B);
            trie.add(numb);
            res = max(res, trie.query(num, numb));
        }
        return res;
    }

private:
    vector<int> get_binary(int num, int B){

        vector<int> res(B);
        for(int i = 0; i < B; i ++)
            res[i] = num & 1, num >>= 1;
        reverse(res.begin(), res.end());
        return res;
    }
};


int main() {

    vector<int> nums1 = {3, 10, 5, 25, 2, 8};
    cout << Solution().findMaximumXOR(nums1) << endl;
    // 28

    return 0;
}
