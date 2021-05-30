/// Source : https://leetcode.com/problems/process-tasks-using-servers/
/// Author : liuyubobobo
/// Time   : 2021-05-29

#include <iostream>
#include <queue>

using namespace std;


/// Priority Queue
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        // waiting_servers {weight, index}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> waiting_servers;
        for(int i = 0; i < servers.size(); i ++)
            waiting_servers.push({servers[i], i});

        // busy_servers {end_tine, index}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> busy_servers;
        vector<int> res(tasks.size());
        int curt = 0, i = 0;
        while(i < tasks.size()){

            if(waiting_servers.empty() && busy_servers.top().first > curt)
                curt = busy_servers.top().first;

            while(!busy_servers.empty() && busy_servers.top().first == curt){
                int no = busy_servers.top().second;
                waiting_servers.push({servers[no], no});
                busy_servers.pop();
            }

            while(!waiting_servers.empty() && i < tasks.size() && curt >= i){
//                cout << i << " " << curt << endl;
                res[i] = waiting_servers.top().second;
                int no = waiting_servers.top().second;
                busy_servers.push({curt + tasks[i], no});
                waiting_servers.pop();
                i ++;
            }
            curt ++;
        }
        return res;
    }
};


void print_vector(const vector<int>& v){
    for(int e: v) cout << e << " "; cout << endl;
}

int main() {

    vector<int> servers1 = {3, 3, 2}, task1 = {1, 2, 3, 2, 1, 2};
    print_vector(Solution().assignTasks(servers1, task1));
    // 2 2 0 2 1 2

    vector<int> servers2 = {5,1,4,3,2}, task2 = {2,1,2,4,5,2,1};
    print_vector(Solution().assignTasks(servers2, task2));
    // 1,4,1,4,1,3,2

    vector<int> servers3 = {10,63,95,16,85,57,83,95,6,29,71}, task3 = {70,31,83,15,32,67,98,65,56,48,38,90,5};
    print_vector(Solution().assignTasks(servers3, task3));
    // [8,0,3,9,5,1,10,6,4,2,7,9,0]

    vector<int> servers4 = {338,890,301,532,284,930,426,616,919,267,571,140,716,859,980,469,628,490,195,664,925,652,503,301,917,563,82,947,910,451,366,190,253,516,503,721,889,964,506,914,986,718,520,328,341,765,922,139,911,578,86,435,824,321,942,215,147,985,619,865};
    vector<int> tasks4 = {773,537,46,317,233,34,712,625,336,221,145,227,194,693,981,861,317,308,400,2,391,12,626,265,710,792,620,416,267,611,875,361,494,128,133,157,638,632,2,158,428,284,847,431,94,782,888,44,117,489,222,932,494,948,405,44,185,587,738,164,356,783,276,547,605,609,930,847,39,579,768,59,976,790,612,196,865,149,975,28,653,417,539,131,220,325,252,160,761,226,629,317,185,42,713,142,130,695,944,40,700,122,992,33,30,136,773,124,203,384,910,214,536,767,859,478,96,172,398,146,713,80,235,176,876,983,363,646,166,928,232,699,504,612,918,406,42,931,647,795,139,933,746,51,63,359,303,752,799,836,50,854,161,87,346,507,468,651,32,717,279,139,851,178,934,233,876,797,701,505,878,731,468,884,87,921,782,788,803,994,67,905,309,2,85,200,368,672,995,128,734,157,157,814,327,31,556,394,47,53,755,721,159,843};
    vector<int> res = Solution().assignTasks(servers4, tasks4);
    vector<int> correct = {26,50,47,11,56,31,18,55,32,9,4,2,23,53,43,0,44,30,6,51,29,51,15,17,22,34,38,33,42,3,25,10,49,51,7,58,16,21,19,31,19,12,41,35,45,52,13,59,47,36,1,28,48,39,24,8,46,20,5,54,27,37,14,57,40,59,8,45,4,51,47,7,58,4,31,23,54,7,9,56,2,46,56,1,17,42,11,30,12,44,14,32,7,10,23,1,29,27,6,10,33,24,19,10,35,30,35,10,17,49,50,36,29,1,48,44,7,11,24,57,42,30,10,55,3,20,38,15,7,46,32,21,40,16,59,30,53,17,18,22,51,11,53,36,57,26,5,36,56,55,31,34,57,7,52,37,31,10,0,51,41,2,32,25,0,7,49,47,13,14,24,57,28,4,45,43,39,38,8,2,44,45,29,25,25,12,54,5,44,30,27,23,26,7,33,58,41,25,52,40,58,9,52,40};
    for(int i = 0; i < res.size(); i ++)
        if(res[i] != correct[i]){cout << i << endl;}
    return 0;
}
