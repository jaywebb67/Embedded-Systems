#include "studio.h"




typedef struct {
  double real;
  double imag;
} ComplexNumber_C;

ComplexNumber_C complexAdd(const ComplexNumber_C a, const ComplexNumber_C b) {
    ComplexNumber_C y = a;
    y.real += b.real;
    y.imag += b.imag;
    return y;
}

void complexDisplay(const char *strName, const ComplexNumber_C u) {
    printf("%s = %f + j%f\n", strName, u.real, u.imag);
}

// TASK - write and test complexConjugate, complexNegate, complexSubtract, complexMagnitude, complexMultiply and complexDivide
