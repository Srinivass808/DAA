#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of matrices: ";
    cin >> n;

    int p[n + 1];

    cout << "Enter the dimensions of matrices:" << endl;
    cout << "For example, for matrices 10x20, 20x30, 30x40 enter: 10 20 30 40" << endl;

    for (int i = 0; i <= n; i++)
    {
        cin >> p[i];
    }

    int dp[n + 1][n + 1];

    // Cost of multiplying one matrix is 0
    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = 0;
    }

    // length is the number of matrices in the chain
    for (int length = 2; length <= n; length++)
    {
        for (int i = 1; i <= n - length + 1; i++)
        {
            int j = i + length - 1;

            dp[i][j] = 999999999;

            for (int k = i; k < j; k++)
            {
                int cost = dp[i][k] + dp[k + 1][j]
                         + p[i - 1] * p[k] * p[j];

                if (cost < dp[i][j])
                {
                    dp[i][j] = cost;
                }
            }
        }
    }

    cout << "\nMinimum number of multiplications = ";
    cout << dp[1][n] << endl;

    return 0;
}
