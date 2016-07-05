#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <string.h>
#include <map>
#include <vector>

#define INF 1<<29
using namespace std;

int main() {
	int T, Q, E, Index = 1, c;
	string a, b;
	cin >> T;
	while (T--) {
		Index = 1;
		cin >> E >> Q;
		map<string, int> m;
		string reverseMap[2 * E + 2];
		bool graph[2 * E + 2][2 * E + 2]; // where 2*E is the maximum no of Nodes that can be

		for (int i = 0; i < 2 * E; i++)
			memset(graph[i], 0, sizeof graph[i]);
		while (E--) {
			cin >> a >> b;
			if (!m[a]) {m[a] = Index;	reverseMap[Index++] = a;}
			if (!m[b]) {m[b] = Index;	reverseMap[Index++] = b;}
			graph[m[a]][m[b]] = graph[m[b]][m[a]] = true;
		}
		while (Q--) {
			cin >> a >> b;

			int parent[Index + 1];	memset(parent, 0, sizeof parent);
			queue<int> que;	que.push(m[a]);
			parent[m[a]] = -1;
			bool found = false;

			while (!que.empty()) {

				int u = que.front();
				que.pop();
				for (int v = 1; v < Index; v++)
					if (graph[u][v] && parent[v]==0) {
						parent[v] = u;
						que.push(v);
					}
			}
			vector<string> ans;
			for (c = m[b], ans.push_back(reverseMap[c]); c != m[a]; c= parent[c])
				ans.push_back(reverseMap[parent[c]]);
			reverse(ans.begin(), ans.end());

			for (int i = 0; i < ans.size(); i++)
				cout << ans[i].c_str()[0];
			cout << endl;
		}
		if (T)cout<<endl;
	}
	return 0;
}

