#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
using namespace std;

#ifdef DEBUG
#define REQUIRE(x) assert(x)
#define TEST_CASE(doc, case) int main()
#else
#define CATCH_CONFIG_MAIN
#include "../Catch2/single_include/catch2/catch.hpp"
#endif