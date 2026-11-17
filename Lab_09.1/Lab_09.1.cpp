#include <iostream>
#include <iomanip>
#include <cmath>
#include "dod.h"
#include "sum.h"
#include "var.h"

using namespace std;
using namespace nsDod;
using namespace nsSum;
using namespace nsVar;

int main() {
    cout << "Vvedit pochatkove znachennya x_p (|x| > 1): "; cin >> x_p;
    cout << "Vvedit kinceve znachennya x_k (|x| > 1): ";   cin >> x_k;
    cout << "Vvedit krok dx: ";                            cin >> dx;
    cout << "Vvedit tochnist eps: ";                      cin >> e;
    cout << endl;

    // Виведення заголовка та шапки таблиці
    cout << "   Tablytsya znachen funktsiyi ln((x + 1)/(x - 1))" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "|" << setw(10) << "x" << " |"
        << setw(15) << "ln((x+1)/(x-1))" << " |"
        << setw(15) << "Suma ryadu" << " |"
        << setw(10) << "Dodankiv" << " |" << endl;
    cout << "-----------------------------------------------------------" << endl;

    x = x_p;
    while (x <= x_k + dx / 2.0) { // + dx/2.0 для уникнення похибки округлення типу double
        if (fabs(x) <= 1.0) {
            cout << "|" << setw(10) << fixed << setprecision(3) << x << " |"
                << setw(44) << "Pomylka: |x| maye buty > 1! |" << endl;
        }
        else {
            sum(); // обчислення суми ряду та кількості доданків
            double exactValue = log((x + 1.0) / (x - 1.0)); // точне значення функції

            cout << "|" << setw(10) << fixed << setprecision(3) << x << " |"
                << setw(15) << setprecision(6) << exactValue << " |"
                << setw(15) << setprecision(6) << s << " |"
                << setw(10) << n << " |" << endl;
        }
        x += dx;
    }
    cout << "-----------------------------------------------------------" << endl;

    return 0;
}