#include "dod.h"
#include "var.h"

using namespace nsVar;

void nsDod::dod() {
    // Домножуємо попередній доданок на коефіцієнт рекурентності R = (2n - 1) / ((2n + 1) * x^2)
    a *= (2.0 * n - 1) / ((2.0 * n + 1) * x * x);
}