#include <string>
#include <vector>
#include <algorithm> // std::find
#include <iostream>

/*
* 미해결
* 
* DFS/BFS - 단어 변환
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

    // target에 도달했으면 종료
    if (s1 == s2)
    {
        std::cout << "[" << answer << "] 도달: " << answer << std::endl << std::endl;
        answers.push_back(answer);

        visit[index] = false;
        answer--;
        return;
    }
    

    for (int i = 0; i < words.size(); i++)
    {
        // !!!!!!! 여기서 안 걸리고 통과 !!!!!!!
        if (visit[i] == true)
            continue;

        if (checkString(s1, words[i], s1.size())) // 한 글자만 다르면
        {
            if (s1 == words[i])
            {
                std::cout << "[" << answer << "] 도달: " << answer << std::endl << std::endl;
                answers.push_back(answer);
                return;
            }
            else
            {
                std::cout << "[" << answer << "] " << words[i] << std::endl;
                DFS(i, words[i], s2, words, visit, answer, answers);


                std::cout << "  --- 후퇴" << std::endl;
                answer--;
                //answer -= 2; // 갔다가(s1→words[i]) 돌아오는(words[i]→s1) 횟수 합하면 2번
            }
        }
    }



}

int solution(std::string begin, std::string target, std::vector<std::string> words) {
    int answer = 0;

    std::vector<std::string>::iterator it;
    it = std::find(words.begin(), words.end(), target);


    if (it == words.end()) // words에 target이 존재하지 X
        return 0;


    int len = begin.length();
    bool* visit = new bool[words.size()](); // 0(=false)으로 초기화
    std::vector<int> answers;

    for (int i = 0; i < words.size(); i++)
    {
        if (checkString(begin, words[i], len)) // begin이랑 한 글자만 다르면
        {
            answer++;
            std::cout << "[" << answer << "] " << words[i] << std::endl;
            DFS(i, words[i], target, words, visit, answer, answers);
        }
        else
            continue;

        // 초기화
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