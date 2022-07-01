/// Source : https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs-ii/
/// Author : liuyubobobo
/// Time   : 2022-06-30

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Binary Search
/// Time Complexity: O(nlogn + nlog(max_jobs))
/// Space Complexity: O(1)
class Solution {
public:
    int minimumTime(vector<int>& jobs, vector<int>& workers) {

        sort(jobs.begin(), jobs.end());
        sort(workers.begin(), workers.end());

        int l = 1, r = 1e5;
        while(l < r){
            int mid = (l + r) / 2;
            if(ok(jobs, workers, mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }

private:
    bool ok(const vector<int>& jobs, const vector<int>& workers, int d){

        for(int i = 0; i < workers.size(); i ++)
            if(1ll * workers[i] * d < 1ll * jobs[i]) return false;
        return true;
    }
};


int main() {

    vector<int> jobs1 = {5, 2, 4}, workers1 = {1, 7, 5};
    cout << Solution().minimumTime(jobs1, workers1) << '\n';
    // 2

    return 0;
}
