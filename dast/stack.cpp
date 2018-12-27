#include <iostream>

using namespace std;

typedef struct Element{
    struct Element *next;
    void *data;
} Element;


