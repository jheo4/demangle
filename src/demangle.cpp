#include "demangle.hpp"

#if defined( __clang__ ) && defined( __has_include )
# if __has_include(<cxxabi.h>)
# include <cxxabi.h>
# endif
#elif defined( __GLIBCXX__ ) || defined( __GLIBCPP__ )
# include <cxxabi.h>
#endif

#ifdef INJECT_NAMESPACE
#define INJECTION DEMANGLE_NAMESPACE::
#endif

#if defined( _CXXABI_H )
std::string 
INJECTION demangle(const char *name) {
  int status = -4;
  char *res = abi::__cxa_demangle(name, NULL, NULL, &status);
  const char *const demangled_name = (status == 0) ? res : name;
  const std::string val( demangled_name );
  std::free( res );
  return( val );
}
#else /** no CXX ABI header not much we can do **/
std::string 
INJECTION demangle(const char *name) { return std::string(name); }
#endif
