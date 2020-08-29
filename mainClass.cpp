
#include "Queue.cpp"
#include <iostream>
using namespace std;

int main()
{
    int number = rand() % 100;
    Queue<int> x2(20);

    for (int i = 0; i < 20; i++)
    {
        x2.enqueue(number);
        number = rand() % 100;
    }

    x2.print();
    cout << "break" << endl;

    number = rand() % 20;

    cout << number << endl;

    for (int j = 0; j < number; j++)
    {
        x2.dequeue();
    }
    x2.print();
    return 0;

}