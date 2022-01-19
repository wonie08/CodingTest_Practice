#include <iostream>
#include <vector>
#include <cmath> // pow

/*
* �̿ϼ� (number�� 1�� ��쿡�� ����)
* 
* DFS/BFS - Ÿ�� �ѹ�
* https://programmers.co.kr/learn/courses/30/lessons/43165
*/

// acc: �����Ͽ� ���� ��
void DFS(int k, int acc, int* tree, int nodeMax)
{
	if (k >= nodeMax)
		return;
	else if (k == 1) // main���� ù ȣ��ÿ��� ����
		tree[k] = acc;
	else
		tree[k] = tree[k / 2] + acc; // tree[k/2]�� �θ���

	DFS(2 * k, -1, tree, nodeMax); // ���� (-1 ����)
	DFS(2 * k + 1, +1, tree, nodeMax); // ������ (+1 ����)

}


int solution(std::vector<int> numbers, int target) {
    int answer = 0;

	int level = numbers.size();
	//int nodes = pow(2, level + 1) - 1; // ��ȭ����Ʈ���� ��� ��� ������ 2^(Ʈ������+1) - 1
	int nodes = pow(2, level + 1); // ���ǻ� index=1���� ������ �Ŷ� +1

	// �����Ҵ�
	int* arr = new int[nodes];

	// �ʱ�ȭ
	for (int i = 0; i < nodes; i++) // 2^(5-1) = 2^4 =16
		arr[i] = i;
		
	// DFS
	DFS(1, 0, arr, nodes);

	/*
	// Ȯ�ο� ���
	std::cout << arr[1];
	for (int i = 2; i < nodes; i++)
	{
		// �ٹٲ� (2�� ���������� �Ǻ�)
		if ((i & (i - 1)) == 0)
			std::cout << std::endl;

		std::cout << arr[i] << "  "; // �� ������ 0�� null?
	}
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
	std::vector<int> numbers = { 1, 1, 1, 1, 1 };
	//std::vector<int> numbers = { 1, 1, 1 };
	int target = 3;

	std::cout << solution(numbers, target); // 5
	return 0;
}