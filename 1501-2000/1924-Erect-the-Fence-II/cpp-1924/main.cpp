/// Source : https://leetcode.com/problems/erect-the-fence-ii/
/// Author : liuyubobobo
/// Time   : 2021-07-11

#include <iostream>
#include <vector>

using namespace std;


/// Welzl’s Algorithm
/// See here for detail: https://www.geeksforgeeks.org/minimum-enclosing-circle-set-2-welzls-algorithm/
/// Time Complexity: O(n)
/// Space Complexity: O(n)

// T 选择 long double 或者 double
template<typename T>
class LinearSystem{

private:
    const T eps = 1e-9;
    int R, C;
    vector<vector<T>> A, original;

public:
    LinearSystem(vector<vector<T>>& matrix, T eps): A(matrix), original(matrix), eps(eps){

        R = matrix.size();
        assert(R);

        C = matrix[0].size();
        assert(C == R + 1);
    }

    vector<T> solve(){

        T k;
        for(int r = 0; r < R; r ++){

            int max_index = r;
            T maxv = abs(A[r][r]);
            for(int i = r + 1; i < R; i ++)
                if(abs(A[i][r]) > maxv)
                    max_index = i, maxv = abs(A[i][r]);

            if(max_index != r) swap(A[r], A[max_index]);

            k = A[r][r];
            if(abs(k) < eps){
                for(const vector<T>& v: original){
                    for(T e: v) cout << e << ' '; cout << '\n';
                }
                return {};
            }

            if(abs(k - 1) > eps)
                for(int j = r; j < C; j ++)
                    A[r][j] /= k;

            for(int i = r + 1; i < R; i ++){
                k = A[i][r];
                if(abs(k) > eps)
                    for(int j = r; j < C; j ++)
                        A[i][j] -= k * A[r][j];
            }
        }

        for(int j = R - 1; j >= 1; j --){
            for(int i = j - 1; i >= 0; i --){
                k = A[i][j];
                A[i][j] = 0;
                A[i][C - 1] -= k * A[j][C - 1];
            }
        }

        vector<T> res(R);
        for(int i = 0; i < R; i ++) res[i] = A[i].back();
        // assert(validate(res));
        return res;
    }

private:
    bool validate(const vector<T>& res){

        for(int i = 0; i < R; i ++){
            T y = 0.0;
            for(int j = 0; j < C - 1; j ++) y += res[j] * original[i][j];
            if(abs(y - original[i].back()) > eps) return false;
        }
        return true;
    }
};

// T 选择 long double 或者 double
template<typename T>
class Welzls{

private:
    const T eps;

public:
    Welzls(T eps) : eps(eps){}

    vector<T> solve(vector<vector<T>>& points){

        assert(points.size() > 0);
        assert(points[0].size() == 2);

        srand(time(nullptr));

        vector<vector<T>> supports;
        return solve(points, points.size(), supports);
    };

private:
    vector<T> solve(vector<vector<T>>& points, int n, vector<vector<T>> supports){

        assert(supports.size() <= 3);
        if(supports.size() == 3){
            return get_circle(supports[0][0], supports[0][1],
                              supports[1][0], supports[1][1],
                              supports[2][0], supports[2][1]);
        }

        if(n == 0){
            if(supports.size() == 2)
                return get_circle(supports[0][0], supports[0][1],
                                  supports[1][0], supports[1][1]);
            else if(supports.size() == 1)
                return {supports[0][0], supports[0][1], 0.0};

            assert(supports.size() == 0);
            return {0.0, 0.0, 0.0};
        }

        int index = rand() % n;
        swap(points[index], points[n - 1]);

        vector<T> circle = solve(points, n - 1, supports);
        if(in_circle(circle, points[n - 1]))
            return circle;

        supports.push_back(points[n - 1]);
        return solve(points, n - 1, supports);
    }

    // 给定三个点，求圆
    // x0 = ret[0], y0 = ret[1], r = ret[2];
    vector<T> get_circle(T x1, T y1, T x2, T y2, T x3, T y3){

        // 尝试是否可以用两点构成圆？
        vector<T> circle = get_circle(x1, y1, x2, y2);
        if(in_circle(circle, {x3, y3})) return circle;

        circle = get_circle(x1, y1, x3, y3);
        if(in_circle(circle, {x2, y2})) return circle;

        circle = get_circle(x2, y2, x3, y3);
        if(in_circle(circle, {x1, y1})) return circle;

        // 用三个不同点构成圆
        vector<vector<T>> A = {
                {x1, y1, 1.0, - x1 * x1 - y1 * y1},
                {x2, y2, 1.0, - x2 * x2 - y2 * y2},
                {x3, y3, 1.0, - x3 * x3 - y3 * y3}
        };

        LinearSystem<T> ls(A, eps);
        vector<T> res = ls.solve();
        assert(!res.empty());
        circle = {- res[0] / 2.0, - res[1] / 2.0, sqrt((res[0] * res[0] + res[1] * res[1] - 4.0 * res[2])) / 2.0};

        // assert(on_circle(circle, {x1, y1}) && on_circle(circle, {x2, y2}) && on_circle(circle, {x3, y3}));
        return circle;
    }

    // 给定两个不同的点，求圆
    // x0 = ret[0], y0 = ret[1], r = ret[2];
    vector<T> get_circle(T x1, T y1, T x2, T y2){
        return {(x1 + x2) / 2.0, (y1 + y2) / 2.0, dis(x1, y1, x2, y2) / 2.0};
    }

    // 计算 (x1, y1) 和 (x2, y2) 的距离
    T dis(T x1, T y1, T x2, T y2){
        return sqrt(dis_square(x1, y1, x2, y2));
    }

    // 计算 (x1, y1) 和 (x2, y2) 的距离的平方
    T dis_square(T x1, T y1, T x2, T y2){
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    }

    // 判断 p 是否在 circle 中
    // x0 = circle[0], y0 = circle[1], r = circle[2];
    bool in_circle(const vector<T>& circle, const vector<T>& p){
        return dis_square(circle[0], circle[1], p[0], p[1]) <= circle[2] * circle[2] + eps;
    }

    // 判断 p 是否在 circle 上
    // x0 = circle[0], y0 = circle[1], r = circle[2];
    bool on_circle(const vector<T>& circle, const vector<T>& p){
        return abs(dis_square(circle[0], circle[1], p[0], p[1]) - circle[2] * circle[2]) <= eps;
    }
};


class Solution {
public:
    vector<double> outerTrees(vector<vector<int>>& trees) {

        int n = trees.size();
        vector<vector<double>> points(n, vector<double>(2));
        for(int i = 0; i < n; i ++)
            points[i][0] = trees[i][0], points[i][1] = trees[i][1];

        return Welzls<double>(1e-7).solve(points);
    }
};


void print_vec(const vector<double>& v){
    for(double e: v) cout << e << ' '; cout << endl;
}

int main() {

    vector<vector<int>> trees1 = {
            {1, 1}, {2, 2}, {2, 0}, {2, 4}, {3, 3}, {4, 2}
    };
    print_vec(Solution().outerTrees(trees1));
    // 2 2 2

    vector<vector<int>> trees2 = {
            {55, 7},{36, 30},{1, 64},{83, 97},{8, 90},{16, 7},
            {18, 23},{98, 77},{57, 33},{98, 54},{73, 7}
    };
    print_vec(Solution().outerTrees(trees2));
    // 49.36388,52.10134,56.10061

    return 0;
}
