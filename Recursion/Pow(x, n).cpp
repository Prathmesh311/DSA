class Solution {
public:
    double findPow(double x, long long n, double &ans) {
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return x;
        }

        ans = findPow(x, n / 2, ans);
        ans = ans * ans;

        return n % 2 == 1 ? x * ans : ans;
    }

    double myPow(double x, int n) {
        double ans = 1.0;

        ans = findPow(x, abs((long long)n), ans);

        if (n < 0) {
            return 1 / ans;
        }

        return ans;
    }
};
