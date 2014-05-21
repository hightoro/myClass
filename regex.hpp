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
  inline sregex regex(std::string&& s){ return std::move(sregex::compile(s)); };

  //////////////////
  // regex_range
  template<
    class BidirIt,
    class CharT   = typename std::iterator_traits<BidirIt>::value_type,
    class Traits  = regex_traits<CharT>
    >
  class regex_range
  {
    CharT              str_;
    basic_regex<CharT> reg_;
  public:
    regex_range(CharT const& t,basic_regex<CharT> const& r):str_(t),reg_(r){}
    regex_range(CharT&& t,basic_regex<CharT>&& r):str_(t),reg_(r){}
    regex_iterator<BidirIt> begin(){return regex_iterator<BidirIt>(str_.begin(),str_.end(),reg_);}
    regex_iterator<BidirIt> end(){return regex_iterator<BidirIt>();}
  };
  using cregex_range  = regex_range<const char*>;
  using wcregex_range = regex_range<const wchar_t*>;
  using sregex_range  = regex_range<std::string::const_iterator>;
  using wsregex_range = regex_range<std::wstring::const_iterator>;

  //////////////////
  // regex_token_range


}


#endif
