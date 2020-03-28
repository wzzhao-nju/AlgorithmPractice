#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool nextPermutation(string &str) {
	int len = str.length();
	for (int i = len - 1; i > 0; i--) {
		if (str[i] > str[i - 1]) {
			char temp = str[i - 1];
			int j = len - 1;
			for (; j >= i; j--)
				if (str[j] > temp)
					break;
			swap(str[i - 1], str[j]);
			int s = i, e = len - 1;
			while (s < e)
				swap(str[s++], str[e--]);
			return true;
		}
	}
	int start = 0, end = len - 1;
	while (start < end)
		swap(str[start++], str[end--]);
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	int k;
	cin >> k;
	while (k--) {
		string str, next;
		cin >> str;
		sort(str.begin(), str.end());
		next = str;
		cout << str << endl;
		while (nextPermutation(next) == true) {
			if (next != str)
				cout << next << endl;
			str = next;
		}
		cout << endl;
	}
	return 0;
}