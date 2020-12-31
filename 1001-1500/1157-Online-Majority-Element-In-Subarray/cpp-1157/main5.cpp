/// Source : https://leetcode.com/problems/online-majority-element-in-subarray/
/// Author : liuyubobobo
/// Time   : 2019-08-11

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cassert>

using namespace std;


/// Bucket
/// if we split the interval [l, r] into several sub-intervals
/// the more than half majority should also be a more than half majority int at least one sub-interval
///
/// Time Complexity: init: O(nlogn)
///                  query: O(sqrt(n) * logn)
/// Space Complexity: O(n)
class MajorityChecker {

private:
    vector<int> arr;
    unordered_map<int, vector<int>> indexes;

    vector<int> bucket;
    int bucket_sz;
    vector<int> bucket_majority;

public:
    MajorityChecker(vector<int>& arr): arr(arr.begin(), arr.end()), bucket_sz(sqrt(arr.size())){

        for(int i = 0; i < arr.size(); i ++)
            indexes[arr[i]].push_back(i);

        bucket.push_back(0);
        while(bucket.back() != arr.size()){
            int l = bucket.back();
            int r = min(bucket.back() + bucket_sz, (int)arr.size());
            bucket.push_back(r);
            bucket_majority.push_back(vote(l, r - 1));
        }

//        for(int e: bucket) cout << e << " "; cout << endl;
//        for(int e: bucket_majority) cout << e << " "; cout << endl;
    }

    int query(int left, int right, int threshold) {

        vector<int>::iterator iter = lower_bound(bucket.begin(), bucket.end(), left);
        int b = iter - bucket.begin();
        if(bucket[b] > left) b --;
        assert(b >= 0 && b + 1 < bucket.size());
        if(right < bucket[b + 1]){
            int e = vote(left, right);
            if(get_freq(e, left, right) >= threshold) return e;
            return -1;
        }

        while(bucket[b] <= right){
            int f = get_freq(bucket_majority[b], left, right);
            int e = bucket_majority[b];
            if(left > bucket[b]){
                e = vote(left, bucket[b + 1]);
                f = get_freq(e, left, right);
            }
            else if(right < bucket[b + 1] - 1){
                e = vote(bucket[b], right);
                f = get_freq(e, left, right);
            }
            if(f >= threshold) return e;
            b ++;
        }
        return -1;
    }

private:
    int vote(int left, int right){

        int count = 1, res = arr[left];
        for(int i = left + 1; i <= right; i ++){
            if(count == 0) res = arr[i];
            count += (res == arr[i] ? 1 : -1);
        }
        return res;
    }

    int get_freq(int e, int left, int right){
        const vector<int>& v = indexes[e];
        vector<int>:: const_iterator iter1 = lower_bound(v.begin(), v.end(), left);
        vector<int>:: const_iterator iter2 = upper_bound(v.begin(), v.end(), right);
        return iter2 - iter1;
    }
};


int main() {

    vector<int> arr1 = {1,1,2,2,1,1};
    MajorityChecker checker1(arr1);
    cout << checker1.query(0, 5, 4) << endl; // 1
    cout << checker1.query(0, 3, 3) << endl; // -1
    cout << checker1.query(2, 3, 2) << endl; // 2

    vector<int> arr2 = {2,2,2,2,1,2,2,1,1,1,2,1,2,1,2,2};
    MajorityChecker checker2(arr2);
    cout << checker2.query(0, 13, 10) << endl; // 1
    cout << checker2.query(4, 12, 8) << endl;  // -1
    cout << checker2.query(0, 12, 13) << endl; // -1
    cout << checker2.query(4, 14, 10) << endl; // -1
    cout << checker2.query(0, 4, 4) << endl; // 2
    cout << checker2.query(13, 13, 1) << endl; // -1
    cout << checker2.query(10, 13, 3) << endl; // -1
    cout << checker2.query(4, 7, 3) << endl; // -1
    cout << checker2.query(3, 5, 2) << endl; // 2
    cout << checker2.query(6, 14, 7) << endl; // -1

    return 0;
}