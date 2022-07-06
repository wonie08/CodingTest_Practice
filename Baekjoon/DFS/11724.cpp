// https://www.acmicpc.net/problem/11724

#include <iostream>
#include <vector>

int N, M;  // numbers of node: N,   numbers of edges: M
std::vector<std::vector<int>> graph(1001);
char visited[1001] = { false, };
int answer = 0;

void DFS(int node_num)
{
	if (visited[node_num]) // visited: true
		return;
	else // visited: false
		visited[node_num] = true;

	std::vector<int>::iterator it = graph[node_num].begin();

	for (it; it != graph[node_num].end(); ++it)
		DFS(*it);
}

int main()
{
	// Input
	std::cin >> N >> M;
	graph.resize(N);

	int i = 0;
	int a, b;
	while (i != M) {
		std::cin >> a >> b;

		graph[a - 1].push_back(b - 1);
		graph[b - 1].push_back(a - 1);

		i++;
	}

	for (int k = 0; k < N; k++)
	{
		if (visited[k]) // visited: true
			continue;

		DFS(k); // starts seach from No.1 node (= index 0)
		answer++;
	}
	std::cout << answer;
	return 0;
}