/// Source : https://leetcode.com/problems/find-in-mountain-array/
/// Author : liuyubobobo
/// Time   : 2019-06-22

#include <iostream>

using namespace std;


/// Binary Search
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
        return findInMountainArray(target, mountainArr, 0, n - 1);
    }

private:
    int findInMountainArray(int target, MountainArray &mountainArr, int l, int r){

        if(l > r) return -1;

        int mid = (l + r) / 2;
        int e = mountainArr.get(mid);

        bool isInc = isIncrease(mountainArr, mid, e);

        if(e == target){
            if(isInc) return mid;
            else{
                int res = findInMountainArray(target, mountainArr, l, mid - 1);
                return res == -1 ? mid : res;
            }
        }
        else if(e < target){
            if(isInc) return findInMountainArray(target, mountainArr, mid + 1, r);
            else return findInMountainArray(target, mountainArr, l, mid - 1);
        }
        else{ // e > target
            int res = findInMountainArray(target, mountainArr, l, mid - 1);
            return res == -1 ? findInMountainArray(target, mountainArr, mid + 1, r) : res;
        }

        return -1;
    }

    bool isIncrease(MountainArray &mountainArr, int index, int e){

        if(index == 0) return true;

        int e2 = mountainArr.get(index - 1);
        return e2 < e;
    }
};


int main() {

    return 0;
}