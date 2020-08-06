#include "List.cpp"
#include <iostream>
using namespace std;

int main()
{
    int a = rand() % 5;
    int last = 0;
    int position = 0;
    List<int> x2;

    for (int i = 0; i < 20; i++)
    {
        x2.add(a);
        a = rand() % 5;
    }

    x2.print();

    cout << "break" << endl;

    for (int i = 0; i < 3; i++)
    {
        a = rand() % 5;
        position = x2.get(a);

        if (position == -1)
        {
            continue;
        }
        else
        {
            x2.remove(position);
            cout << "removed " << a << " at position " << position << endl;
        }      
        
        
    }

    x2.print();
    cout << "break" << endl;

    
    for (int l = 0; l < 3; l++)
    {
        a = rand() % 5;
        position = x2.get(a);

        if (position == -1)
        {
            continue;
        }
        else
        {           
            x2.first();
            for (int j = 0; j < position-1; j++)
            {
                x2.next();
            }
            x2.add(a);

            cout << "inserted " << a << " at position " << position << endl;
        }

    }

    x2.addHead(15);
    x2.print();
    //cout << "break" << endl;
    
    return 0;

}