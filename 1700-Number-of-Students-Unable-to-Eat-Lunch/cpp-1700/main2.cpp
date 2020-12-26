/// Source : https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/
/// Author : liuyubobobo
/// Time   : 2020-12-26

#include <iostream>
#include <vector>
#include <deque>

using namespace std;


/// Using Deque and Stack
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {

public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {

        deque<int> q;
        vector<int> cnt(2, 0);
        for(int stu: students){
            q.push_back(stu);
            cnt[stu] ++;
        }
        reverse(sandwiches.begin(), sandwiches.end());

        while(!q.empty()){
            if(q.front() != sandwiches.back()){
                if(cnt[1 - q.front()] == 0)
                    return q.size();
                int a = q.front();
                q.pop_front();
                q.push_back(a);
            }
            else{
                int a = q.front();
                cnt[a] --;
                q.pop_front();
                sandwiches.pop_back();
            }
        }
        return 0;
    }
};


int main() {

    return 0;
}
