#include "test_framework.h"

int main(int argc, char** argv) {
    testing::TestRunner runner;
    return runner.run_all_tests();
}
