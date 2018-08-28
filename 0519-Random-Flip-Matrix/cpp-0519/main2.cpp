/// Source : https://leetcode.com/problems/random-flip-matrix/description/
/// Author : liuyubobobo
/// Time   : 2018-08-28

#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>
#include <algorithm>
#include <cassert>

using namespace std;


/// Using Buckets to find the kth unflipped position
///
/// Time Complexty: O(sqrt(m*n))
/// Space Complexity: O(min(len(call of flip), m*n))
class Solution {

private:
    int m, n;
    int bucket_sz;
    vector<unordered_set<int>> buckets;
    int left;

public:
    Solution(int n_rows, int n_cols): m(n_rows), n(n_cols) {

        bucket_sz = sqrt(m * n);
        reset();
    }

    vector<int> flip() {

        int randNum = rand() % left;
        left --;

        int index = 0, ret = -1;
        for(int i = 0; i < buckets.size(); i ++){
            int left_in_bucket = min(bucket_sz, m * n - i * bucket_sz) - buckets[i].size();
            if(randNum >= index && randNum < index + left_in_bucket){
                int k = randNum - index;
                for(int j = i * bucket_sz; j < min((i + 1) * bucket_sz, m * n); j ++)
                    if(buckets[i].find(j) == buckets[i].end()){
                        if(!k){
                            ret = j;
                            buckets[i].insert(j);
                            break;
                        }
                        k --;
                    }
                if(ret != -1)
                    break;
            }
            else
                index += left_in_bucket;
        }
        assert(ret != -1);
        return {ret / n, ret % n};
    }

    void reset() {

        buckets.clear();
        for(int i = 0; i < m * n; i += bucket_sz)
            buckets.push_back(unordered_set<int>());
        left = m * n;
    }

    static void print_vec(const vector<int>& vec){
        for(int e: vec)
            cout << e << " ";
        cout << endl;
    }
};


int main() {

    Solution solution(2, 2);
    for(int i = 0; i < 4; i ++)
        Solution::print_vec(solution.flip());

    return 0;
}