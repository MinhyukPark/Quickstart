#include <iostream>
#include "library.h"

int main(int argc, char* argv[]) {
    std::cout<<"main"<<std::endl;
    Library* library = new Library();
    std::cout<<library->square(5)<<std::endl;
}
