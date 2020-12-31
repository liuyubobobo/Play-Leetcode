/// Source : https://leetcode.com/problems/find-in-mountain-array/
/// Author : liuyubobobo
/// Time   : 2019-06-22

#include <iostream>

using namespace std;


/// Find peak and then Using Binary Search
/// Time Complexity: O(logn)
/// Space Complexity: O(logn)
class MountainArray {
public:
    int get(int index){return -1;}
    int length(){return -1;}
};


class Solution {

private:
    int n;

public:
    int findInMountainArray(int target, MountainArray &mountainArr) {

        n = mountainArr.length();

        // find peak
        int peak = find_peak(mountainArr);

        // binary search
        int res = binary_search(mountainArr, 0, peak, target, true);
        return res == -1 ? binary_search(mountainArr, peak, n - 1, target, false) : res;
    }

private:
    int find_peak(MountainArray &mountainArr){

        int l = 0, r = n - 1;
        while(l < r){
            int mid = (l + r) / 2;
            if(mountainArr.get(mid) < mountainArr.get(mid + 1))
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }

    int binary_search(MountainArray &mountainArr, int l, int r, int target, bool is_inc){

        while(l <= r){
            int mid = (l + r) / 2;
            int e = mountainArr.get(mid);
            if(e == target) return mid;

            if(is_inc){
                if(e < target) l = mid + 1;
                else r = mid - 1;
            }
            else{
                if(e < target) r = mid - 1;
                else l = mid + 1;
            }
        }
        return -1;
    }
};


int main() {

    return 0;
}