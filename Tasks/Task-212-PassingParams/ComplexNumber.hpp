#include "mbed.h"


typedef struct {
  double real;
  double imag;
} ComplexNumber_C;

ComplexNumber_C complexAdd(const ComplexNumber_C a, const ComplexNumber_C b)

void complexDisplay(const char *strName, const ComplexNumber_C u)

// TASK - write and test complexConjugate, complexNegate, complexSubtract, complexMagnitude, complexMultiply and complexDivide

ComplexNumber_C complexConjugate(const ComplexNumber_C c)

ComplexNumber_C complexNegate(const ComplexNumber_C n)

ComplexNumber_C complexSubtract(const ComplexNumber_C a, const ComplexNumber_C b)
ComplexNumber_C complexMagnitude(const ComplexNumber_C m)

ComplexNumber_C complexMultiply(const ComplexNumber_C a, const ComplexNumber_C b)

ComplexNumber_C complexDivide(ComplexNumber_C a, ComplexNumber_C b) 

void complexNegateInplace(ComplexNumber_C& u)

void complexConjugateInplace(ComplexNumber_C& c)
