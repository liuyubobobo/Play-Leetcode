#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    double getAdmissionLine(int k, vector<double>& scores) {

        sort(scores.begin(), scores.end(), greater<double>());
        return scores[k - 1];
    }
};

int main() {

    vector<double> scores1 = {150,300,400,500,600,700,550,450,450,500,555.5};
    cout << Solution().getAdmissionLine(5, scores1) << endl;
    // 500

    vector<double> scores2 = {723,699,510,488.5};
    cout << Solution().getAdmissionLine(4, scores2) << endl;
    // 488.5
    return 0;
}
