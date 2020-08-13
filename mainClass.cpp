#include "List.cpp"
#include <iostream>
using namespace std;

int main()
{
    int a = rand() % 5;
    int last = 0;
    int position = 0;
    List<int> x2;

    for (int i = 0; i < 5; i++)
    {
        x2.add(a);
        a = rand() % 5;
    }

    x2.print();
    x2.first();
    x2.prev();
    cout << "break" << endl;

    x2.printCurrent();


    return 0;

}