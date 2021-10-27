#include<bits/stdc++.h>
using namespace std;

// nCr = (n-1)C(r) + (n-1)C(r-1)

// _______________________ Recurcive _______________________

int nCkRecur(int n, int k) {
	if (k > n)
		return 0;
	if (k == 0 || k == n)
		return 1;
	return nCkRecur(n - 1, k) + nCkRecur(n - 1, k - 1);
}

// _______________________ Top Down _______________________

int nCkTD(int n, int k, int dp[][200]) {
	if (k > n)
		return 0;
	if (k == 0 || k == n)
		return 1;
	if (dp[n][k] != -1)
		return dp[n][k];

	return dp[n][k] = nCkTD(n - 1, k, dp) + nCkTD(n - 1, k - 1, dp);
}

// _______________________ Bottom Up _______________________

int nCkBU(int n, int k) {

	int dp[n + 1][k + 1];

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= min(i, k); j++) {

			if (j == 0 || j == i)
				dp[i][j] = 1;
			else
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}

	return dp[n][k];

}

// _______________________ Optimized _______________________

int nCkBUOpti(int n, int k) {

	int dp[k + 1];
	memset(dp, 0, sizeof(dp));

	dp[0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = min(i, k); j > 0; j--)
			dp[j] = dp[j] + dp[j - 1];
	}

	return dp[k];
}

int main() {

	int n, k;
	cin >> n >> k;

	cout << "nCk (Recurcive): " << nCkRecur(n, k) << endl;

	int dp[200][200];
	memset(dp, -1, sizeof(dp));
	cout << "nCk (Top Down): " << nCkTD(n, k, dp) << endl;

	cout << "nCk (Bottom Up): " << nCkBU(n, k) << endl;

	cout << "nCk (Optimized): " << nCkBUOpti(n, k) << endl;
}