#pragma once
#include <iostream>
#include <string.h>

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#define LOG(msg) std::cout << __FILENAME__ << " (" << __LINE__ << "): " << msg << std::endl

// DEBUG_LOG
#define __DEBUG_MODE__ 0
#if __DEBUG_MODE__
#define DEBUG_LOG(msg) LOG(msg)
#else
#define DEBUG_LOG(msg)
#endif

// THROW_MSG
#define STRINGIZE_DETAIL(x) #x
#define STRINGIZE(x) STRINGIZE_DETAIL(x)
#define __LINE_STR__ STRINGIZE(__LINE__)
#define THROW_MSG(msg) " (" __LINE_STR__ "): " #msg
