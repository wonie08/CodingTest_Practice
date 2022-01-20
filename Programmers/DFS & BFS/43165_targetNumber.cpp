#include <iostream>
#include <vector>
#include <cmath> // pow

/*
* DFS/BFS - 타겟 넘버
* https://programmers.co.kr/learn/courses/30/lessons/43165
*/


// acc: 누적하여 더할 값
void DFS(int k, int acc, int* tree, std::vector<int>& numbers, int count, int nodeMax)
{
	if (k >= nodeMax)
		return;
	else if (k == 1) // main에서 첫 호출시에만 실행
		tree[k] = acc; // tree[1] = 0;
	else
		tree[k] = tree[k / 2] + acc; // tree[k/2]는 부모노드

	if (count < (int)numbers.size() - 1)
	{
		++count; // -1 → 0
		acc = numbers[count]; // acc = numbers[0] = 1
	}
	else
		return;

	DFS(2 * k, -acc, tree, numbers, count, nodeMax); // 왼쪽 (-1 더함)
	DFS(2 * k + 1, +acc, tree, numbers, count, nodeMax); // 오른쪽 (+1 더함)
}


int solution(std::vector<int> numbers, int target) {
    int answer = 0;

	int level = numbers.size();
	//int nodes = pow(2, level + 1) - 1; // 포화이진트리의 모든 노드 갯수는 2^(트리높이+1) - 1
	int nodes = pow(2, level + 1); // 편의상 index=1부터 시작하기 때문에 +1

	// 동적할당
	int* arr = new int[nodes];

	// 초기화
	for (int i = 0; i < nodes; i++) // 2^(5-1) = 2^4 =16
		arr[i] = 0;
	
	// DFS
	DFS(1, 0, arr, numbers, -1, nodes);

	/*
	// 확인용 출력
	std::cout << arr[1];
	for (int i = 2; i < nodes; i++)
	{
		// 줄바꿈 (2의 제곱수인지 판별)
		if ((i & (i - 1)) == 0)
			std::cout << std::endl;

		std::cout << arr[i] << "  "; // 맨 마지막 0은 null
	}
	std::cout << std::endl << std::endl;
	*/

	// 트리의 마지막 레벨에 있는 노드의 갯수는 2^level
	int start = nodes - (int)pow(2, level);
	for (int i = start; i < nodes; i++)
	{
		if (arr[i] == target)
			answer++;
	}

	// 동적할당 해제
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