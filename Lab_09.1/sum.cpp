#include <cmath>
#include "dod.h"
#include "sum.h"
#include "var.h"

using namespace nsDod;
using namespace nsVar;

void nsSum::sum() {
    n = 0;
    a = 2.0 / x; // перший доданок ряду (з урахуванням множника 2)
    s = a;

    do {
        n++;
        dod();      // обчислення наступного доданку
        s += a;     // накопичення суми
    } while (fabs(a) >= e);

    n++; // загальна кількість просумованих доданків (включаючи нульовий)
}