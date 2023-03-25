#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

bool compare(char *str1, char *str2)
{
    if (strlen(str1) > strlen(str2)) // 1. 길이가 짧은 것부터
        return false;
    else if (strlen(str1) == strlen(str2)) // 2. 길이가 같으면 사전 순으로
    {
        // if (strcmp(words[j], words[j + 1]) == 0)
        //     words[j][0] = 0;
        return strcmp(str1, str2) < 0;
    }
    return true;
}

int main()
{
    int N;
    scanf("%d", &N); // 첫째 줄에 단어의 개수 N이 주어진다 (1 ≤ N ≤ 20,000)
    char **words = (char **)malloc(sizeof(char *) * N);
    for (int i = 0; i < N; i++) // N개의 줄에 걸쳐 알파벳 소문자로 이루어진 단어가 한 줄에 하나씩 주어진다
    {
        words[i] = (char *)malloc(sizeof(char) * 51); // 주어지는 문자열의 길이는 50을 넘지 않는다.
        words[i][50] = 0;
        scanf("%s", words[i]);
    }

    sort(words, words + N, compare);

    for (int j = 0; j + 1 < N; j++)
    {
        if (strcmp(words[j], words[j + 1]))
            printf("%s\n", words[j]);
    }
    printf("%s\n", words[N - 1]);
}