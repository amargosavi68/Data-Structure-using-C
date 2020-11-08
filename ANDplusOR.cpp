#include <iostream>
using namespace std;

int main() {
	// your code goes here
    short int test_cases, x, i, j, a, b;
    cin >> test_cases;
    while(test_cases != 0)
    {
        int flag = 0;
        cin >> x;
        for ( i = 0; i <= x; i++)
        {
            for ( j = 0; j <= x; j++)
            {
                if (((i & j) + (i | j)) == x)
                {
                    flag = 1;
                    a = i;
                    b = j;
                }
            }

        }

        if (flag == 1)
             cout << a <<" " << b << endl;
        else
            cout << -1 << endl;
        test_cases--;
    }
	return 0;
}
