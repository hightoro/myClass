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
 *|  file_reader  |*
 * --------------- */
template<template<typename...>class strT, typename charT=char, typename traits=std::char_traits<charT> >
class basic_file_reader
{
public:
  using stream_t = strT<charT,traits>;
  using string_t = std::basic_string<charT>;

private:
  string_t               name_;  // file name
  stream_t               file_;  // file stream
  string_t               line_;  //

public:
  /*+----------------------------+*
   *|  Constructor & Destructor  |*
   *+----------------------------+*/
  basic_file_reader()=delete;
  ~basic_file_reader()=default;

  /*+--------------------+*
   *|  Copy Constructor  |*
   *+--------------------+*/
  basic_file_reader(const basic_file_reader&)=delete;
  basic_file_reader& operator=(const basic_file_reader&)=delete;

  /*+--------------------+*
   *|  Move Constructor  |*
   *+--------------------+*/
  basic_file_reader(basic_file_reader&&)=default;
  basic_file_reader& operator=(basic_file_reader&&)=default;

  /*+---------------------+*
   *|  Other Constructor  |*
   *+---------------------+*/
  explicit basic_file_reader(const string_t& name):
    name_(name),file_(),line_()
  { open(file_,name); }

  /* ------------- *
   *| status |*
   * ------------- */
  enum struct status
  {
    bof,
    good,
    eof,
    end
  };

  /* ------------- *
   *| Iterators |*
   * ------------- */
  class iterator : public std::iterator<std::forward_iterator_tag, string_t const>
  {
  private:
    stream_t&       file_;
    const string_t& line_;
    unsigned int    num_;
    status          st_;

  public:
    iterator( )=delete;  // default constructor (delete)
    ~iterator()=default; // destructor
    iterator(const iterator&)=default;
    iterator& operator=(const iterator&)=default;
    //
    iterator(const stream_t& file,const string_t& line):
      file_(file),
      line_(line),
      num_(0),
      st_(status::bof)
      //{ std::getline(file_,line_); st_=(file_)?status::readable:status::eof; }
    { forward(); }
    //
    iterator(const stream_t& file,const string_t& line,status st):
      file_(file),
      line_(line),
      num_(0),
      st_(st)
      //{ std::getline(file_,line_); st_=(file_)?status::readable:status::eof; }
    { }
    //
    void forward()
    {
      if( file_ ){
        std::getline(file_,line_);
        ++num_;
        st_=(file_)?status::good:status::eof;
      }
      else if( st_==status::eof ){
        st_=status::end;
      }
    }
    //
    const string_t& operator* ()const{ return  line_; }
    string_t* const operator->()const{ return &line_; }
    //
    iterator& operator++(){ forward(); return *this; }
    //iterator  operator++(int){ iterator i(*this); ++(*this); return i; }
    iterator& operator++(int){ forward(); return *this; }
    //
    bool operator!=(const iterator& i)const{ return st_ != i.st_; }
    bool operator==(const iterator& i)const{ return st_ == i.st_; }
  };

  iterator begin()
  { return iterator(file_,line_); }

  const iterator end()
  { return iterator(file_,line_,status::end); }

  // getter
  const string_t& get_line()const{ return line_; }

  // stream strait
  bool eof()const{ return static_cast<bool>(file_.eof()); }

};

using file_reader = basic_file_reader<std::basic_ifstream>;

}

#endif
