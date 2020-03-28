#include<iostream>
using namespace std;
const int MAX = 500;
const int inf = 80000;
int graph[MAX][MAX], dis[MAX], res[MAX];
bool vis[MAX];
void dijkstra(int start, int f) {
	for (int i = 1; i < f; i++)
		dis[i] = graph[start][i];
	dis[start] = 0;
	vis[start] = true;
	int i, j, k;
	int min, pos;
	for (i = 0; i < f - 1; i++) {
		min = inf;
		pos = start;
		for (j = 0; j < f; j++) {
			if (vis[j] == false && dis[j] < min) {
				pos = j;
				min = dis[j];
			}
		}
		vis[pos] = true;
		for (k = 0; k < f; k++)
			if (vis[k] == false && graph[pos][k] < inf&&dis[pos] + graph[pos][k] < dis[k])
				dis[k] = dis[pos] + graph[pos][k];
	}
}
int main() {
	int f, p, c, m;
	cin >> f >> p >> c >> m;
	for (int i = 0; i < f; i++)
		for (int j = 0; j < f; j++)
			if (i == j)
				graph[i][j] = 0;
			else
				graph[i][j] = inf;
	//init graph
	for (int i = 0; i < f; i++)
		vis[i] = false;
	//init vis
	for (int i = 0; i < f; i++)
		dis[i] = inf;
	//init dis
	int v1, v2, w;
	for (int i = 0; i < p; i++) {
		cin >> v1 >> v2 >> w;
		if (graph[v1 - 1][v2 - 1] > w) {
			graph[v1 - 1][v2 - 1] = w;
			graph[v2 - 1][v1 - 1] = w;
		}
	}
	dijkstra(0, f);
	int count = 0;
	int cow;
	for (int i = 1; i <= c; i++) {
		cin >> cow;
		if (dis[cow - 1] <= m)
			res[count++] = i;
	}
	cout << count << endl;
	for (int i = 0; i < count; i++)
		cout << res[i] << endl;
	return 0;
}