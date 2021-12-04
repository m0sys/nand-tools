#pragma once
#include <iostream>
#include <string.h>

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#define LOG(msg) std::cout << __FILENAME__ << " (" << __LINE__ << "): " << msg << std::endl

#define __DEBUG_MODE__ 0

#if __DEBUG_MODE__
#define DEBUG_LOG(msg) LOG(msg)
#else
#define DEBUG_LOG(msg)
#endif
