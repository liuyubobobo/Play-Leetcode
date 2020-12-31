/// Source : https://leetcode.com/problems/advantage-shuffle/description/
/// Author : liuyubobobo
/// Time   : 2018-07-14

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;


/// Greedy
/// Using HashMap and Set to store elements in A
///
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {

        unordered_map<int, int> Afreq;
        set<int> Auniq;
        for(int a: A){
            Afreq[a] ++;
            Auniq.insert(a);
        }

        vector<int> res(A.size(), -1);
        for(int i = 0 ; i < B.size() ; i ++){
            set<int>::iterator iter = Auniq.upper_bound(B[i]);
            if(iter != Auniq.end()){
                res[i] = *iter;
                Afreq[*iter] --;
                if(Afreq[*iter] == 0){
                    Afreq.erase(*iter);
                    Auniq.erase(*iter);
                }
            }
        }

        for(int i = 0 ; i < res.size() ; i ++)
            if(res[i] == -1){
                int num = Afreq.begin()->first;
                res[i] = num;
                Afreq[num] --;
                if(Afreq[num] == 0)
                    Afreq.erase(num);
            }

        return res;
    }
};


void print_vec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    vector<int> A1 = {2, 7, 11, 15};
    vector<int> B1 = {1, 10, 4, 11};
    print_vec(Solution().advantageCount(A1, B1));

    vector<int> A2 = {12, 24, 8, 32};
    vector<int> B2 = {13, 25, 32, 11};
    print_vec(Solution().advantageCount(A2, B2));

    return 0;
}