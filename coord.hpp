/*|===================================== *|  Copyright (c) 2011-2014 hightoro
 *|  All rights reserved
 *|=====================================
 */

#ifndef CLASS_T_COORD_H
#define CLASS_T_COORD_H

#include <sstream>
#include <type_traits>
#include <utility>

/*+--------------------------------+*
 *|                                |*
 *|  File : coord.hpp              |*
 *|                                |*
 *|  Data : 04/01/2012             |*
 *|  TYPE : Class Header           |*
 *|  Base : (Nothing)              |*
 *|                                |*
 *+--------------------------------+*/

namespace pporig{

// Forward declarations(class)
template <class T> class basic_coord;

// Forward declarations(friend function)
template <typename T>
constexpr basic_coord<T> operator+ (const basic_coord<T>&, const basic_coord<T>&);
template <typename T>
constexpr basic_coord<T> operator- (const basic_coord<T>&, const basic_coord<T>&);
template <typename T>
constexpr basic_coord<T> operator* (const basic_coord<T>&, const T&);
template <typename T>
constexpr basic_coord<T> operator* (const T&, const basic_coord<T>&);
template <typename T>
constexpr basic_coord<T> operator/ (const basic_coord<T>&, const T&);
//
template <typename T>
constexpr basic_coord<T> operator+ (const basic_coord<T>&);
template <typename T>
constexpr basic_coord<T> operator- (const basic_coord<T>&);
//
template <typename T>
constexpr T comp (const basic_coord<T>&, const basic_coord<T>&);
template <typename T>
constexpr bool operator<  (const basic_coord<T>&, const basic_coord<T>&);
template <typename T>
constexpr bool operator>  (const basic_coord<T>&, const basic_coord<T>&);
template <typename T>
constexpr bool operator<= (const basic_coord<T>&, const basic_coord<T>&);
template <typename T>
constexpr bool operator>= (const basic_coord<T>&, const basic_coord<T>&);
template <typename T>
constexpr bool operator== (const basic_coord<T>&, const basic_coord<T>&);
template <typename T>
constexpr bool operator!= (const basic_coord<T>&, const basic_coord<T>&);
//
template <typename T,typename charT,typename traits>
std::basic_ostream<charT,traits>& operator<< (std::basic_ostream<charT,traits>&, const basic_coord<T>&);

// 五次元まで
template <class T>
class basic_coord
{
private:
  unsigned short dim;

public:
  T const x, y, z, w, v;  // read-only menber

  /* ------------------------ *
   *|  Construct & Destruct  |*
   * ------------------------ */
  constexpr basic_coord():                  // Construct (Default)
    dim(2),x(0),y(0),z(0),w(0),v(0){}

  constexpr basic_coord(T x_,T y_):
    dim(2),x(x_),y(y_),z(0),w(0),v(0){}     // 2

  constexpr basic_coord(T x_,T y_,T z_):
    dim(3),x(x_),y(y_),z(z_),w(0),v(0){}    // 3

  constexpr basic_coord(T x_,T y_,T z_,T w_):
    dim(4),x(x_),y(y_),z(z_),w(w_),v(0){}   // 4

  constexpr basic_coord(T x_,T y_,T z_,T w_,T v_):
    dim(5),x(x_),y(y_),z(z_),w(w_),v(v_){}  // 5

  ~basic_coord()=default;                   // Destruct

  /* ------------------ *
   *|  Copy Construct  |*
   * ------------------ */
  basic_coord( const basic_coord<T>& )=default;            // Copy Construct 1
  basic_coord& operator=( const basic_coord<T>& )=default; // Copy Construct 2

  /* ------------------ *
   *|  Move Construct  |*
   * ------------------ */
  basic_coord( basic_coord<T>&& )=default;              // Move Construct 1
  basic_coord& operator=( basic_coord<T>&& )=default;   // Move Construct 2

  /* ------- *
   *|  put  |*
   * ------- */
  // nothing //

  /* ------- *
   *|  get  |*
   * ------- */
  // nothing //

  /* ---------------------- *
   *|  operator(compound)  |*
   * ---------------------- */
  basic_coord<T>& operator+= ( const basic_coord<T>& obj )
  {
    const_cast<T&>(x)+= obj.x;
    const_cast<T&>(y)+= obj.y;
    const_cast<T&>(z)+= obj.z;
    const_cast<T&>(w)+= obj.w;
    const_cast<T&>(v)+= obj.v;
    return *this;
  }
  basic_coord<T>& operator-= ( const basic_coord<T>& obj )
  {
    const_cast<T&>(x)-= obj.x;
    const_cast<T&>(y)-= obj.y;
    const_cast<T&>(z)-= obj.z;
    const_cast<T&>(w)-= obj.w;
    const_cast<T&>(v)-= obj.v;
    return *this;
  }
  //basic_coord<T>& operator *= ( const basic_coord<T>& );
  basic_coord<T>& operator*= ( const T& val )
  {
    const_cast<T&>(x)*= val;
    const_cast<T&>(y)*= val;
    const_cast<T&>(z)*= val;
    const_cast<T&>(w)*= val;
    const_cast<T&>(v)*= val;
    return *this;
  }
  //basic_coord<T>& operator /= ( const basic_coord<T>& );
  basic_coord<T>& operator/= ( const T& val)
  {
    const_cast<T&>(x)/= val;
    const_cast<T&>(y)/= val;
    const_cast<T&>(z)/= val;
    const_cast<T&>(w)/= val;
    const_cast<T&>(v)/= val;
    return *this;
  }

  /* -------------------- *
   *|  operator(binary)  |*
   * -------------------- */
  friend /*constexpr*/ basic_coord<T> operator+<> (const basic_coord<T>&, const basic_coord<T>&);
  friend /*constexpr*/ basic_coord<T> operator-<T> (const basic_coord<T>&, const basic_coord<T>&);
  friend /*constexpr*/ basic_coord<T> operator*<T> (const basic_coord<T>&, const T&);
  friend /*constexpr*/ basic_coord<T> operator*<T> (const T&, const basic_coord<T>&);
  friend /*constexpr*/ basic_coord<T> operator/<T> (const basic_coord<T>&, const T&);
  /* ------------------- *
   *|  operator(unary)  |*
   * ------------------- */
  friend /*constexpr*/ basic_coord<T> operator+<T> (const basic_coord<T>&);
  friend /*constexpr*/ basic_coord<T> operator-<T> (const basic_coord<T>&);
  /* --------------------- *
   *|  operator(compare)  |*
   * --------------------- */
  friend /*constexpr*/ T comp <T>(const basic_coord<T>&, const basic_coord<T>&);
  friend /*constexpr*/ bool operator< <T> (const basic_coord<T>&, const basic_coord<T>&);
  friend /*constexpr*/ bool operator> <T> (const basic_coord<T>&, const basic_coord<T>&);
  friend /*constexpr*/ bool operator<=<T> (const basic_coord<T>&, const basic_coord<T>&);
  friend /*constexpr*/ bool operator>=<T> (const basic_coord<T>&, const basic_coord<T>&);
  friend /*constexpr*/ bool operator==<T> (const basic_coord<T>&, const basic_coord<T>&);
  friend /*constexpr*/ bool operator!=<T> (const basic_coord<T>&, const basic_coord<T>&);
/* -------------------- *
 *|  operator(stream)  |*
 * -------------------- */
  template<typename U,typename charT,typename traits>
  friend std::basic_ostream<charT,traits>& operator<< (std::basic_ostream<charT,traits>&, const basic_coord<U>&);
  //
private:
  constexpr basic_coord(T x_,T y_,T z_,T w_,T v_,unsigned short d):
    dim(d),x(x_),y(y_),z(z_),w(w_),v(v_){}  // call from friend function
};
/* -------------------- *
 *|  operator(binary)  |*
 * -------------------- */
template<typename T>
constexpr basic_coord<T> operator+ ( const basic_coord<T>& lhs, const basic_coord<T>& rhs )
{ return basic_coord<T>(lhs.x+rhs.x,lhs.y+rhs.y,lhs.z+rhs.z,lhs.w+rhs.w,lhs.v+rhs.v,lhs.dim); }
template<typename T>
constexpr basic_coord<T> operator- ( const basic_coord<T>& lhs, const basic_coord<T>& rhs )
{ return basic_coord<T>(lhs.x-rhs.x,lhs.y-rhs.y,lhs.z-rhs.z,lhs.w-rhs.w,lhs.v-rhs.v,lhs.dim); }
template<typename T>
constexpr basic_coord<T> operator* ( const basic_coord<T>& lhs, const T& rhs )
{ return basic_coord<T>(lhs.x*rhs,lhs.y*rhs,lhs.z*rhs,lhs.w*rhs,lhs.v*rhs,lhs.dim); }
template<typename T>
constexpr basic_coord<T> operator* ( const T& lhs, const basic_coord<T>& rhs )
{ return basic_coord<T>(lhs*rhs.x,lhs*rhs.y,lhs*rhs.z,lhs*rhs.w,lhs*rhs.v,rhs.dim); }
template<typename T>
constexpr basic_coord<T> operator/ ( const basic_coord<T>& lhs, const T& rhs )
{ return basic_coord<T>(lhs.x/rhs,lhs.y/rhs,lhs.z/rhs,lhs.w/rhs,lhs.v/rhs,lhs.dim); }
/* ------------------- *
 *|  operator(unary)  |*
 * ------------------- */
template<typename T>
constexpr basic_coord<T> operator+ ( const basic_coord<T>& rhs )
{ return rhs; }
template<typename T>
constexpr basic_coord<T> operator- ( const basic_coord<T>& rhs )
{ return basic_coord<T>(-rhs.x,-rhs.y,-rhs.z,-rhs.w,-rhs.v,rhs.dim); }
/* --------------------- *
 *|  operator(compare)  |*
 * --------------------- */
template<typename T>
constexpr T comp( const basic_coord<T>& lhs, const basic_coord<T>& rhs )
{
  return
    (lhs.v!=rhs.v) ? (lhs.v-rhs.v) :
    (lhs.w!=rhs.w) ? (lhs.w-rhs.w) :
    (lhs.z!=rhs.z) ? (lhs.z-rhs.z) :
    (lhs.y!=rhs.y) ? (lhs.y-rhs.y) :
                     (lhs.x-rhs.x) ;
}
template<typename T>
constexpr bool operator <  ( const basic_coord<T>& lhs, const basic_coord<T>& rhs  )
{ return ( comp(lhs,rhs) <  0 ); }
template<typename T>
constexpr bool operator >  ( const basic_coord<T>& lhs, const basic_coord<T>& rhs  )
{ return ( comp(lhs,rhs) >  0 ); }
template<typename T>
constexpr bool operator <= ( const basic_coord<T>& lhs, const basic_coord<T>& rhs  )
{ return ( comp(lhs,rhs) <= 0 ); }
template<typename T>
constexpr bool operator >= ( const basic_coord<T>& lhs, const basic_coord<T>& rhs  )
{ return ( comp(lhs,rhs) >= 0 ); }
template<typename T>
constexpr bool operator == ( const basic_coord<T>& lhs, const basic_coord<T>& rhs  )
{ return ( comp(lhs,rhs) == 0 ); }
template<typename T>
constexpr bool operator != ( const basic_coord<T>& lhs, const basic_coord<T>& rhs  )
{ return ( comp(lhs,rhs) != 0 ); }

/* -------------------- *
 *|  operator(stream)  |*
 * -------------------- */
//istream& operator >> <>( istream&, Basic_Coord<T>& );
template<typename T, typename charT, typename traits>
std::basic_ostream<charT,traits>& operator<< (std::basic_ostream<charT,traits>& ostr, const basic_coord<T>& rhs)
{
  std::basic_ostringstream<charT,traits> str;
  str << "(";
  if( rhs.dim >= 1 )        str <<        rhs.x;
  if( rhs.dim >= 2 )   str << "," << rhs.y;
  if( rhs.dim >= 3 )   str << "," << rhs.z;
  if( rhs.dim >= 4 )   str << "," << rhs.v;
  if( rhs.dim >= 5 )   str << "," << rhs.w;
  str << ")";
  return ostr << str.str();
}

/* -------------------- *
 *|  operator(global)  |*
 * -------------------- */
using coord =basic_coord<int>;
using coord =basic_coord<int>; // test
using fcoord=basic_coord<float>;
using dcoord=basic_coord<double>;
using scoord=basic_coord<short>;
using lcoord=basic_coord<long>;

}

#endif //CLASS_T_COORD_H
