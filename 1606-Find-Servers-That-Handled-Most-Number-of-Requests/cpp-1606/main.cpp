/// Source : https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/
/// Author : liuyubobobo
/// Time   : 2020-10-15

#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;


/// Priority Queue + TreeMap
/// Time Complexity: O(nlogk)
/// Space Complexity: O(k)
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // (idletime, id)
        set<int> available;
        vector<int> f(k, 0);

        for(int i = 0; i < min(k, (int)arrival.size()); i ++) {
            pq.push({arrival[i] + load[i], i});
            f[i] ++;
        }

        for(int i = k; i < arrival.size(); i ++){

            while(!pq.empty() && pq.top().first <= arrival[i]){
                available.insert(pq.top().second);
                pq.pop();
            }

            set<int>::iterator iter = available.lower_bound(i % k);
            if(iter == available.end()){
                iter = available.lower_bound(0);
            }

            if(iter != available.end()){
                int index = *iter;
                available.erase(index);
                pq.push({arrival[i] + load[i], index});
                f[index] ++;
            }
        }

        vector<int> res;
        int maxf = 0;
        for(int i = 0; i < k; i ++)
            if(f[i] > maxf) res = {i}, maxf = f[i];
            else if(f[i] == maxf) res.push_back(i);
        return res;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << " "; cout << endl;
}

int main() {

    vector<int> arr1 = {1, 2, 3, 4, 5}, load1 = {5, 2, 3, 3, 3};
    print_vec(Solution().busiestServers(3, arr1, load1));
    // 1

    vector<int> arr2 = {1, 2, 3, 4}, load2 = {1, 2, 1, 2};
    print_vec(Solution().busiestServers(3, arr2, load2));
    // 0

    vector<int> arr3 = {1, 2, 3}, load3 = {10, 12, 11};
    print_vec(Solution().busiestServers(3, arr3, load3));
    // 0 1 2

    vector<int> arr4 = {1, 2, 3, 4, 8, 9, 10}, load4 = {5, 2, 10, 3, 1, 2, 2};
    print_vec(Solution().busiestServers(3, arr4, load4));
    // 1

    vector<int> arr5 = {1}, load5 = {1};
    print_vec(Solution().busiestServers(1, arr5, load5));
    // 0

    vector<int> arr6 = {1}, load6 = {1000000000};
    print_vec(Solution().busiestServers(3, arr6, load6));
    // 0

    return 0;
}
