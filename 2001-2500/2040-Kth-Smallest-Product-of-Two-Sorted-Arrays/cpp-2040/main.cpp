/// Source : https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/
/// Author : liuyubobobo
/// Time   : 2021-10-18

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// Binary Search
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {

        vector<long long> neg1, zero1, pos1;
        for(int e: nums1) {
            if (e < 0) neg1.push_back(e);
            else if (e == 0) zero1.push_back(e);
            else pos1.push_back(e);
        }

        vector<long long> neg2, zero2, pos2;
        for(int e: nums2)
            if(e < 0) neg2.push_back(e);
            else if(e == 0) zero2.push_back(e);
            else pos2.push_back(e);

        long long neg_cnt = (long long)neg1.size() * pos2.size() + (long long)neg2.size() * pos1.size();
        long long zero_cnt = (long long)zero1.size() * nums2.size() + (long long)zero2.size() * nums1.size() - (long long)zero1.size() * zero2.size();
        long long pos_cnt = (long long)neg1.size() * neg2.size() + (long long)pos1.size() * pos2.size();
        assert(neg_cnt + zero_cnt + pos_cnt == (long long)nums1.size() * nums2.size());

        for(long long& e: neg1) e = -e;
        for(long long& e: neg2) e = -e;
        reverse(neg1.begin(), neg1.end());
        reverse(neg2.begin(), neg2.end());

        if(k <= neg_cnt)
            return - solve(neg1, pos2, neg2, pos1, neg_cnt + 1 - k);
        else if(k <= neg_cnt + zero_cnt)
            return 0;

        return solve(neg1, neg2, pos1, pos2, k - neg_cnt - zero_cnt);
    }

private:
    long long solve(const vector<long long>& a1, const vector<long long>& b1,
                    const vector<long long>& a2, const vector<long long>& b2, long long k){

        assert(k > 0 && k <= (long long)a1.size() * b1.size() + (long long)a2.size() * b2.size());

        long long l = 1, r = 0;
        if(!a1.empty() && !b1.empty()) r = max(r, a1.back() * b1.back());
        if(!a2.empty() && !b2.empty()) r = max(r, a2.back() * b2.back());
        assert(r);

        while(l < r){
            long long mid = (l + r) / 2;
            if(count(a1, b1, a2, b2, mid) >= k) r = mid;
            else l = mid + 1;
        }
        return l;
    }

    long long count(const vector<long long>& a1, const vector<long long>& b1,
                    const vector<long long>& a2, const vector<long long>& b2, long long t){

        long long res = 0;

        int r = b1.size() - 1;
        for(long long e: a1){
            long long x = t / e;
            while(r >= 0 && b1[r] > x) r --;
            res += r + 1;
        }

        r = b2.size() - 1;
        for(long long e: a2){
            long long x = t / e;
            while(r >= 0 && b2[r] > x) r --;
            res += r + 1;
        }
        return res;
    }
};


int main() {

    vector<int> nums11 = {2, 5}, nums12 = {3, 4};
    cout << Solution().kthSmallestProduct(nums11, nums12, 2) << endl;
    // 8

    vector<int> nums21 = {-4, -2, 0, 3}, nums22 = {2, 4};
    cout << Solution().kthSmallestProduct(nums21, nums22, 6) << endl;
    // 0

    vector<int> nums31 = {-2, -1, 0, 1, 2}, nums32 = {-3, -1, 2, 4, 5};
    cout << Solution().kthSmallestProduct(nums31, nums32, 3) << endl;
    // -6

    vector<int> nums41 = {-9, -9, -8, -6, -1, 0, 5, 8, 10, 10}, nums42 = {0, 4, 9};
    cout << Solution().kthSmallestProduct(nums41, nums42, 19) << endl;
    // 0

    vector<int> nums51 = {1, 9, 10, 10}, nums52 = {-6, -4, -4, -2, -2, 1, 1, 2, 9};
    cout << Solution().kthSmallestProduct(nums51, nums52, 22) << endl;
    // 1

    return 0;
}
