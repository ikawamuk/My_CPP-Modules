#ifndef DEBUG_MODE_HPP_
# define DEBUG_MODE_HPP_

#include <iostream>

#ifdef DEBUG
	#define PRINT_DEBUG(msg) std::cerr << "[DEBUG] " << msg << std::endl;
#else
	#define PRINT_DEBUG(msg)
#endif

#endif
