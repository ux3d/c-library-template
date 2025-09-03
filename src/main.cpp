// Include the C interface declaration
#include "c_library_template.h"
// Example use of C++
#include <iostream>
#include <string>

void c_library_template_cpp_function(void)
{
    // Use a C++ feature
    std::string example = "C++ string example";
    std::cout << "Hello from C++!" << std::endl;
}

// C interface implementation
extern "C" {
void c_library_template_init(void)
{
    c_library_template_cpp_function();
}

void c_library_template_cleanup(void)
{
    // Stub
}
}
