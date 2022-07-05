#include <iostream>
#include <vector>

int answer = 0;
bool* visited;
std::vector<std::vector<int>> my_vector;

void DFS(int computer_index)
{
	if (visited[computer_index]) // visited: true
	{
		--answer;
		return;
	}

	visited[computer_index] = true; // visited: false

	std::vector<int>::iterator it = my_vector[computer_index].begin();
	for (it; it != my_vector[computer_index].end(); ++it)
	{
		DFS(*it);
		++answer;
	}
}

void bool_initial(int arr_size)
{
	for (int i = 0; i < arr_size; i++)
		visited[i] = false;
}

int main()
{
	int computers, pairs;
	std::cin >> computers;
	std::cin >> pairs;

	my_vector.resize(computers);

	int i = 0;
	int a, b; // one pair
	while (i != pairs)
	{
		std::cin >> a >> b;
		my_vector[a - 1].push_back(b - 1);
		my_vector[b - 1].push_back(a - 1);
		i++;
	}

	visited = new bool[computers + 1];
	bool_initial(computers + 1); // initilizes all values of 'visited' as false


	DFS(0); // cause we starts search from No.1 computer (=index 0)
	std::cout << answer << std::endl;
	delete[] visited;
	return 0;
}