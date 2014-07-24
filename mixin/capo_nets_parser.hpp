#ifndef CLASS_CAPO_NETS_PARSER_H
#define CLASS_CAPO_NETS_PARSER_H

#include <iostream>
#include <fstream>
#include <string>

#include <boost/xpressive/xpressive.hpp>

#include "../pporig/tags.hpp"
#include "../pporig/file.hpp"

//////////////
//  Parser  //
//////////////

template<typename Derived>
class capo_nets_parser// : public Derived
{
protected:
  capo_nets_parser()=default;
  ~capo_nets_parser()=default;
  capo_nets_parser(const capo_nets_parser&)=delete;
  capo_nets_parser(capo_nets_parser&&)=delete;
  capo_nets_parser& operator=(const capo_nets_parser&)=delete;
  capo_nets_parser& operator=(capo_nets_parser&&)=delete;

public:
  //void put_node_pos()=0;

  // read /
  void parse_nets(const std::string& line,std::string& name)
  {
    if( line.find("UCLA nets 1.0")!=std::string::npos )
      return;
    if( boost::xpressive::regex_search(line,boost::xpressive::sregex::compile(R"(^\s*#)")) )
      return;

    boost::xpressive::smatch what;
    if( boost::xpressive::regex_match(line,what,boost::xpressive::sregex::compile(R"(^NetDegree\s+:\s+(\d+)\s+(\w+)\s*$)")) ){
      name = what[2];
      static_cast<Derived*>(this)->put_conn_name(name);
    }
    if( boost::xpressive::regex_match(line,what,boost::xpressive::sregex::compile(R"(^\s*(\w+)\s+([IO])\s+:\s+(\d+)\s+(\d)\s*$)")) ){
      static_cast<Derived*>(this)->put_conn_node(name,what[1]);
    }
  }

  //////////
  // read //
  void read_nets(const std::string& name)
  {
    pporig::ifstring file(name);
    std::string n_name;

    while( file.getline_ew() ){
      parse_nets( file.get_line(),n_name );
    }
    // infomation
    std::cout << pporig::tags::INFO <<  "Read connection file [" << name << "] OK!" << std::endl;
  }

};

#endif
