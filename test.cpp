/*|=====================================
 *|  Copyright (c) 2011-2014 hightoro
 *|  All rights reserved
 *|=====================================
 */

#include <iostream>
#include <string>

#include "dict.hpp"
#include "coord.hpp"

struct TestClass
{
  std::string name_;
  TestClass(const std::string s):name_(s){}
  const std::string& get_name()const{return name_;}
};

int main()
{
  // dict.hpp //
  dict<TestClass> dict_a;

  std::cout << "----- TEST1 ------" << std::endl;
  dict_a.push_back("name");
  auto& tc_a = dict_a.at("name");
  std::cout << tc_a.get_name() << std::endl;

  std::cout << "----- TEST2 ------" << std::endl;
  dict_a.push_back("a");
  dict_a.push_back("b");
  dict_a.push_back("c");
  for( auto& n : dict_a ){ std::cout << n.get_name() << " ";} std::cout << std::endl;

  std::cout << "----- coord.hpp ------" << std::endl;
  // coord.hpp //
  constexpr auto coord_a = coord(1,2,3);

  std::cout << "----- TEST1 ------[copy constructor]" << std::endl;
  constexpr coord coord_b(coord_a);
  std::cout << coord_b << std::endl;

  std::cout << "----- TEST2 ------[operator=(const&)]" << std::endl;
  constexpr auto coord_c = coord_a;
  std::cout << coord_c << std::endl;

  std::cout << "----- TEST3 ------[move constructor]" << std::endl;
  constexpr coord coord_d(coord(1,2,3));
  std::cout << coord_d << std::endl;

  std::cout << "----- TEST4 ------[operator=(&&)]" << std::endl;
  /*constexpr*/ auto coord_e = std::move(coord_a);
  std::cout << coord_e << std::endl;

  std::cout << "----- TEST5 ------[operator+]" << std::endl;
  constexpr auto coord_f = coord_d + coord(1,1,1,1,1);
  std::cout << coord_f << std::endl;

}

