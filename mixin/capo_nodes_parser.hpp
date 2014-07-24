#ifndef CLASS_CAPO_NODE_PARSER_H
#define CLASS_CAPO_NODE_PARSER_H

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
class capo_node_parser : public Derived
{
public:
  //void put_node_pos()=0;

  ///////////
  // parse //
  void parse_nodes(const std::string& line)
  {
    if( line.find("UCLA nodes 1.0")!=std::string::npos )
      return;
    if( boost::xpressive::regex_search(line,boost::xpressive::sregex::compile(R"(^\s*#)")) )
      return;

    boost::xpressive::smatch what;
    if( boost::xpressive::regex_match(line,what,boost::xpressive::sregex::compile(R"(^\s*(\w+)\s+([\d+)\s+(\d+)\s+terminal\s*$)")) )
      static_cast<Derived*>(this)->put_node_size(what[1],std::stoi(what[2]),std::stoi(what[3]),true);
    else if( boost::xpressive::regex_match(line,what,boost::xpressive::sregex::compile(R"(^\s*(\w+)\s+([\d+)\s+(\d+)\s*$)")) )
      static_cast<Derived*>(this)->put_node_size(what[1],std::stoi(what[2]),std::stoi(what[3]),false);
  }

  //////////
  // read //
  void read_nodes(const std::string& name)
  {
    pporig::ifstring file(name);

    while( file.getline_ew(),file.eof() ){
      parse_nodes( file.get_line() );
    }
    // infomation
    std::cout << pporig::tags::INFO <<  "Read Nodes size file [" << f_name << "] OK!" << std::endl;
  }

};

#endif
