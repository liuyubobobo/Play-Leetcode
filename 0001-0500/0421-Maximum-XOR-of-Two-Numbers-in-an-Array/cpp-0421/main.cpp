#include <iostream>
#include <vector>

using namespace std;


class Solution {

public:
    int findMaximumXOR(vector<int>& nums) {

        int maxv = *max_element(nums.begin(), nums.end());
        int B = 0;
        while(maxv) B ++, maxv >>= 1;

        vector<pair<int, int>> trie(1, {-1, -1});

        int res = 0;
        for(int num: nums){

            vector<int> numb = get_binary(num, B);

            res = max(res, query(trie));
            add(trie, 0, num);
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

    return 0;
}
