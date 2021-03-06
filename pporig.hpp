/*|=====================================
 *|  Copyright (c) 2011-2014 hightoro
 *|  All rights reserved
 *|=====================================
 */

#ifndef NAME_ORIGINAL_FUNCTION_H
#define NAME_ORIGINAL_FUNCTION_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

#include <boost/format.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/xpressive/xpressive.hpp>
n
amespace pporig
{
  //////////////////////////////////////////////////////////////////////////////////
  // stream

  /* ----------------- *
   *| escape sequence |*
   * ----------------- */
  struct console
  {
    template<typename T>
    static void error_print(T t){   return std::cout << ERROR << t << std::endl; }
    template<typename T>
    static void warning_print(T t){ return std::cout << WARN 　<< t << std::endl; }
    template<typename T>
    static void info_print(T t){    return std::cout << INFO 　<< t << std::endl; }

    static constexpr char* ERROR  = (char*)"\x1b[1;4;31m [ERROR]  : \x1b[0m: ";
    static constexpr char* WARN   = (char*)    "\x1b[34m [WARNING]: \x1b[0m: ";
    static constexpr char* INFO   = (char*)  "\x1b[1;33m [INFO]   : \x1b[0m: ";
    static constexpr char* WS     = (char*)"           ";
  };

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // string

  /* --------- *
   *|  split  |*
   * --------- */
  //template <template<class Type, class... Args> class Container = std::vector>
  //Container<T> split( T const& line, T const& demilita )
  template<typename T=std::vector<std::string> >
  T split( std::string const& line, std::string const& demilita )
  {
    T array;

    boost::algorithm::split( array, line, boost::is_any_of(demilita),
                             boost::algorithm::token_compress_on );
    if( array.front().empty() ) array.erase( array.begin() );
    if( array.back().empty() ) array.pop_back();

    return std::move(array);
  }
  template<typename T=std::vector<std::string>>
  T split( std::string const& line )
  { return std::move( split(line," \t\n") ); }


  /////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // container

  /* ------------- *
   *|  pop_front  |*
   * ------------- */
  template <template<class Type, class... Args> class Container,typename T>
  T pop_front( Container<T>& array )
  {
    auto front = array.front();
    array.erase( array.begin() );
    return std::move(front);
  }

  /* ------------------ *
   *|  range for_each  |*
   * ------------------ */
  template <typename T_container, typename T_function>
  T_function for_each(T_container& rcontainer, T_function function) {
    return for_each(rcontainer.begin(), rcontainer.end(), function);
  }


  /////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // regex


  /////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

#endif // NAME_ORIGINAL_FUNCTION_H
