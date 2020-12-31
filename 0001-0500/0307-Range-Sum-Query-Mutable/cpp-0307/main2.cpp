/// Source : https://leetcode.com/problems/range-sum-query-mutable/description/
/// Author : liuyubobobo
/// Time   : 2019-08-11

#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <numeric>
#include <algorithm>

using namespace std;

/// Bucket
/// Time Complexity: init: O(n)
///                  update: O(logn)
///                  query: O(sqrt(n))
/// Space Complexity: O(n)
class NumArray {

private:
    vector<int> bucket, arr, sum;
    const int bucket_sz;

public:
    NumArray(vector<int> nums): arr(nums.begin(), nums.end()), bucket_sz(sqrt(arr.size())) {

        bucket.push_back(0);
        while(bucket.back() != nums.size()){
            int l = bucket.back();
            int r = min(bucket.back() + bucket_sz, (int)nums.size());
            bucket.push_back(r);
            sum.push_back(accumulate(nums.begin() + l, nums.begin() + r, 0));
        }

//        cout << "bucket_sz = " << bucket_sz << endl;
//        for(int e: bucket) cout << e << " "; cout << endl;
//        for(int e: sum) cout << e << " "; cout << endl;
    }

    void update(int i, int val) {
        int o = arr[i];
        arr[i] = val;

        vector<int>::iterator iter = lower_bound(bucket.begin(), bucket.end(), i);
        int index = iter - bucket.begin();
        if(bucket[index] != i) index --;

        sum[index] = sum[index] - o + val;
    }

    int sumRange(int i, int j) {

        vector<int>::iterator iter = lower_bound(bucket.begin(), bucket.end(), i);
        int index = iter - bucket.begin();
        if(bucket[index] != i) index --;

        if(i >= bucket[index] && j < bucket[index + 1]) return sumNaive(i, j);

        int res = sumNaive(i, bucket[index + 1] - 1);
        index ++;
        while(j >= bucket[index]){

            if(j < bucket[index + 1]) res += sumNaive(bucket[index], j);
            else res += sum[index];

            index ++;
        }
        return res;
    }

private:
    int sumNaive(int i, int j){
        return accumulate(arr.begin() + i, arr.begin() + (j + 1), 0);
    }
};


int main() {

    vector<int> nums1 = {1, 3, 5};
    NumArray obj1(nums1);

    cout << obj1.sumRange(0, 2) << endl;
    obj1.update(1, 2);
    cout << obj1.sumRange(0, 2) << endl;

    cout << endl;

    // ---

    vector<int> nums2 = {0, 9, 5, 7, 3};
    NumArray obj2(nums2);

    cout << obj2.sumRange(4, 4) << endl;
    cout << obj2.sumRange(2, 4) << endl;

    return 0;
}