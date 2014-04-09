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

template<typename T>
class file_string
{
private:
  std::string                 name_;  // file name
  T                           file_;  // file stream
  std::vector<std::string>    line_;
  unsigned int                num_;   // line num;

  std::string                 end_;
  std::string                 dem_;

public:

  file_string()=delete;
  ~file_string()=default;

  file_string(const file_string&)=delete;
  file_string& operator=(const file_string&)=delete;

  file_string(file_string&&)=default;
  file_string& operator=(const file_string&)=default;

  file_string(const std::string& f):
    name_(f),num_(1)
  { open(file_,f);  }


  // move current line
  const std::string& operator++(){ return *(++itr_); }
  const std::string& operator++(int){ return *(itr_++); }

  // get current line
  const std::string& get_line()const{ return itr++ }
  unsigned int       get_num()const{}

};

using ifstring = file_string<ifstream>

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
  std::cout << console::INFO <<  "Open File [ " << name << " ] OK!" << std::endl;

  return file;
}







#endif
