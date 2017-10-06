#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include "Solution1.h"
#include "Solution2.h"

using namespace std;

int main() {

    int N = 2000;

    srand(time(NULL));
    vector<int> vec1;
    for(int i = 0 ; i < N ; i ++){
        int randNumber = rand() % N;
        if(randNumber % 2)
            vec1.push_back(randNumber);
        else
            vec1.push_back(-randNumber);
    }

    vector<int> vec2(vec1.begin(), vec1.end());

    int target = rand() % N;
    time_t startTime, endTime;

    startTime = clock();
    Solution1().fourSum(vec1, target);
    endTime = clock();
    cout << "Solution 1 time: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;

    startTime = clock();
    Solution2().fourSum(vec2, target);
    endTime = clock();
    cout << "Solution 2 time: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;

    return 0;
}