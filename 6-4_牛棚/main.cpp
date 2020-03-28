#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	int m, s, c;
	cin >> m >> s >> c;
	if (m >= c) {
		cout << c << endl;
		return 0;
	}
	int *cow = new int[c];
	for (int i = 0; i < c; i++)
		cin >> cow[i];
	sort(cow, cow + c);
	int *gap = new int[c - 1];
	for (int i = 0; i < c - 1; i++)
		gap[i] = cow[i + 1] - cow[i] - 1;
	sort(gap, gap + c - 1, cmp);
	int res = cow[c - 1] - cow[0] + 1;
	for (int i = 0; i < m - 1; i++)
		res -= gap[i];
	cout << res << endl;
	return 0;
}