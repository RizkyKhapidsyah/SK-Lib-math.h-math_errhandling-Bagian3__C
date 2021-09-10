#pragma warning(disable:4996)
#pragma fenv_access(on)

#include <iostream>
#include <cfenv>
#include <cmath>
#include <cerrno>
#include <cstring>
#include <conio.h>

/*
    Source by CPPReference
    Modified For Learn by RK
    I.D.E : VS2019
*/

int main() {
    std::cout << "MATH_ERRNO is "
        << (math_errhandling & MATH_ERRNO ? "set" : "not set") << '\n'
        << "MATH_ERREXCEPT is "
        << (math_errhandling & MATH_ERREXCEPT ? "set" : "not set") << '\n';
    std::feclearexcept(FE_ALL_EXCEPT);
    errno = 0;
    std::cout << "log(0) = " << std::log(0) << '\n';
    if (errno == ERANGE) {
        std::cout << "errno = ERANGE (" << std::strerror(errno) << ")\n";
    }
        
    if (std::fetestexcept(FE_DIVBYZERO)) {
        std::cout << "FE_DIVBYZERO (pole error) reported\n";
    }
        
    _getch();
    return 0;
}