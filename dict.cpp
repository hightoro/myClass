/*+--------------------------------+*
 *|                                |*
 *|  File : dict.cpp               |*
 *|                                |*
 *|  Data : 17/09/2012             |*
 *|  Type : Member Function        |*
 *|  Base : Arch                   |*
 *|                                |*
 *+--------------------------------+*/

/* ---------------- *
 *|  copy & clear  |*
 * ---------------- */
template <class T>
void dict<T>::copy( const dict<T>& cp )
{
  /* This */
  key_list  = cp.key_list;
  value_map = cp.value_map; 
}
template <class T>
void dict<T>::clear( )
{

}

/* ------- *
 *|  put  |*
 * ------- */
template <class T>
void dict<T>::push_back( const string& name )
{
  key_list.push_back(name);
  value_map.insert( make_pair(name,T(name)) );
}
template <class T>
void dict<T>::push_back( const string& name, const T& type )
{
  key_list.push_back(name);
  value_map.insert( make_pair(name,type) );
}

/* --------- *
 *| emplace |*
 * --------- */
/*
template <class T>
template <class... Args>
void dict<T>::emplace_back( const Args&... args)
{
    T value( args... );
    key_list.push_back( key );
    value_map.emplace( key,args... )
}
*/

/* --------- *
 *|  erase  |*
 * --------- */
template <class T>
void dict<T>::erase( const string& name )
{
  boost::remove_erase( key_list,name );
  value_map.erase( name );
}

/* ------------ *
 *|  return T  |*
 * ------------ */
template <class T>
T& dict<T>::front( )
{
  return value_map.at(key_list.front());
}
template <class T>
T& dict<T>::back( )
{
  return value_map.at(key_list.back());
}
template <class T>
T& dict<T>::operator[]( const string& key )
{
  return value_map.at(key);
}
template <class T>
T& dict<T>::at( const string& key )
{
  return value_map.at(key);
}

/* ------------------ *
 *|  return const T  |*
 * ------------------ */
template <class T>
const T& dict<T>::front( ) const 
{
  return value_map.at(key_list.front());
}
template <class T>
const T& dict<T>::back( ) const 
{
  return value_map.at(key_list.back());
}
template <class T>
const T& dict<T>::operator[]( const string& key ) const
{
  return value_map.at(key);
}
template <class T>
const T& dict<T>::at( const string& key ) const
{
  return value_map.at(key);
}

/* --------- *
 *|  basic  |*
 * --------- */
template <class T>
bool dict<T>::empty( ) const
{
  return key_list.empty();
}
template <class T>
unsigned int dict<T>::size( ) const
{
  return key_list.size();
}
template <class T>
unsigned int dict<T>::count( const string& key ) const
{
  return value_map.count(key);
}
template <class T>
bool dict<T>::exist( const string& key ) const
{
  return ( value_map.find(key)!=value_map.end() );
}

/* ------------ *
 *|  iterator  |*
 * ------------ */
template <class T>
typename dict<T>::iterator dict<T>::begin( )
{
  return iterator( key_list.begin(),value_map );
}
template <class T>
typename dict<T>::iterator dict<T>::end( )
{
  return iterator( key_list.end(),value_map );
}
template <class T>
typename dict<T>::iterator dict<T>::find( const string& key )
{
  iterator pos( find(key_list.begin(),key_list.end(),key ),value_map );
  return pos;
}

/* ------------------ *
 *|  const_iterator  |*
 * ------------------ */
template <class T>
typename dict<T>::const_iterator dict<T>::begin( )const
{
  return const_iterator( key_list.begin(),value_map  );
}
template <class T>
typename dict<T>::const_iterator dict<T>::end( )const
{
  return const_iterator( key_list.end(),value_map  );
}









