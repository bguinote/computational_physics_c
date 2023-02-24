#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;


int main()
{
    const int MAXVALUEs = 11; //definir valor constante de valores maximos
    double VLoadData[MAXVALUEs]; //valores de carga
    double VDeflectionData[MAXVALUEs]; //valores de deflexão
    double VSlopes[MAXVALUEs]; //valores da curva
    string Vprompts[] = { "primeiro", "segundo", "terceiro", "quarto",
                        "quinto", "sexto", "setimo", "oitavo",
                        "nono", "decimo" };
    double Load; //cargas
    double Deflection; //deflexão

    //inicialização
    int point = 0; //pontos sempre começando em 0.0
    VLoadData[point] = 0.0;
    VDeflectionData[point++] = 0.0;

    for (;;) // loop ate nao dar mais nenhum valor
    {
        cout << "coloque o " << Vprompts[point - 1] << " valor de Carga e Deflexao (para parar, coloque 0): ";
        cin >> Load >> Deflection;

        if (Load == 0.0) //caso coloque valores não coerentes com o que foi pedido
            break;
        else if (Load < 0.0 || Load <= 0.0)
            cout << "Carga e Deflexão tem que ser valores positivos. \n";
        else if (Load <= VLoadData[point - 1]) // valor menor que o anterior
            cout << "Valores de carga tem que ser em ordem crescente. \n";
        else
        {
            VLoadData[point] = Load;
            VDeflectionData[point++] = Deflection;

            if (point == (MAXVALUEs - 1))
                break;
        }
    }
    // calculo da curva
    int i;
    int Segments = point - 1;
    for (i = 0; i < Segments; i++)
    {
        VSlopes[i] = (VLoadData[i + 1] - VLoadData[i]) / (VDeflectionData[i + 1] - VDeflectionData[i]);
    }
    // achar curva não linear da carga
    double tolerance = 1.0e-3;
    double NonLinearValue = 0.0;
    for (i = 0; i < Segments - 1; i++)
    {
        if (fabs(VSlopes[i + 1] - VSlopes[i]) > tolerance)
        {
            NonLinearValue = VLoadData[i + 1];
            break;
        }
    }

    // resultados
    cout << endl << " Resultados finais";
    cout << endl << "---------------------------" << endl;
    cout << "Carga" << "   " << "Deflexao" << "   " << "Curva\n";
    cout << "---------" << "" << "-----------" << "" << "----------\n";
    cout << setiosflags(ios::left) << setw(7) << VLoadData[0] << " "
        << setw(10) << VDeflectionData[0]
        << endl;
    for (i = 1; i < point; i++)
    {
        cout << setiosflags(ios::left)
            << setw(7) << VLoadData[i] << " "
            << setw(10) << VDeflectionData[i] << " "
            << setw(10) << VSlopes[i - 1] << endl;
    }
    if (NonLinearValue == 0.0)
        cout << "\nA resposta eh linear.\n";
    else
        cout << "\n Ela torna-se nao-linear no valor " << NonLinearValue << endl;

    return 0;
}