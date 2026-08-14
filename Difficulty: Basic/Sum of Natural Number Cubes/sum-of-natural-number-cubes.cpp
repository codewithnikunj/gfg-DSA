class Solution {
  public:
    int sumOfSeries(int n) {
        if (n == 0) {
            return 0;
        }

        return n * n * n + sumOfSeries(n - 1);// code here
        sumOfSeries(n-1);
        cout<<n*n*n;
    }
};