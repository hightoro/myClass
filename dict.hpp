/*|=====================================
 *|  Copyright (c) 2011-2014 hightoro
 *|  All rights reserved
 *|=====================================
 */

#ifndef CLASS_T_DICT_H
#define CLASS_T_DICT_H

#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <type_traits>

template <typename T>
class dict
{
protected:

  std::vector<std::string>   key_list_;  // key
  std::map<std::string,T>    value_map_; // value

  using key_type   = std::string;
  using value_type = T;
  using size_type  = std::size_t;

  using k_list_t   = std::vector<std::string>;
  using v_map_t    = std::map<std::string,T>;

public:
  /* ------------------------ *
   *|  Construct & Destruct  |*
   * ------------------------ */
  dict( )=default;
  virtual ~dict( )=default;

  /* ------------------ *
   *|  Copy Construct  |*
   * ------------------ */
  dict( const dict<T>& )=default;
  dict& operator=( const dict<T>& )=default;

  /* ------------------ *
   *|  Move Construct  |*
   * ------------------ */
  dict( dict<T>&& )=default;
  dict& operator=( dict<T>&& )=default;

  /* ------------- *
   *|  Iterators  |*
   * ------------- */
  class iterator : public std::iterator<std::bidirectional_iterator_tag, value_type>
  {
  private:
    k_list_t::iterator   itr_;
    v_map_t&             val_;

  public:
    iterator( )=delete;  // default constructor (delete)
    ~iterator()=default; // destructor
    iterator(const k_list_t::iterator& i,v_map_t& v):itr_(i),val_(v){}
    iterator(const iterator& i):itr_(i.itr_),val_(i.val_){}

    value_type& operator*(){ return ( val_.at(*itr_) ); }

    iterator& operator++(){ ++itr_; return *this; }
    iterator  operator++(int){ iterator i(*this); ++(*this); return i; }
    iterator& operator--(){ --itr_; return *this; }
    iterator  operator--(int){ iterator i(*this); --(*this); return i; }

    bool operator!=(const iterator& i)const{ return (itr_ != i.itr_); }
    bool operator==(const iterator& i)const{ return (itr_ == i.itr_); }
  };

  iterator begin( )
  {
    return iterator( key_list_.begin(),value_map_ );
  }

  iterator end( )
  {
    return iterator( key_list_.end(),value_map_ );
  }


  /* ------------------ *
   *|  Const Iterator  |*
   * ------------------ */
  class const_iterator : public std::iterator<std::bidirectional_iterator_tag, value_type const>
  {
  private:
    k_list_t::const_iterator itr_;
    const v_map_t&           val_;

  public:
    const_iterator( )=delete;
    ~const_iterator()=default;
    const_iterator( const k_list_t::const_iterator& i, const v_map_t& v ):itr_(i),val_(v){}
    const_iterator( const const_iterator& i ):itr_(i.itr_),val_(i.val_){}

    const value_type& operator*()const{ return ( val_.at(*itr_) ); }

    const_iterator& operator++(){ ++itr_; return *this; }
    const_iterator  operator++(int){ const_iterator i(*this); ++(*this); return i; }
    const_iterator& operator--(){ --itr_; return *this; }
    const_iterator  operator--(int){ const_iterator i(*this); --(*this); return i; }

    bool operator!=( const const_iterator& i )const{ return (itr_ != i.itr_); }
    bool operator==( const const_iterator& i )const{ return (itr_ == i.itr_); }
  };

  const_iterator begin( )const
  {
    return const_iterator( key_list_.begin(),value_map_  );
  }
  const_iterator end( )const
  {
    return const_iterator( key_list_.end(),value_map_  );
  }

  /* ------------------ *
   *|  Element access  |*
   * ------------------ */
  // front
  value_type& front( )
  {
    return value_map_.at(key_list_.front());
  }
  const value_type& front( ) const
  {
    return value_map_.at(key_list_.front());
  }

  // back
  value_type& back( )
  {
    return value_map_.at(key_list_.back());
  }
  const value_type& back( ) const
  {
    return value_map_.at(key_list_.back());
  }

  // at
  value_type& at( const key_type& key )
  {
    return value_map_.at(key);
  }
  const value_type& at( const key_type& key ) const
  {
    return value_map_.at(key);
  }

  // operator[]
  value_type& operator[]( const key_type& key )
  {
    return value_map_.at(key);
  }
  const value_type& operator[]( const key_type& key ) const
  {
    return value_map_.at(key);
  }

  /* ------------ *
   *|  Capacity  |*
   * ------------ */
  // empty
  bool empty( ) const noexcept
  {
    return key_list_.empty();
  }

  // size
  size_type size( ) const noexcept
  {
    return key_list_.size();
  }

  /* ------------- *
   *|  Modifiers  |*
   * ------------- */
  // clear
  void clear( ) noexcept
  {
    key_list_.clear();
    value_map_.clear();
  }

  // insert



  // emplace



  // push_front
  //void push_front( const string& )
  //void push_front( const string&, T&& );

  // push_back
  template<typename U=void>
  auto push_back( const key_type& name ) -> decltype
    ( typename std::enable_if< std::is_constructible<T,std::string>::value,U>::type(),
      void()
      ){
    key_list_.push_back(name);
    value_map_.emplace( name,T(name) );
  }
  template<typename U=void>
  auto push_back( const key_type& name ) -> decltype
    ( typename std::enable_if<!std::is_constructible<T,std::string>::value,U>::type(),
      void()
      ){
    key_list_.push_back(name);
    value_map_.emplace( name,T() );
  }
  void push_back( const key_type& name, const value_type& value )
  {
    key_list_.push_back(name);
    value_map_.emplace(name,value);
  }
  void push_back( const key_type& name, value_type&& value )
  {
    key_list_.push_back(name);
    value_map_.emplace(name,value);
  }

  // emplace_front



  // emplace_back
  /*
  template <class... Args>
  void emplace_back( const Args&... args )
  {
    T value( args... );
    key_list.push_back( key );
    value_map.emplace( key,args... );
  }
  */

  // erase
  void erase( const key_type& name )
  {
    // boost::remove_erase( key_list_,name );
    key_list_.erase( std::remove(key_list_.begin(),key_list_.end(),name),key_list_.end());
    value_map_.erase( name );
  }

  // pop_front



  // pop_back


  // swap

  /* ------------ *
   *|  property  |*
   * ------------ */
  // exist
  bool exist( const key_type& key )const
  {
    return ( value_map_.find(key)!=value_map_.end() );
  }

  // count
  size_type count( const key_type& key )const
  {
    return value_map_.count();
  }

  // find
  iterator find( const key_type& key )
  {
    return iterator( std::find(key_list_.begin(),key_list_.end(),key),value_map_ );
  }

  const_iterator find( const key_type& key )const
  {
    return const_iterator( std::find(key_list_.begin(),key_list_.end(),key),value_map_ );
  }

};


#endif // CLASS_T_DICT_H

