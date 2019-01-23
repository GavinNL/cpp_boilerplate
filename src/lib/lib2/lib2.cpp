#include <lib2/lib2.h>
#include <iostream>

#include <lib1/lib1.h>

namespace lib2
{
    Bar::Bar()
    {
        std::cout << "Bar Created" << std::endl;
    }

   Bar::~Bar()
    {
        std::cout << "Bar destroyed" << std::endl;
        lib1::foo(4);
    }

}
