#include <iostream>
using namespace std;

void count_cases(int num, unsigned int *count)
{
    if (num == 0)
        (*count)++;
    else
    {
        if (num > 0)
        {
            count_cases(num - 3, count);
            count_cases(num - 2, count);
            count_cases(num - 1, count);
        }
        
        
    }
    
}

int main()
{
    unsigned int T;
    int n;
    cin >> T;
    for (unsigned int i = 0; i < T; i++)
    {
        cin >> n;
        unsigned int count = 0;
        count_cases(n, &count);
        cout << count << endl;
    }
}