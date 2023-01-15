/// Source : https://leetcode.com/problems/find-the-index-of-the-large-integer/
/// Author : liuyubobobo
/// Time   : 2023-01-14

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;


/// Binary Search
/// Time Compelxity: O(logn)
/// Space Compelxity: O(1)

// This is the ArrayReader's API interface.
// You should not implement it, or speculate about its implementation
class ArrayReader {

private:
    vector<int> data;
    vector<int> presum;

public:
    ArrayReader(const vector<int>& arr): data(arr), presum(data.size() + 1, 0){

        int n = arr.size();
        for(int i = 0; i < n; i ++) presum[i + 1] = presum[i] + data[i];
    }

    // Compares the sum of arr[l..r] with the sum of arr[x..y]
    // return 1 if sum(arr[l..r]) > sum(arr[x..y])
    // return 0 if sum(arr[l..r]) == sum(arr[x..y])
    // return -1 if sum(arr[l..r]) < sum(arr[x..y])
    int compareSub(int l, int r, int x, int y){
        int sum1 = presum[r + 1] - presum[l], sum2 = presum[y + 1] - presum[x];
        if(sum1 > sum2) return 1;
        return sum1 == sum2 ? 0 : -1;
    }

    // Returns the length of the array
    int length(){
        return data.size();
    }
};

class Solution {
public:
    int getIndex(ArrayReader &reader) {

        int n = reader.length();
        return search(reader, 0, n - 1);
    }

private:
    int search(ArrayReader &reader, int l, int r){

        if(l == r) return l;

        int len = (r - l + 1);
        if(len & 1){
            int res = search(reader, l, r - 1);
            return res == -1 ? r : res;
        }

        int mid = (l + r) / 2;
        int x = reader.compareSub(l, mid, mid + 1, r);
        if(x == 1) return search(reader, l, mid);
        else if(x == 0) return -1;
        else return search(reader, mid + 1, r);
    }
};


int main() {

    vector<int> nums1 = {6, 6, 12};
    ArrayReader reader1(nums1);
    cout << Solution().getIndex(reader1) << '\n';
    // 2

    vector<int> nums2 = {7, 7, 7, 7, 10, 7, 7, 7};
    ArrayReader reader2(nums2);
    cout << Solution().getIndex(reader2) << '\n';
    // 4

    return 0;
}
