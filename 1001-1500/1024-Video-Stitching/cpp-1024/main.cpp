/// Source : https://leetcode.com/problems/video-stitching/
/// Author : liuyubobobo
/// Time   : 2019-04-06

#include <iostream>
#include <vector>

using namespace std;


/// Sorting and Greedy
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {

        if(T == 0) return 0;

        sort(clips.begin(), clips.end(),[](const vector<int>& a, const vector<int>& b){
           if(a[0] != b[0]) return a[0] < b[0];
           return a[1] > b[1];
        });

        if(clips[0][0]) return -1;

        int res = 1, end = clips[0][1], tmax = end;
        if(end >= T) return 1;

        for(int i = 1; i < clips.size(); i ++)
            if(clips[i][0] <= end) tmax = max(tmax, clips[i][1]);
            else{
                res ++;
                end = tmax;
                if(end >= T) return res;
                if(clips[i][0] > end) return -1;
            }

        if(tmax >= T) return res + 1;
        return -1;
    }
};


int main() {

    vector<vector<int>> clips1 = {{0,2},{4,6},{8,10},{1,9},{1,5},{5,9}};
    cout << Solution().videoStitching(clips1, 10) << endl;
    // 3

    return 0;
}