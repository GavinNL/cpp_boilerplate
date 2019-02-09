#include <iostream>

#include <lib1/lib1.h>
#include <lib2/lib2.h>


int main(int argc, char ** argv)
{
    lib1::foo(3);
    lib2::Bar B;
    std::cout << "Done" << std::endl;
    return 0;

}
