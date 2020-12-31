/// Source : https://leetcode.com/problems/interval-list-intersections/
/// Author : liuyubobobo
/// Time   : 2019-02-04

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(m + n)
/// Space Complexity: O(1)

/// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {

        vector<Interval> res;

        int i = 0, j = 0;
        while(i < A.size() && j < B.size()){

            int l = max(A[i].start, B[j].start);
            int h = min(A[i].end, B[j].end);
            if(l <= h)
                res.push_back(Interval(l, h));

            if(A[i].end <= B[j].end)
                i ++;
            else
                j ++;
        }
        return res;
    }
};


void print_vec(const vector<Interval>& vec){

    for(const Interval& interval: vec)
        cout << "(" << interval.start << "," << interval.end << ") ";
    cout << endl;
}

int main() {

    vector<Interval> A1 = {Interval(0,2),Interval(5,10),Interval(13,23),Interval(24,25)};
    vector<Interval> B1 = {Interval(1,5),Interval(8,12),Interval(15,24),Interval(25,26)};
    print_vec(Solution().intervalIntersection(A1, B1));
    // [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]

    vector<Interval> A2 = {Interval(5,10)};
    vector<Interval> B2 = {Interval(5,10)};
    print_vec(Solution().intervalIntersection(A2, B2));
    // [[5, 10]]

    vector<Interval> A3 = {Interval(3,5), Interval(9, 20)};
    vector<Interval> B3 = {Interval(4,5), Interval(7, 10), Interval(11, 12), Interval(14, 15), Interval(16, 20)};
    print_vec(Solution().intervalIntersection(A3, B3));
    // [[4,5],[9,10],[11,12],[14,15],[16,20]]

    return 0;
}