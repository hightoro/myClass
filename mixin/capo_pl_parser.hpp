#ifndef CLASS_CAPO_PL_PARSER_H
#define CLASS_CAPO_PL_PARSER_H

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
class capo_pl_parser //: public Derived
{
protected:
  capo_pl_parser()=default;
  ~capo_pl_parser()=default;
  capo_pl_parser(const capo_pl_parser&)=delete;
  capo_pl_parser(capo_pl_parser&&)=delete;
  capo_pl_parser& operator=(const capo_pl_parser&)=delete;
  capo_pl_parser& operator=(capo_pl_parser&&)=delete;

public:
  //void put_node_pos()=0;

  // read //
  void parse_pl(const std::string& line)
  {
    //std::cout << line << std::endl; // debug

    if( line.find("UCLA pl 1.0")!=std::string::npos )
      return;
    if( boost::xpressive::regex_match(line,boost::xpressive::sregex::compile(R"(^\s*#.*$)")) )
      return;

    boost::xpressive::smatch what;
    if( boost::xpressive::regex_match(line,what,boost::xpressive::sregex::compile(R"(^\s*(\w+)\s+(\d+)\s+(\d+)\s+:\s+F?[NSWE]\s+/FIXED\s*$)")) )
       static_cast<Derived*>(this)->put_node_pos(what[1],std::stoi(what[2]),std::stoi(what[3]),true,true);
    else if( boost::xpressive::regex_match(line,what,boost::xpressive::sregex::compile(R"(^\s*(\w+)\s+0\s+0\s+:\s+F?[NSWE]\s+/\s*$)")) )
      static_cast<Derived*>(this)->put_node_pos(what[1],0,0,false,false);
    else if( boost::xpressive::regex_match(line,what,boost::xpressive::sregex::compile(R"(^\s*(\w+)\s+(\d+)\s+(\d+)\s+:\s+F?[NSWE]\s+/\s*$)")) )
      static_cast<Derived*>(this)->put_node_pos(what[1],std::stoi(what[2]),std::stoi(what[3]),true,false);
    else
      std::cout << pporig::tags::ERROR << "Cant parse line : [" << line << "]" << std::endl;
  }

  //////////
  // read //
  void read_pl(const std::string& name)
  {
    pporig::ifstring file(name);

    while( file.getline_ew() ){
      parse_pl( file.get_line() );
    }
    // infomation
    std::cout << pporig::tags::INFO <<  "Read Node placement  [" << name << "] OK!" << std::endl;
  }
};

#endif
