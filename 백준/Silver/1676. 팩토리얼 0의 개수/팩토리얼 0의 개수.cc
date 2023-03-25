//참고 : https://itadventure.tistory.com/22
#include <iostream>

#include <algorithm>

#include <vector>

using namespace std;

int main()

{

    int N;

    int result = 0;

    cin >> N;

    for(int i=N; i>0; i--)

    {

    	int tmp = i;

    	while(tmp % 5 ==0)

    	{

    		if(tmp%125==0)

    		{

    			result += 3;

	    		tmp /= 125;

	    	}

   	 	else if(tmp%25==0)

   	 	{

    			result += 2;

    			tmp /= 25;

   	 	}

   	 	else if(tmp%5==0)

   	 	{

    			result++;

    			tmp /= 5;

 	   	}

    	}

    }

    cout << result << '\n';

    

}