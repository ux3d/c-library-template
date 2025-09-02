#include <gtest/gtest.h>
extern "C" {
#include "c_library_template.h"
}

TEST(ViewmapGenerator, InitDoesNotCrash)
{
    c_library_template_init();
    SUCCEED();
}

TEST(ViewmapGenerator, CleanupDoesNotCrash)
{
    c_library_template_cleanup();
    SUCCEED();
}
