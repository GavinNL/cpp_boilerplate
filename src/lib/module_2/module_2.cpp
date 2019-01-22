#include <module2/module2.h>
#include <iostream>

#include <boilerplate/boilerplate.h>

namespace module2
{
    Bar::Bar()
    {
        std::cout << "Bar Created" << std::endl;
    }

   Bar::~Bar()
    {
        std::cout << "Bar destroyed" << std::endl;
        boilerplate::foo(4);
    }

}
