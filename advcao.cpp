#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    string nome1 = "fisica";
    string guess;
    int guesscount = 0;
    int guesslimit = 3;
    bool outofguess = false;

    cout << "Advinhe a palavra: \n";

    while (nome1 != guess && !outofguess) // && = duas condicoes != diferente ! nedoksodfgacao
    {
        if (guesscount < guesslimit)
        {
            cout << "Palpite: ";
            cin >> guess;
            guesscount++;
        } else
        {
            outofguess = true;
        }
    }
    if (outofguess)
    {
        cout << "you lose!";
    } else
    {
        cout
            << "you win!";
    }
    return 0;
}
