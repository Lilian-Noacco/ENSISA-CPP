//
// Created by Lilian Noacco on 14/12/2025.
//

#include "../include/Similarity.hpp"
#include <cmath>
#include <algorithm>
#include <limits>

double euclidean_distance(const vector<double> &x, const vector<double> &y)
{
    size_t len = min(x.size(), y.size());
    double sum = 0.0;
    for (size_t i = 0; i < len; ++i)
    {
        double diff = x[i] - y[i];
        sum += diff * diff;
    }
    return sqrt(sum);
}

double dtw_distance(const vector<double> &x, const vector<double> &y)
{
    size_t n = x.size();
    size_t m = y.size();
    if (n == 0 || m == 0) return 0.0;

    vector<vector<double>> dtw(n + 1, vector<double>(m + 1, numeric_limits<double>::infinity()));
    dtw[0][0] = 0.0;

    for (size_t i = 1; i <= n; ++i)
    {
        for (size_t j = 1; j <= m; ++j)
        {
            double cost = (x[i - 1] - y[j - 1]) * (x[i - 1] - y[j - 1]);
            dtw[i][j] = cost + min({dtw[i - 1][j], dtw[i][j - 1], dtw[i - 1][j - 1]});
        }
    }
    return sqrt(dtw[n][m]);
}

double edit_distance_real_sequences(const vector<double> &x, const vector<double> &y)
{
    size_t n = x.size();
    size_t m = y.size();
    double epsilon = 0.5; // Threshold for matching, adjustable

    vector<vector<double>> dp(n + 1, vector<double>(m + 1));

    for (size_t i = 0; i <= n; ++i) dp[i][0] = static_cast<double>(i);
    for (size_t j = 0; j <= m; ++j) dp[0][j] = static_cast<double>(j);

    for (size_t i = 1; i <= n; ++i)
    {
        for (size_t j = 1; j <= m; ++j)
        {
            double cost = (abs(x[i - 1] - y[j - 1]) <= epsilon) ? 0.0 : 1.0;
            dp[i][j] = min({
                dp[i - 1][j - 1] + cost, // substitution
                dp[i - 1][j] + 1.0,      // deletion
                dp[i][j - 1] + 1.0       // insertion
            });
        }
    }
    return dp[n][m];
}