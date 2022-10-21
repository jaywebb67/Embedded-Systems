#include "mbed.h"
#include "ComplexNumber.hpp"




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

ComplexNumber_C complexConjugate(const ComplexNumber_C c){
    ComplexNumber_C y = c;
    y.imag = -y.imag;
    return y;
}

ComplexNumber_C complexNegate(const ComplexNumber_C n) {
    
    ComplexNumber_C y;
    y.real = -n.real;
    y.imag = -n.imag;
    return y;
}

ComplexNumber_C complexSubtract(const ComplexNumber_C a, const ComplexNumber_C b) {
    
    ComplexNumber_C y;
    y.real = a.real - b.real;
    y.imag = a.imag - b.imag;
    return y;
}

ComplexNumber_C complexMagnitude(const ComplexNumber_C m) {
    
    double result;
    result = sqrt(m.real*m.real + m.imag*m.imag);
    return result;
}


ComplexNumber_C complexMultiply(const ComplexNumber_C a, const ComplexNumber_C b) {
    
    ComplexNumber_C result;
    result.real = (a.real*b.real) -1*(a.imag*b.imag);
    result.imag = (a.real*b.imag)+(a.imag*b.real);
    return result;
}

ComplexNumber_C complexDivide(ComplexNumber_C a, ComplexNumber_C b) {
    
    ComplexNumber_C result, NUM,DEN, conj;
    conj = complexConjugate(b);
    NUM = complexMultiply(a,conj);
    DEN = complexMultiply(b,conj);
    
    if(DEN.imag==0){
        result.real = NUM.real/DEN.real;
        result.imag = NUM.imag/DEN.real;
    }
    return result;
}

void complexNegateInplace(ComplexNumber_C& u) {
    u.imag = -u.imag;
    u.real = -u.real;
}

void complexConjugateInplace(ComplexNumber_C& c) {
    c.imag = -c.imag;
}
