#pragma once
#include <sstream>

template < typename T > inline std::string to_string( const T& n )
{
  std::ostringstream stm ;
  stm << n ;
  return stm.str() ;
}
