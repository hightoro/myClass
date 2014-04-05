/*|=====================================
 *|  Copyright (c) 2011-2014 hightoro
 *|  All rights reserved
 *|=====================================
 */

#ifndef CLASS_T_COORD_H
#define CLASS_T_COORD_H

#include <vector>
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

//template <class T> class coord;
//template <class T> ostream& operator << ( ostream&, const coord& );

// 五次元まで
template <class T>
class basic_coord
{
private:
  unsigned short dim;

public:
  T x;
  T y;
  T z;
  T w;
  T v;

  /* ------------------------ *
   *|  Construct & Destruct  |*
   * ------------------------ */
  basic_coord():                            // Construct (Default)
    dim(2),x(0),y(0),z(0),w(0),v(0){}

  basic_coord(T x_,T y_):
    dim(2),x(x_),y(y_),z(0),w(0),v(0){}     // 2

  basic_coord(T x_,T y_,T z_):
    dim(3),x(x_),y(y_),z(z_),w(0),v(0){}    // 3

  basic_coord(T x_,T y_,T z_,T w_):
    dim(4),x(x_),y(y_),z(z_),w(w_),v(0){}   // 4

  basic_coord(T x_,T y_,T z_,T w_,T v_):
    dim(5),x(x_),y(y_),z(z_),w(w_),v(v_){}  // 5

  ~basic_coord()=default;                   // Destruct

  /* ------------------ *
   *|  Copy Construct  |*
   * ------------------ */
  basic_coord( const basic_coord<T>& )=default;              // Copy Construct 1
  basic_coord& operator=( const basic_coord<T>& )=default;   // Copy Construct 2

  /* ------------------ *
   *|  Move Construct  |*
   * ------------------ */
  basic_coord( basic_coord<T>&& )=default;              // Move Construct 1
  basic_coord& operator=( basic_coord<T>&& )=default;   // Move Construct 2

  /* ------- *
   *|  put  |*
   * ------- */

  /* ---------------------- *
   *|  get (return value)  |*
   * ---------------------- */

  /* ------------------- *
   *|  at (return ref)  |*
   * ------------------- */

  /* ------------------ *
   *|  operator(cast)  |*
   * ------------------ */


  /* --------------------- *
   *|  operator(compare)  |*
   * --------------------- */
  int  comp( const basic_coord<T>& obj )const
  {
    if( (v-obj.v)!=0 )
      return (v-obj.v);
    else if( (w-obj.w)!=0 )
      return (w-obj.w);
    else if( (z-obj.z)!=0 )
      return (z-obj.z);
    else if( (y-obj.y)!=0 )
      return (y-obj.y);
    else
      return (x-obj.x);
  }
  bool operator <  ( const basic_coord<T>& obj )const
  { return ( (this->comp(obj)) < 0 ); }
  bool operator >  ( const basic_coord<T>& obj )const
  { return ( (this->comp(obj)) > 0 ); }
  bool operator <= ( const basic_coord<T>& obj )const
  { return ( (this->comp(obj)) <= 0 ); }
  bool operator >= ( const basic_coord<T>& obj )const
  { return ( (this->comp(obj)) >= 0 ); }
  bool operator == ( const basic_coord<T>& obj )const
  { return ( (this->comp(obj)) == 0 ); }
  bool operator != ( const basic_coord<T>& obj )const
  { return ( (this->comp(obj)) != 0 ); }

  /* ----------------------- *
   *|  operator(increment)  |*
   * ----------------------- */
  //basic_coord<T>& operator ++ (  );
  //basic_coord<T>  operator ++ ( int );
  //basic_coord<T>& operator -- (  );
  //basic_coord<T>  operator -- ( int );

  /* --------------------- *
   *|  operator(monadic)  |*
   * --------------------- */
  basic_coord<T>& operator += ( const basic_coord<T>& );
  basic_coord<T>& operator -= ( const basic_coord<T>& );
  //basic_coord<T>& operator *= ( const basic_coord<T>& );
  basic_coord<T>& operator *= ( T );
  //basic_coord<T>& operator /= ( const basic_coord<T>& );
  basic_coord<T>& operator /= ( T& );

  /* -------------------- *
   *|  operator(binary)  |*
   * -------------------- */
  const basic_coord<T> operator + ( const basic_coord<T>& )const;
  const basic_coord<T> operator - ( const basic_coord<T>& )const;
  const basic_coord<T> operator * ( const basic_coord<T>& )const;
  const basic_coord<T> operator / ( const basic_coord<T>& )const;

  /* -------------------- *
   *|  operator(global)  |*
   * -------------------- */
  friend std::ostream& operator << ( ostream& out, const basic_coord<T>& obj )
  {
    if( obj.dim == 1 )
      out << boost::format("(%d)")%obj.x;
    else if( obj.dim == 2 )
      out << boost::format("(%d,%d)")%obj.x %obj.y;
    else if( obj.dim == 3 )
      out << boost::format("(%d,%d,%d)")%obj.x %obj.y %obj.z;
    return out; 
  }
  //friend istream& operator >> <>( istream&, Basic_Coord<T>& );
};

using coord =basic_coord<int>;
using dcoord=basic_coord<double>;
using scoord=basic_coord<short>;
using lcoord=basic_coord<long>;

#include "coord.cpp"

#endif //CLASS_T_COORD_H
