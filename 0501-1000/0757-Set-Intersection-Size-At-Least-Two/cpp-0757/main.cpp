#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;


class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& interval1, const vector<int>& interval2){

            if(interval1[1] != interval2[1]) return interval1[1] < interval2[1];
            return interval1[0] >= interval2[0];
        });

        int res = 2, largest1 = intervals[0][1], largest2 = intervals[0][1] - 1;
        for(int i = 1; i < intervals.size(); i ++){
            int a = intervals[i][0], b = intervals[i][1];
            if(a <= largest2 && largest1 <= b){
                continue;
            }
            else if(largest1 >= a){
                res ++;
                largest2 = largest1;
                largest1 = b;
            }
            else{
                res += 2;
                largest1 = b;
                largest2 = b - 1;
            }
        }
        return res;
    }
};


int main() {

    vector<vector<int>> intervals1 = {{1,3},{1,4},{2,5},{3,5}};
    cout << Solution().intersectionSizeTwo(intervals1) << '\n';
    // 3

    return 0;
}
