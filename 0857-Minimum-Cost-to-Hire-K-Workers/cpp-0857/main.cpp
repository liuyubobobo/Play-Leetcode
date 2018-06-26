/// Source : https://leetcode.com/problems/minimum-cost-to-hire-k-workers/description/
/// Author : liuyubobobo
/// Time   : 2010-06-25

#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;


/// Greedy + Priority Queue
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Worker{

private:
    int q, w;
    double ratio;

public:
    Worker(int q, int w){
        this->q = q;
        this->w = w;
        this->ratio = (double)w / q;
    }

    double getRatio() const{
        return ratio;
    }

    int getQuality() const{
        return q;
    }
};


bool cmpWorkers (const Worker& w1, const Worker& w2){
    return w1.getRatio() < w2.getRatio();
}

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {

        assert(K <= quality.size());

        vector<Worker> workers;
        for(int i = 0 ; i < quality.size() ; i ++)
            workers.push_back(Worker(quality[i], wage[i]));

        sort(workers.begin(), workers.end(), cmpWorkers);

        priority_queue<int> pq;
        int sumq = 0;
        for(int i = 0 ; i < K ; i ++){
            pq.push(workers[i].getQuality());
            sumq += workers[i].getQuality();
        }

        double res = sumq * workers[K-1].getRatio();
        for(int i = K ; i < workers.size() ; i ++){
            int maxq = pq.top();
            pq.pop();
            sumq -= maxq;

            pq.push(workers[i].getQuality());
            sumq += workers[i].getQuality();
            res = min(res, sumq * workers[i].getRatio());
        }

        return res;
    }
};


int main() {

    vector<int> quality1 = {10, 20, 5};
    vector<int> wage1 = {70, 50, 30};
    int K1 = 2;
    cout << Solution().mincostToHireWorkers(quality1, wage1, K1) << endl;
    // 105.00000

    vector<int> quality2 = {3, 1, 10, 10, 1};
    vector<int> wage2 = {4, 8, 2, 2, 7};
    int K2 = 3;
    cout << Solution().mincostToHireWorkers(quality2, wage2, K2) << endl;
    // 30.66667

    return 0;
}