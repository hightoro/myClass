/*|=====================================
 *|  Copyright (c) 2011-2014 hightoro
 *|  All rights reserved
 *|=====================================
 */

#include <iostream>
#include <string>

#include "dict.hpp"

struct TestClass
{
  std::string name_;
  TestClass(const std::string s):name_(s){}
  const std::string& get_name()const{return name_;}
};

int main()
{
  dict<TestClass> tc_list;

  tc_list.push_back("name");
  auto& a = tc_list.at("name");

  std::cout << a.get_name() << std::endl;

  tc_list.push_back("a");
  tc_list.push_back("b");
  tc_list.push_back("c");

  for( auto& n : tc_list ){ std::cout << n.get_name() << " ";} std::cout << std::endl;
}

