#include <iostream>

using namespace std;

int main(){

    int temp = 10;
    int *p = &temp;

    printf("%d\n",p);
    printf("%d\n",*p);
}

