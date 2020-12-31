/// Source : https://leetcode.com/problems/online-election/description/
/// Author : liuyubobobo
/// Time   : 2018-09-22

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cassert>

using namespace std;


/// Using Priority Queue to precalculate the winner in every time
/// Using Binary Search to query
///
/// Time Complexity: init: O(nlogn)
///                  query: O(logn)
class TopVotedCandidate {

private:
    vector<pair<int, int>> winner;

public:
    TopVotedCandidate(vector<int> persons, vector<int> times) {

        priority_queue<pair<pair<int, int>, int>> pq; // (votes, time), id
        vector<int> nearest(persons.size() + 1, 0);
        vector<int> votes(persons.size(), 0);

        winner.clear();
        for(int i = 0; i < times.size(); i ++){
            nearest[persons[i]] = times[i];
            votes[persons[i]] ++;
            pq.push(make_pair(make_pair(votes[persons[i]], times[i]), persons[i]));
            while(true){
                int vote = pq.top().first.first;
                int time = pq.top().first.second;
                int person = pq.top().second;

                if(nearest[person] == time){
                    winner.push_back(make_pair(times[i], person));
                    break;
                }
                else
                    pq.pop();
            }
        }
    }

    int q(int t) {

        vector<pair<int, int>>::iterator iter =
                lower_bound(winner.begin(), winner.end(), make_pair(t, -1));
        if(iter->first != t){
            assert(iter != winner.begin());
            iter --;
        }
        return iter->second;
    }
};


int main() {

    vector<int> persons1 = {0,1,1,0,0,1,0};
    vector<int> times1 = {0,5,10,15,20,25,30};
    TopVotedCandidate topVotedCandidate1(persons1, times1);

    cout << topVotedCandidate1.q(3) << endl;
    // 0


    vector<int> persons2 = {0,0,0,0,1};
    vector<int> times2 = {0,6,39,52,75};
    TopVotedCandidate topVotedCandidate2(persons2, times2);

    cout << topVotedCandidate2.q(99) << endl;
    // 0

    return 0;
}