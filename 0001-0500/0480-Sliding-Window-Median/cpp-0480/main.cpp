/// Source : https://leetcode.com/problems/sliding-window-median/
/// Author : liuyubobobo
/// Time   : 2019-09-23

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// One TreeSet
/// Time Complexity: O(nlogk)
/// Space Complexity: O(k)
class Solution {

private:
    map<int, int> tree;
    int count = 0;

    int index = -1;
    map<int, int>::iterator iter;

public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {

        vector<double> res;
        for(int i = 0; i < k; i ++)
            add(nums[i]);

        res.push_back(get_median());
//        cout << get_median() << endl;
        for(int i = k; i < nums.size(); i ++){
            add(nums[i]);
            remove(nums[i - k]);
            res.push_back(get_median());
//            cout << get_median() << endl;
        }
        return res;
    }

private:
    void add(int num){

        if(!count){
            tree[num] ++;
            index = 0;
            iter = tree.begin();
            count ++;
            return;
        }

        tree[num] ++;
        if(count % 2){ // odd
            if(num < iter->first){
                if(index) index --;
                else iter --, index = iter->second - 1;
            }
        }
        else{ // even
            if(num >= iter->first){
                if(index + 1 < iter->second) index ++;
                else iter ++, index = 0;
            }
        }
        count ++;
    }

    void remove(int num){

        if(count % 2){ // odd
            if(num >= iter->first){
                if(index) index --;
                else iter--, index = iter->second - 1;
            }
        }
        else{ // even
            if(num < iter->first){
                if(index + 1 < iter->second) index ++;
                else iter ++, index = 0;
            }
            else if(num == iter->first && index + 1 == iter->second)
                iter ++, index = 0;
        }

        tree[num] --;
        count --;
        if(tree[num] == 0) tree.erase(num);
    }

    double get_median(){
        if(count % 2) return iter->first;
        if(index + 1 < iter->second) return iter->first;

        map<int, int>::iterator iter2 = iter;
        iter2 ++;
        return ((double)iter->first + (double)iter2->first) / 2;
    }
};


void print_vec(const vector<double>& vec){
    for(double e: vec) cout << e << " "; cout << endl;
}

int main() {

    vector<int> nums1 = {1, 3, -1, -3, 5, 3, 6, 7};
    print_vec(Solution().medianSlidingWindow(nums1, 3));
    // 1 -1 -1 3 5 6

    vector<int> nums2 = {1, 2, 3, 4, 2, 3, 1, 4, 2};
    print_vec(Solution().medianSlidingWindow(nums2, 3));
    // 2 3 3 3 2 3 2

    return 0;
}