/// Source : https://leetcode.com/problems/online-election/description/
/// Author : liuyubobobo
/// Time   : 2018-09-22

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>


using namespace std;


/// Using 2D vectors votes
/// Votes[i][j] is the jth vote make some person's vote count == i
/// Then use Binary Search twice to query
/// The performance is not the best for the problem
/// But I think the idea is good to think about
///
/// Time Complexity: init: O(n)
///                  query: O(2logn)
class TopVotedCandidate {

private:
    vector<vector<pair<int, int>>> votes; // time, person

public:
    TopVotedCandidate(vector<int> persons, vector<int> times) {

        unordered_map<int, int> cnt; // person -> votes
        votes.clear();
        votes.push_back(vector<pair<int, int>>());
        for(int i = 0; i < persons.size(); i ++){
            cnt[persons[i]] ++;
            if(votes.size() <= cnt[persons[i]]) {
                assert(votes.size() == cnt[persons[i]]);
                votes.push_back(vector<pair<int, int>>());
            }
            assert(cnt[persons[i]] < votes.size());
            votes[cnt[persons[i]]].push_back(make_pair(times[i], persons[i]));
        }
    }

    int q(int t) {

        int l = 0, r = votes.size() - 1;
        while(l < r){

            int mid = (l + r + 1) / 2;
            assert(votes[mid].size() > 0);
            if(votes[mid][0].first > t)
                r = mid - 1;
            else // votes[mid][0].first <= t
                l = mid;
        }

        vector<pair<int, int>>:: iterator iter =
                lower_bound(votes[l].begin(), votes[l].end(), make_pair(t, -1));
        if(iter->first != t)
            iter --;
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