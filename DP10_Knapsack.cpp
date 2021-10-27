#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int>&weights, vector<int>&values, int pos, int c, vector<vector<int>>&dp) {
	if (c == 0 || pos >= weights.size())
		return 0;
	if (dp[c][pos] != -1)
		return dp[c][pos];
	if (weights[pos] > c)
		return dp[c][pos] = knapsack(weights, values, pos + 1, c, dp);
	return dp[c][pos] = max(knapsack(weights, values, pos + 1, c - weights[pos], dp) + values[pos], knapsack(weights, values, pos + 1, c, dp));
}

int main() {
	vector<int> weights, values;
	int n, c;
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		int w;
		cin >> w;
		weights.push_back(w);
	}
	for (int i = 0; i < n; i++) {
		int v;
		cin >> v;
		values.push_back(v);
	}
	vector<vector<int>> dp(c + 1, vector<int>(weights.size(), -1));
	cout << knapsack(weights, values, 0, c, dp);
	return 0;
}