#include <stdio.h>

int main()
{
    int N;           // 첫째 줄에 단어의 개수 N이 들어온다
    scanf("%d", &N); // N은 100보다 작거나 같은 자연수
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        char word[100];          // 둘째 줄부터 N개의 줄에 단어가 들어온다
        char alphabet[26] = {0}; // 길이는 최대 100이다
        scanf("%s", word);
        int j = 0;
        count++; // 그룹단어일거라고 가정하고 시작
        while (word[j])
        {
            char tmp = word[j];
            if (tmp >= 'a' && tmp <= 'z')
            {
                if (alphabet[tmp - 97] == 0)
                {
                    // 최초 방문
                    alphabet[tmp - 97] = 1;
                    while (tmp == word[j])
                        j++;
                    continue;
                }
                else
                {
                    // 다시 방문 -> 그룹 단어 아님
                    count--;
                    break;
                }
            }
            j++;
        }
    }
    printf("%d\n", count);
}