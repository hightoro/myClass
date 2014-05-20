/*|=====================================
 *|  Copyright (c) 2011-2014 hightoro
 *|  All rights reserved
 *|=====================================
 */
#ifndef CLASS_VERILOG_GATE_PARSER_H
#define CLASS_VERILOG_GATE_PARSER_H

#include <iostream>
#include <fstream>
#include <string>
#include <regex>

#include <boost/xpressive/xpressive.hpp>
#include <boost/algorithm/string.hpp>

#include "../pporig/tags.hpp"
#include "../pporig/regex.hpp"

namespace pporig{

template<typename Derived>
class verilog_gate_parser
{
protected:
  verilog_gate_parser()=default;
  ~verilog_gate_parser()=default;
  verilog_gate_parser(const verilog_gate_parser&)=delete;
  verilog_gate_parser(verilog_gate_parser&&)=delete;
  verilog_gate_parser& operator=(const verilog_gate_parser&)=delete;
  verilog_gate_parser& operator=(verilog_gate_parser&&)=delete;

public:
  //void put_name(string)
  //void put_bus(string,string)
  //void put_bus(string,int,int,string)
  //void put_func(string,string)
  //void put_func_wire(string,string,string)

  /* --------- *
   *|  parse  |*
   * --------- */
  void parse_bus( const std::string& line )
  {
    boost::xpressive::smatch what,what2;
    boost::xpressive::regex_match
      ( line,
        what,
        boost::xpressive::sregex::compile(R"(^\s*()\s+(:?\[\s*([0-9]+)\s*:\s*([0-9]+)\s\]\s+)?\((.*)\)/s*$)") );

    // no bus size
    if( what.str(2).empty() ){
      auto r  =boost::xpressive::sregex::compile(R"(\w+)");
      auto itr=boost::xpressive::sregex_iterator(what.str(4).begin(),what.str(4).end(),r );
      auto eos=boost::xpressive::sregex_iterator();
      for(;itr!=eos;itr++){
        static_cast<Derived*>(this)->put_bus( what[1],stoi(what[2]),stoi(what[3]),(*itr).str() );
      }
    }
    else{
      auto r  =boost::xpressive::sregex::compile(R"(^\s*() \[\\s*([0-9])+\\s*:\\s*[0-9]+\\s*\\]$)");
      auto itr=boost::xpressive::sregex_iterator(what.str(4).begin(),what.str(4).end(),r );
      auto eos=boost::xpressive::sregex_iterator();
      for(;itr!=eos;itr++){
        static_cast<Derived*>(this)->put_bus( what[1],(*itr).str() );
      }
    }
  }
  void parse_func( const std::string& line )
  {
    boost::xpressive::smatch what;
    auto r=boost::xpressive::sregex::compile(R"(^\s*(\w+)\s+(\w+)\s*\((.+)\);\s*$)");
    boost::xpressive::regex_match(line,what,r);

    static_cast<Derived*>(this)->put_func( what[1],what[2] );

    auto r2 =boost::xpressive::sregex::compile(R"(.(\w+)\s*\(\s*(\w+)\s*\))");
    auto itr=boost::xpressive::sregex_iterator( what.str(3).begin(),what.str(3).end(),r2 );
    auto eos=boost::xpressive::sregex_iterator();
    for(; itr!=eos;itr++){
      static_cast<Derived*>(this)->put_bus(what[1],itr->str(1),itr->str(2) );
    }
  }
  void parse_verilog( const std::string& line )
  {
    boost::xpressive::smatch what;

    // case module
    if( boost::xpressive::regex_match(line,what,boost::xpressive::sregex::compile("^\\s*module\\s+([^\\s]+)\\s.*$")) ){
      static_cast<Derived*>(this)->put_name( what[1] );
    }

    // case bus(wire|input|output|inout)
    else if( boost::xpressive::regex_search(line,boost::xpressive::sregex::compile("input|output|inout|wire")) ){
      parse_bus( line );
    }

    // case func(gate|submodule)
    else{
      parse_func( line );
    }
  }

  /* -------- *
   *|  Read  |*
   * -------- */
  void read_verilog( const std::string& name )
  {
    // file open
    std::ifstream file(name);
    if( !file.is_open() ){
      std::cerr << tags::ERROR << "file_name(" << name << ") : ファイルがありません" << std::endl;
      throw std::logic_error("Not Found File");
    }

    // get line
    unsigned int num=0;      // line number
    std::string  line;       // line string
    bool         flag=false; // parsing flag

    while( std::getline(file,line) ){

      // line number increment
      num++;
      //std::clog << num << " : " << line << std::endl; // debug

      // skip
      if( line.length()<2 ) continue;  // at space only

      // check new line  &  concatenate lines
      if( line.find("endmodule")==std::string::npos ){ // bad parsing keyword...
        while( line.find( ";" )==std::string::npos ){ // check new line
          num++;
          std::string word;
          getline(file,word);
          line += std::move(word);
        }
      }

      // check "endmodule"
      if( line.find("endmodule")!=std::string::npos ){ // bad parsing keyword...
        flag = false;
      }
      else if( line.find("module")!=std::string::npos ){ // bad parsing keyword...
        flag = true;
      }

      // parsing //
      if( flag ){
        //std::clog << num << " : " << line << std::endl; // debug
        parse_verilog( line );
      }

    }
  }
};

}
#endif
