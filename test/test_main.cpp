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

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
