#include <iostream>

using namespace std;

int main(void)

{

    int c[5] = {0};

    int *p;

    int i;

    p = &(c[1]);

    for (i = 0; i < 2; i++)

    {

        p[i] = 2;

    }

    for (i = 0; i < 5; i++)

    {

        cout<<c[i]<<" ";

    }

    cout<<endl;

}
