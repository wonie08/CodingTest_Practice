#include <iostream>
#include <vector>
#include <cmath> // pow

/*
* DFS/BFS - Ÿ�� �ѹ�
* https://programmers.co.kr/learn/courses/30/lessons/43165
*/


// acc: �����Ͽ� ���� ��
void DFS(int k, int acc, int* tree, std::vector<int>& numbers, int count, int nodeMax)
{
	if (k >= nodeMax)
		return;
	else if (k == 1) // main���� ù ȣ��ÿ��� ����
		tree[k] = acc; // tree[1] = 0;
	else
		tree[k] = tree[k / 2] + acc; // tree[k/2]�� �θ���

	if (count < (int)numbers.size() - 1)
	{
		++count; // -1 �� 0
		acc = numbers[count]; // acc = numbers[0] = 1
	}
	else
		return;

	DFS(2 * k, -acc, tree, numbers, count, nodeMax); // ���� (-1 ����)
	DFS(2 * k + 1, +acc, tree, numbers, count, nodeMax); // ������ (+1 ����)
}


int solution(std::vector<int> numbers, int target) {
    int answer = 0;

	int level = numbers.size();
	//int nodes = pow(2, level + 1) - 1; // ��ȭ����Ʈ���� ��� ��� ������ 2^(Ʈ������+1) - 1
	int nodes = pow(2, level + 1); // ���ǻ� index=1���� �����ϱ� ������ +1

	// �����Ҵ�
	int* arr = new int[nodes];

	// �ʱ�ȭ
	for (int i = 0; i < nodes; i++) // 2^(5-1) = 2^4 =16
		arr[i] = 0;
	
	// DFS
	DFS(1, 0, arr, numbers, -1, nodes);

	/*
	// Ȯ�ο� ���
	std::cout << arr[1];
	for (int i = 2; i < nodes; i++)
	{
		// �ٹٲ� (2�� ���������� �Ǻ�)
		if ((i & (i - 1)) == 0)
			std::cout << std::endl;

		std::cout << arr[i] << "  "; // �� ������ 0�� null
	}
	std::cout << std::endl << std::endl;
	*/

	// Ʈ���� ������ ������ �ִ� ����� ������ 2^level
	int start = nodes - (int)pow(2, level);
	for (int i = start; i < nodes; i++)
	{
		if (arr[i] == target)
			answer++;
	}

	// �����Ҵ� ����
	delete[] arr;

    return answer;
}

int main()
{
	//std::vector<int> numbers = { 1, 1, 1, 1, 1 };
	std::vector<int> numbers = { 5, 1, 13 };
	int target = -19;

	std::cout << "ANSWER : " << solution(numbers, target) << std::endl;
	return 0;
}