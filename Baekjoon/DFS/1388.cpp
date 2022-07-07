// https://www.acmicpc.net/problem/1388
#include <iostream>

int N, M; // height, width
char str[51][51];
int answer;

void cal()
{
	// I've solved this problem by just 'for loop', not by 'DFS algorithm'
	int i = 0;
	int j = 0;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			// Vertical line
			if (i == N)
				continue;
			else if (str[i][j] == '|' && str[i + 1][j] == '|')
				answer--;

			// Horizontal line
			if (j == M)
				continue;
			else if (str[i][j] == '-' && str[i][j + 1] == '-')
				answer--;
		}
	}
}

int main()
{
	// INPUT
	std::cin >> N >> M; // height, width
	answer = N * M;

	int i = 0;
	while (N != i)
	{
		for (int j = 0; j < M; j++)
			std::cin >> str[i][j];
		i++;
	}

	cal();
	std::cout << answer;

	return 0;
}