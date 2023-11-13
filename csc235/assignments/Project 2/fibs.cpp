#include <iostream>
using namespace std;

#define NUM 25

int main()
{
    int fibs[NUM] = {1, 1};

    for (int i = 0; i < NUM - 2; i++)
    {
        fibs[i + 2] = fibs[i] + fibs[i + 1];
    }

    for (int i = NUM - 1; i >= 0; i--)
    {
        cout << fibs[i] << endl;
    }
}
