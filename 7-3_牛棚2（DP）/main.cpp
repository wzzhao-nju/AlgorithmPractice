#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int n, t;
	cin >> n >> t;
	int **farm = new int*[n + 1];
	for (int i = 0; i < n + 1; i++)
		farm[i] = new int[n + 1];
	for (int i = 0; i < n + 1; i++)
		for (int j = 0; j < n + 1; j++)
			if (i == 0 || j == 0)
				farm[i][j] = 0;
			else
				farm[i][j] = 1;
	int x, y;
	for (int i = 0; i < t; i++) {
		cin >> x >> y;
		farm[x][y] = 0;
	}
	int res = 0;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (farm[i][j] != 0)
				farm[i][j] = min(farm[i - 1][j], min(farm[i][j - 1], farm[i - 1][j - 1])) + 1;
			res = max(res, farm[i][j]);
		}
	}
	cout << res << endl;
	return 0;
}