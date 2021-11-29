#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s, t, u;
    while (cin >> s >> t >> u) {
        int n = s.size();
        int m = t.size();
        // dp[i][j] serà true si podem formar les i + j primeres lletres de u
        // intercalant les i primeres de s i les j primeres de t
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= m; ++j) {
                if (i > 0 and dp[i - 1][j] and s[i - 1] == u[i + j - 1])
                    dp[i][j] = true;
                if (j > 0 and dp[i][j - 1] and t[j - 1] == u[i + j - 1])
                    dp[i][j] = true;
            }
        
        // Si dp[n][m] és true, podem intercalar s i t per obtenir u
        cout << (dp[n][m] ? "yes" : "no") << endl;
    }
}