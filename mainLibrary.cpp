#include <iostream>
#include <cstring>
#include <cmath>

#include "master.cpp"

using namespace std;

static int num_person = 0;


int main()
{
    Client cl;
    cl.id = 1;
    cin >> cl.name;
    cl.age = 19;
    cl.salary = 500000;
    write_client("client.txt", cl);

    return 0;
}
