/*|=====================================
 *|  Copyright (c) 2011-2014 hightoro
 *|  All rights reserved
 *|=====================================
 */

#ifndef NAME_ORIGINAL_FUNCTION_H
#define NAME_ORIGINAL_FUNCTION_H

#include

namespace pporig
{
  //////////////////////////////////////////////////////////////////////////////////
  // stream

  /* ----------------- *
   *| escape sequence |*
   * ----------------- */
  struct console
  {
    template<typename T>
    static void error_print(T t){   return cout << error   << t << endl; }
    template<typename T>
    static void warning_print(T t){ return cout << warning << t << endl; }
    template<typename T>
    static void info_print(T t){    return cout << info    << t << endl; }

    static constexpr char* ERROR  = (char*)"\x1b[1;4;31m [ERROR]  : \x1b[0m: ";
    static constexpr char* WARN   = (char*)    "\x1b[34m [WARNING]: \x1b[0m: ";
    static constexpr char* INFO   = (char*)  "\x1b[1;33m [INFO]   : \x1b[0m: ";
    static constexpr char* WS     = (char*)"           ";
  };

  /* -------- *
   *|  open  |*
   * -------- */
  template<typename T>
  T& open( T& file, const std::string& f_name )
  {
    // file open
    file.open(f_name);

    // open check ( throw exception )
    if( !file.is_open() ){
      std::string error_s("File not Found Exception -> file's name is [ "); error_s+=name; error_s+=" ]";
      throw std::logic_error(error_s);
    }

    // infomation
    std::cout << console::info <<  "Open File [ " << name << " ] OK!" << endl;
  }



  /////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // string

  /* --------- *
   *|  split  |*
   * --------- */
  //template <template<class Type, class... Args> class Container = std::vector>
  //Container<T> split( T const& line, T const& demilita )
  template<typename T=std::vector<std::string>>
  T split( std::string const& line )
  {
    T array;

    boost::algorithm::split( array, line, boost::is_any_of(demilita),
                             boost::algorithm::token_compress_on );
    if( array.front().empty() ) array.erase( array.begin() );
    if( array.back().empty() ) array.pop_back();

    return std::move(array);
  }
  template<typename T=std::vector>
  T<std::string> split( std::string const& line )
  { return std::move( split(line," \t\n") ); }


  /////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // container

  /* ------------- *
   *|  pop_front  |*
   * ------------- */
  template <template<class Type, class... Args> class Container,typename T>
  U pop_front( T<U>& array )
  {
    string front = array.front();
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

  /* --------------------------- *
   *|  regex (boost/xpressive)  |*
   * --------------------------- */
  using namespace boost::xpressive;
  inline sregex regex(std::string const& s){ return std::move(sregex::compile(s)); };


#endif // NAME_ORIGINAL_FUNCTION_H
