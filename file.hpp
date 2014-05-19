/*|=====================================
 *|  Copyright (c) 2011-2014 hightoro
 *|  All rights reserved
 *|=====================================
 */

#ifndef HIGHTORO_CPP_ORIGINAL_FILE_FUNCTIONS_H
#define HIGHTORO_CPP_ORIGINAL_FILE_FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <exception>
#include <stdexcept>
#include <iomanip>

#include "../pporig/tags.hpp"

namespace pporig{

/* -------- *
 *|  open  |*
 * -------- */
template<typename T>
T& open( T& file, const std::string& name )
{
  // file open
  file.open(name);

  // open check ( throw exception )
  if( !file.is_open() ){
    std::string error_s("File not Found Exception -> file's name is [ "); error_s+=name; error_s+=" ]";
    throw std::logic_error(error_s);
  }

  // infomation
  std::cout << tags::INFO <<  "Open File [ " << name << " ] OK!" << std::endl;

  return file;
}

/* --------------- *
 *|  file_string  |*
 * --------------- */
template<template<typename...>class strT, typename charT=char, typename traits=std::char_traits<charT>,char del_='\n'>
class file_string
{
public:
  using io_type = strT<charT,traits>;
  using s_type  = std::basic_string<charT>;

private:
  s_type                 name_;  // file name
  io_type                file_;  // file stream
  s_type                 line_;  //
  unsigned int           num_;   // line num;

  //s_type                 del_;


public:
  /*+----------------------------+*
   *|  Constructor & Destructor  |*
   *+----------------------------+*/
  file_string()=delete;
  ~file_string()=default;
  /*+--------------------+*
   *|  Copy Constructor  |*
   *+--------------------+*/
  file_string(const file_string&)=delete;
  file_string& operator=(const file_string&)=delete;
  /*+--------------------+*
   *|  Move Constructor  |*
   *+--------------------+*/
  file_string(file_string&&)=default;
  file_string& operator=(file_string&&)=default;
  /*+---------------------+*
   *|  Other Constructor  |*
   *+---------------------+*/
  file_string(const s_type& f):
    name_(f),file_(),line_("(bof)"),num_(0)
  { open(file_,f); /*get_line(file_,line_);*/  }

  // get next line
  const s_type& pop_line(){ getline_ew(); return line_; }
  const s_type& pop_line(const s_type& s){ do{pop_line();}while(line_.find(s)==s_type::npos); return line_; }
  unsigned int  get_num()const{ return num_; }
  char          get_delim()const{ return del_; }
  const s_type& get_line()const{ return line_; }

  // stream strait
  bool          eof()const{ return static_cast<bool>(file_.eof()); }

  // move current line
  const s_type& operator++(){ return pop_line(); }
  const s_type  operator++(int){ s_type s=line_; pop_line(); return s; }

  // show line
  //template<typename charT,typename triats>
  friend std::basic_ostream<charT,traits>& operator<<( std::basic_ostream<charT,traits>& ostr,const file_string& lhs)
  {
    std::basic_ostringstream<charT,traits> num;
    num << "(" << lhs.num_ << ")";
    std::basic_ostringstream<charT,traits> str;
    str << std::setw(7) << std::right << num.str()
        << "|" << lhs.line_;
    return ostr << str.str();
  }

  // while space eliminate getline
  bool getline_ew()
  {
    while( std::getline(file_,line_,del_) ){
      num_++; // line_ctr increment
      if( line_.length()<2 ) continue;
      //if( line_.find(co)!=std::basic_string<charT>::npos ) continue;
      return true;
    }
    line_="(eof)";
    return false;
  }

};

using ifstring = file_string<std::basic_ifstream>;

}

#endif
