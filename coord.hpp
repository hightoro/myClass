#ifndef CLASS_T_COORD_H
#define CLASS_T_COORD_H
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
  basic_coord():                                  // Construct (Default)
    dim(2),x(0),y(0){}
  basic_coord(T x_,T y_):
    dim(2),x(x_),y(y_){}                    // 2
  basic_coord(T x_,T y_,T z_):
    dim(3),x(x_),y(y_),z(z_){}              // 3
  basic_coord(T x_,T y_,T z_,T w_):
    dim(4),x(x_),y(y_),z(z_),w(w_){}        // 4
  basic_coord(T x_,T y_,T z_,T w_,T v_):
    dim(5),x(x_),y(y_),z(z_),w(w_),v(v_){}  // 5
  virtual ~basic_coord()=default;                 // Destruct

  /* ------------------ *
   *|  Copy Construct  |*
   * ------------------ */
  basic_coord( const basic_coord<T>& )=default;        // Copy Construct 1
  basic_coord& operator=( const basic_coord<T>& )=default;   // Copy Construct 2

  /* ----------------------- *
   *|  Init & Copy & Clear  |*
   * ----------------------- */
  void init( );
  void copy( const basic_coord<T>& );
  void clear( );

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
  int  comp( const basic_coord<T>& )const;
  bool operator <  ( const basic_coord<T>& )const;
  bool operator >  ( const basic_coord<T>& )const;
  bool operator <= ( const basic_coord<T>& )const;
  bool operator >= ( const basic_coord<T>& )const;
  bool operator == ( const basic_coord<T>& )const;
  bool operator != ( const basic_coord<T>& )const;

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
  basic_coord<T>& operator *= ( const basic_coord<T>& );
  basic_coord<T>& operator /= ( const basic_coord<T>& );

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
  friend ostream& operator << ( ostream& out, const basic_coord<T>& obj )
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
