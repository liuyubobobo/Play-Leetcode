/// Source : https://leetcode.com/problems/create-maximum-number/
/// Author : liuyubobobo
/// Time   : 2020-12-02

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


/// Mono Stack
/// Time Complexity: O(k * (|nums1| + |nums2|))
/// Space Complexity: O(|nums1| + |nums2|)
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {

        string s1 = "", s2 = "";
        for(int e: nums1) s1 += ('0' + e);
        for(int e: nums2) s2 += ('0' + e);

        string res(k, '0');
        for(int i = 0; i <= k; i ++){
            int sz1 = i, sz2 = k - i;
            if(sz1 >= 0 && sz1 <= nums1.size() && sz2 >= 0 && sz2 <= nums2.size()){
                string a = get(s1, sz1);
                string b = get(s2, sz2);
                assert(a.size() + b.size() == k);

                string tres = merge(a, b);
                assert(tres.size() == k);

                if(tres > res) res = tres;
            }
        }

        vector<int> ret;
        for(char c: res) ret.push_back(c - '0');
        return ret;
    }

private:
    string merge(const string& s1, const string& s2){

        int i = 0, j = 0;
        string res;
        while(i < s1.size() && j < s2.size()){
            if(s1.substr(i) > s2.substr(j)) res += s1[i ++];
            else res += s2[j ++];
        }
        if(j < s2.size()) res += s2.substr(j);
        else if(i < s1.size()) res += s1.substr(i);
        return res;
    }

    string get(const string& s, int sz){

        int remove = (int)s.size() - sz;
        assert(remove >= 0);

        string stack = "";
        for(char c: s){
            while(stack != "" && remove && c > stack.back())
                stack.pop_back(), remove --;
            stack += c;
        }
        while(stack.size() != sz) stack.pop_back();
        return stack;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << " "; cout << endl;
}

int main() {

    vector<int> numsa1 = {3, 4, 6, 5}, numsb1 = {9, 1, 2, 5, 8, 3};
    print_vec(Solution().maxNumber(numsa1, numsb1, 5));
    // 9 8 6 5 3

    vector<int> numsa2 = {6, 7}, numsb2 = {6, 0, 4};
    print_vec(Solution().maxNumber(numsa2, numsb2, 5));
    // 6 7 6 0 4

    vector<int> numsa3 = {3, 9}, numsb3 = {8, 9};
    print_vec(Solution().maxNumber(numsa3, numsb3, 3));
    // 9 8 9

    vector<int> numsa4 = {1,6,5,4,7,3,9,5,3,7,8,4,1,1,4};
    vector<int> numsb4 = {4,3,1,3,5,9};
    print_vec(Solution().maxNumber(numsa4, numsb4, 21));
    // 4,3,1,6,5,4,7,3,9,5,3,7,8,4,1,3,5,9,1,1,4

    return 0;
}
