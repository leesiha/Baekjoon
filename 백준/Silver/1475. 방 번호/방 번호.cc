#include <iostream>
using namespace std;
int main()
{
    string N;
    int set[10] = {1,1,1,1,1,1,1,1,1,1};
    cin >> N;
    int i = 0;
    int need = 1;    
    while (N[i])
    {
        if (set[N[i]-'0']) //해당 플라스틱 숫자가 있을 경우
        {
            set[N[i]-'0']--; // 사용
        }
        else //해당 플라스틱 숫자가 없을 경우
        {
            if ((N[i] == '6') && set[9]) //만약 6없는데 9가 있다면
                set[9]--;
            else if ((N[i] == '9') && set[6]) //만약 9없는데 6이 있다면
                set[6]--;
            else
            {
                // 그 외에는 세트를 하나 더 사고 사용해줘야함
                need++;
                for (int j = 0; j < 10; j++)
                    set[j]++;
                set[N[i]-'0']--;
            }
        }
        i++;
    }
    cout << need << endl;
}