#include<bits/stdc++.h>
using namespace std;

// _______________________ Recurcive _______________________

int ccRecur(vector<int> &coins, int c_pos, int target) {

	if (target == 0)
		return 1;
	if (target < 0)
		return 0;
	if (c_pos <= 0 && target > 0)
		return 0;

	return ccRecur(coins, c_pos, target - coins[c_pos - 1]) + ccRecur(coins, c_pos - 1, target);
}
// _________________________________________________________

// _______________________ Bottom-Up DP _______________________

int ccDP(vector<int> &coins, int target) {

	int c_size = coins.size();
	int dp[target + 1][c_size];

	for (int i = 0; i < c_size; i++)
		dp[0][i] = 1;

	for (int i = 1; i <= target; i++) {
		for (int j = 0; j < c_size; j++) {
			int x = (i - coins[j] >= 0) ? dp[i - coins[j]][j] : 0;
			int y = (j > 0) ? dp[i][j - 1] : 0;
			dp[i][j] = x + y;
		}
	}

	return dp[target][c_size - 1];
}
// ____________________________________________________________

// _______________________ DP Optimized _______________________

int ccOptimized(vector<int> &coins, int target) {

	int c_size = coins.size();
	int dp[target + 1];

	memset(dp, 0, sizeof(dp));
	dp[0] = 1;

	for (int i = 0; i < c_size; i++) {
		for (int j = coins[i]; j <= target; j++) {
			dp[j] += dp[j - coins[i]];
		}
	}

	return dp[target];
}
// ____________________________________________________________

int main() {

	int c, n;
	cin >> c >> n;
	vector<int> coins(c);
	for (int &coin : coins)
		cin >> coin;

	cout << "Coin Change Possibilities (Recurcive): " << ccRecur(coins, c, n) << endl;

	cout << "Coin Change Possibilities (DP): " << ccDP(coins, n) << endl;

	cout << "Coin Change Possibilities (DP Optimized): " << ccOptimized(coins, n) << endl;
}