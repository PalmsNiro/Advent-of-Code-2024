#include <iostream>
#include "Day2.hpp"

int main()
{
    std::cout << "Test: "<<('1' < '2' ? false : true) << std::endl;
    Day2 d;
    d.solve();
    return EXIT_SUCCESS;
}
