#include<bits/stdc++.h>
using namespace std;

// _______________________ Recurcive _______________________

int mcmRecur(vector<int> &chain, int start, int end) {

	if (start == end)
		return 0;

	int min = INT_MAX;
	for (int i = start; i < end; i++) {
		int count = mcmRecur(chain, start, i)
		            + mcmRecur(chain, i + 1, end)
		            + chain[start - 1] * chain[i] * chain[end];
		min = std::min(min, count);
	}
	return min;
}
// _________________________________________________________

// _______________________ DP _______________________

int mcmTabuler(vector<int> &chain) {
	int n = chain.size();
	int dp[n][n];

	for (int i = 1; i < n; i++) {
		dp[i][i] = 0;
	}

	for (int L = 2; L < n; L++) {
		for (int start = 1; start < n - L + 1; start++) {

			int end = start + L - 1;
			dp[start][end] = INT_MAX;

			for (int k = start; k < end; k++)
			{
				int q = dp[start][k] + dp[k + 1][end]
				        + chain[start - 1] * chain[k] * chain[end];
				if (q < dp[start][end])
					dp[start][end] = q;
			}
		}
	}

	return dp[1][n - 1];
}
// __________________________________________________

int main() {

	int n;
	cin >> n;
	vector<int> chain(n + 1);
	for (int &dim : chain)
		cin >> dim;

	cout << "Matrix Chain Multiplication Operations (Recurcive): " << mcmRecur(chain, 1, n) << endl;

	cout << "Matrix Chain Multiplication Operations (DP): " << mcmTabuler(chain) << endl;
}