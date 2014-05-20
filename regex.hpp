/*|=====================================
 *|  Copyright (c) 2011-2014 hightoro
 *|  All rights reserved
 *|=====================================
 */

#ifndef HIGHTORO_CPP_ORIGINAL_REGEX_H
#define HIGHTORO_CPP_ORIGINAL_REGEX_H


#include <string>
#include <boost/xpressive/xpressive.hpp>

namespace pporig{

  using namespace boost::xpressive;
  inline sregex regex(const std::string& s){ return std::move(sregex::compile(s)); };

  template<
    class BidirIt,
    class CharT = typename std::iterator_traits<BidirIt>::value_type,
    class Traits = std::regex_traits<CharT>
    > class regex_range
  {
    CharT target_;
    boost::xpressive::basic_regex<CharT> reg_;
  public:
    regex_range(CharT t,CharT r):target_(t),reg_(r){}
    regex_range(CharT t,basic_regex<CharT> r):target_(t),reg_(r){}
    boost::xpressive::range_iterator<> begin(){return boost::xpressive::basic_iterator();}
    boost::xpressive::range_iterator<> end(){return boost::xpressive::basic_iterator();}
  };
  using cregex_range  = regex_range<const char*>;
  using wcregex_range = regex_range<const wchar_t*>;
  using sregex_range  = regex_range<std::string::const_iterator>;
  using wsregex_range = regex_range<std::wstring::const_iterator>;

    //using eos = regex_iterator (){}
  //using regex_token_iterator (){}
}


#endif
