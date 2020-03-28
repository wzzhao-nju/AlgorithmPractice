#include<iostream>
using namespace std;
struct hashNode
{
	int data;
	hashNode *next;
	hashNode() { next = nullptr; }
	hashNode(int x) { data = x; next = nullptr; }
};
class hashList {
private:
	hashNode *head;
public:
	hashList() { head = nullptr; }
	int find(int d) {
		int count = 0;
		for (hashNode *h = head; h!=nullptr; h = h->next)
			if (h->data == d)
				count++;
		return count;
	}
	void insert(int d) {
		hashNode *to_insert = new hashNode(d);
		if (head == nullptr)
			head = to_insert;
		else {
			to_insert->next = head->next;
			head->next = to_insert;
		}
	}
};
int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int *a = new int[n];
	int *b = new int[n];
	int *c = new int[n];
	int *d = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	int p = 99991;
	hashList *hash = new hashList[p];
	int sum = 0, select;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum = a[i] + b[j];
			select = sum % p;
			if (select < 0)
				select += p;
			hash[select].insert(sum);
		}
	}
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum = c[i] + d[j];
			sum = -sum;
			select = sum % p;
			if (select < 0)
				select += p;
			count += hash[select].find(sum);
		}
	}
	cout << count << endl;
	return 0;
}