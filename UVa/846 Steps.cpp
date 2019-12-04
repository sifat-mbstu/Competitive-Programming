#include <iostream>

using namespace std;

int main()
{
    int nc, steps, m, n, diff;
    cin >> nc;

    for (int i = 0; i < nc; i++)
    {
        cin >> m >> n;
        diff = n - m;
        steps = 0;
        if (diff != 0)
        {
            unsigned int k = 0;     /* the limit for the sum of steps */
            unsigned int f = 2; /* divided by two, it represents the size of the next step */
            while (k < diff)
            {
                k += (f / 2); /* next step */
                steps++;
                f++;
            }
        }
        cout << steps << endl;
    }
    return 0;
}
