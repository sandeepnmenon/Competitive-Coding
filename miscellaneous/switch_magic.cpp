#include <iostream>
using namespace std;

int main()
{

    int count = 7;
    switch (
        count % 5)
    {
    case 0:
        while (--count > 0) // for (; --count > 0;)
        {
            cout << count % 5 << endl;
        case 1:
            cout << count % 5 << endl;
        case 2:
            cout << count % 5 << endl;
        case 3:
            cout << count % 5 << endl;
        case 4:
            cout << count % 5 << endl;
        }
    }

    return 0;
}