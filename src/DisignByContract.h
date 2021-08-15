//============================================================================
// Name        : DesignByContract.h
// Author      : Serge Demeyer
// Version     :
// Copyright   : Project Software Engineering - BA1 Informatica - Serge Demeyer
// - University of Antwerp Description : Declarations for design by contract in
// C++
//============================================================================

#include <assert.h>

#ifdef __linux__

#define REQUIRE(assertion, what) \
  if (!(assertion)) __assert(what, __FILE__, __LINE__)

#define ENSURE(assertion, what) \
  if (!(assertion)) __assert(what, __FILE__, __LINE__)

#elif _WIN32

#define REQUIRE(assertion, what) \
  if (!(assertion)) _assert(what, __FILE__, __LINE__)

#define ENSURE(assertion, what) \
  if (!(assertion)) _assert(what, __FILE__, __LINE__)

#endif