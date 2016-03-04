#include <iostream>

using namespace std;

int myFunction(int *a);

int main (void)

{

    int b = 1;

    int c = 1;

    c = myFunction(&b);



    cout << b <<" "<<c << endl;





    return 0;

}

int myFunction(int *a)

{

    *a = *a*2;

    return *a + 1;

}
