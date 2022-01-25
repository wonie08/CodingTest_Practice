#include <string>
#include <vector>
#include <algorithm> // std::find
#include <iostream>

/*
* ���ذ�
* 
* DFS/BFS - �ܾ� ��ȯ
* https://programmers.co.kr/learn/courses/30/lessons/43163
*/

bool checkString(std::string s1, std::string s2, int len)
{
    // HIT  vs  HOT
    int i = 0;
    int same = 0;

    while (i < len)
    {
        if (s1[i] == s2[i])
            same++;

        i++;
    }

    if (same == len - 1)
        return true;
    else
        return false;
}

void DFS(int index, std::string s1, std::string s2, std::vector<std::string>& words, bool* visit, int& answer, std::vector<int>& answers)
{
    visit[index] = true;
    answer++;

    // target�� ���������� ����
    if (s1 == s2)
    {
        std::cout << "[" << answer << "] ����: " << answer << std::endl << std::endl;
        answers.push_back(answer);

        visit[index] = false;
        answer--;
        return;
    }
    

    for (int i = 0; i < words.size(); i++)
    {
        // !!!!!!! ���⼭ �� �ɸ��� ��� !!!!!!!
        if (visit[i] == true)
            continue;

        if (checkString(s1, words[i], s1.size())) // �� ���ڸ� �ٸ���
        {
            if (s1 == words[i])
            {
                std::cout << "[" << answer << "] ����: " << answer << std::endl << std::endl;
                answers.push_back(answer);
                return;
            }
            else
            {
                std::cout << "[" << answer << "] " << words[i] << std::endl;
                DFS(i, words[i], s2, words, visit, answer, answers);


                std::cout << "  --- ����" << std::endl;
                answer--;
                //answer -= 2; // ���ٰ�(s1��words[i]) ���ƿ���(words[i]��s1) Ƚ�� ���ϸ� 2��
            }
        }
    }



}

int solution(std::string begin, std::string target, std::vector<std::string> words) {
    int answer = 0;

    std::vector<std::string>::iterator it;
    it = std::find(words.begin(), words.end(), target);


    if (it == words.end()) // words�� target�� �������� X
        return 0;


    int len = begin.length();
    bool* visit = new bool[words.size()](); // 0(=false)���� �ʱ�ȭ
    std::vector<int> answers;

    for (int i = 0; i < words.size(); i++)
    {
        if (checkString(begin, words[i], len)) // begin�̶� �� ���ڸ� �ٸ���
        {
            answer++;
            std::cout << "[" << answer << "] " << words[i] << std::endl;
            DFS(i, words[i], target, words, visit, answer, answers);
        }
        else
            continue;

        // �ʱ�ȭ
        answer = 0;
        for (int i = 0; i < words.size(); i++)
            visit[i] = false;
    }

    answer = *std::min_element(answers.begin(), answers.end());

    delete[] visit;
    return answer;
}

int main()
{
    std::string begin("hit"), target("cog");
    std::vector<std::string> words = { "hot", "dot", "dog", "lot", "log", "cog" };

    std::cout << "ANSWER " << solution(begin, target, words) << std::endl;

    return 0;
}