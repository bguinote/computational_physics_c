#include <iostream>
#include <iomanip>

using namespace std;

int lista = 3;
int ary[3];

int main()
{
    cout << "Insira os elementos da lista: " << endl;
    for (int i = 0; i < lista; i++)
    {
        cin >> ary[i];
    }

    for (int i = 0; i < lista; i++)
    {
        cout << "Para valor = " << ary[i] << endl;
        cout << "o dobro eh: " << ary[i] * 2 << endl;
    }
    return 0;
}