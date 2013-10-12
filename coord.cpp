/*+--------------------------------+*
 *|                                |*
 *|  File : Coord.cpp              |*
 *|                                |*
 *|  Data : 25/09/2012             |*
 *|  Type : Member Function        |*
 *|  Base : (Nothing)              |*
 *|                                |*
 *+--------------------------------+*/

/* ----------------------- *
 *|  Init & Copy & Clear  |*
 * ----------------------- */
template <class T>
void basic_coord<T>::init( )
{
  x = 0;
  y = 0;
  z = 0;
  w = 0;
  v = 0;
}
template <class T>
void basic_coord<T>::copy( const basic_coord<T>& cp )
{
  dim = cp.dim;
  x = cp.x;
  y = cp.y;
  z = cp.z;
  w = cp.w;
  v = cp.v;
}
template <class T>
void basic_coord<T>::clear( )
{
  x = 0;
  y = 0;
  z = 0;
  w = 0;
  v = 0;
}

/* ------------------ *
 *|  operator(cast)  |*
 * ------------------ */
//basic_coord::operator int( const basic_coord& obj ) const
//basic_coord::operator double( const basic_coord& obj ) const
//basic_coord::operator string( const basic_coord& obj ) const

/* --------------------- *
 *|  operator(compare)  |*
 * --------------------- */
template <class T>
int basic_coord<T>::comp( const basic_coord<T>& obj ) const
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
template <class T>
bool basic_coord<T>::operator<( const basic_coord<T>& obj ) const
{
  return ( (this->comp(obj)) < 0 );
  /*
  if( v < obj.v )
    return true;
  else if( v == obj.v )
    if( w < obj.w )
      return true;
    else if( w == obj.w )
      if( z < obj.z )
	return true;
      else if( z == obj.z )
	if( y < obj.y )
	  return true;
	else if( y == obj.y )
	  if( x < obj.x )
	    return true;
  
  return false;
  */
}
template <class T>
bool basic_coord<T>::operator>( const basic_coord<T>& obj ) const
{
  return ( (this->comp(obj)) > 0 );
  /*
  if( z > obj.z )
    return true;
  else if( z == obj.z )
    if( y > obj.y )
      return true;
    else if( y == obj.y )
      if( x > obj.x )
	return true;

  return false;
  */
}
template <class T>
bool basic_coord<T>::operator<=( const basic_coord<T>& obj ) const
{
  return ( (this->comp(obj)) <= 0 );
  /*
  if( z <= obj.z )
    return true;
  else if( z == obj.z )
    if( y <= obj.y )
      return true;
    else if( y == obj.y )
      if( x <= obj.x )
	return true;

  return false;
  */
}
template <class T>
bool basic_coord<T>::operator>=( const basic_coord<T>& obj ) const
{
  return ( (this->comp(obj)) >= 0 );
  /*
  if( z >= obj.z )
    return true;
  else if( z == obj.z )
    if( y >= obj.y )
      return true;
    else if( y == obj.y )
      if( x >= obj.x )
	return true;

  return false;
  */
}
template <class T>
bool basic_coord<T>::operator==( const basic_coord<T>& obj ) const
{
  return ( (this->comp(obj)) == 0 );
  /*
  if( z == obj.z )
    if( y == obj.y )
      if( x == obj.x )
	return true;

  return false;
  */
}
template <class T>
bool basic_coord<T>::operator!=( const basic_coord<T>& obj ) const
{
  return !( *this == obj );
}

/* ----------------------- *
 *|  operator(increment)  |*
 * ----------------------- */
/*
template <class T>
basic_coord<T>& basic_coord<T>::operator ++ (  )
{
  if(dimension>0)
    ++x;
  if(dimension>1)
    ++y;
  if(dimension>2)
    ++z;
  return *this;
}
template <class T>
basic_coord<T> basic_coord<T>::operator ++ ( int )
{
  basic_coord<T> tmp = *this;
  ++(*this);
  return tmp;
}
template <class T>
basic_coord<T>& basic_coord<T>::operator -- (  )
{
  if(dimension>0)
    --x;
  if(dimension>1)
    --y;
  if(dimension>2)
    --z;
  return *this;
}
template <class T>
basic_coord<T> basic_coord<T>::operator -- ( int )
{
  basic_coord<T> tmp = *this;
  --(*this);
  return tmp;
}
*/
/* --------------------- *
 *|  operator(monadic)  |*
 * --------------------- */
template <class T>
basic_coord<T>& basic_coord<T>::operator += ( const basic_coord<T>& obj )
{
  x += obj.x;
  y += obj.y;
  z += obj.z;
  return (*this);
}
template <class T>
basic_coord<T>& basic_coord<T>::operator -= ( const basic_coord<T>& obj )
{
  x -= obj.x;
  y -= obj.y;
  z -= obj.z;
  return (*this);
}
template <class T>
basic_coord<T>& basic_coord<T>::operator *= ( const basic_coord<T>& obj )
{
  x *= obj.x;
  y *= obj.y;
  z *= obj.z;
  return (*this);
}
template <class T>
basic_coord<T>& basic_coord<T>::operator /= ( const basic_coord<T>& obj )
{
  x /= obj.x;
  y /= obj.y;
  z /= obj.z;
  return (*this);
}

/* -------------------- *
 *|  operator(binary)  |*
 * -------------------- */
template <class T>
const basic_coord<T> basic_coord<T>::operator + ( const basic_coord<T>& obj ) const
{
  basic_coord<T> tmp = *this;
  tmp += obj;
  return tmp;
}
template <class T>
const basic_coord<T> basic_coord<T>::operator - ( const basic_coord<T>& obj )const
{
  basic_coord<T> tmp = *this;
  tmp -= obj;
  return tmp;
}
template <class T>
const basic_coord<T> basic_coord<T>::operator * ( const basic_coord<T>& obj )const
{
  basic_coord<T> tmp = *this;
  tmp *= obj;
  return tmp;
}
template <class T>
const basic_coord<T> basic_coord<T>::operator / ( const basic_coord<T>& obj )const
{
  basic_coord<T> tmp = *this;
  tmp /= obj;
  return tmp;
}

/* -------------------- *
 *|  operator(global)  |*
 * -------------------- */
/*
template <class T>
inline ostream& operator << ( ostream& out, const basic_coord<T>& obj )
{
  if( obj.dimension == 1 )
    out << boost::format("(%d)")%obj.x;
  else if( obj.dimension == 2 )
    out << boost::format("(%d,%d)")%obj.x %obj.y;
  else if( obj.dimension == 3 )
    out << boost::format("(%d,%d,%d)")%obj.x %obj.y %obj.z;
  return out;   
}
*/

