#ifndef CLASS_T_DICT_H
#define CLASS_T_DICT_H
/*+--------------------------- *
 *|                           |*
 *|  File : library.hpp       |*
 *|                           |*
 *|  Data : 05/12/2011        |*
 *|  TYPE : Class Header      |*
 *|                           |*
 * --------------------------- */

template <class T>
class dict
{
protected:
  vector<string> key_list;  // key 
  map<string,T>  value_map; // value         

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

  /* ---------------- *
   *|  copy & clear  |*
   * ---------------- */
  void init( );
  void copy( const dict<T>& );
  void clear( );

  /* ------- *
   *|  put  |*
   * ------- */
  void push_front( const string& );
  void push_front( const string&, const T& );
  void push_back( const string& );
  void push_back( const string&, const T& );

  /* --------- *
   *|  erase  |*
   * --------- */
  void erase( const string& );

  /* ------------ *
   *|  return T  |*
   * ------------ */
  T& front();
  T& back();
  T& operator[]( const string& );
  T& at( const string& );

  /* ------------------ *
   *|  return const T  |*
   * ------------------ */
  const T& front()const;
  const T& back()const;
  const T& operator[]( const string& )const;
  const T& at( const string& )const;

  /* --------- *
   *|  basic  |*
   * --------- */
  bool empty( )const;
  unsigned int size( )const;
  unsigned int count( const string& )const;
  bool exist( const string& )const;

  /* ------------ *
   *|  iterator  |*
   * ------------ */
  class iterator : public std::iterator<bidirectional_iterator_tag, T>
  {
  private:
    vector<string>::iterator itr_;
    map<string,T>&           val_;

    iterator( ){};
  public:
    iterator(const list<string>::iterator& i,map<string,T>& v):itr_(i),val_(v){}
    iterator(const iterator& i):itr_(i.itr_),val_(i.val_){}

    T& operator*(){ return ( val_.at(*itr_) ); }

    iterator& operator++(){ ++itr_; return *this; }
    iterator  operator++(int){ iterator i(*this); ++(*this); return i; }
    iterator& operator--(){ --itr_; return *this; }
    iterator  operator--(int){ iterator i(*this); --(*this); return i; }

    bool operator!=(const iterator& i)const{ return (itr_ != i.itr_); }
    bool operator==(const iterator& i)const{ return (itr_ == i.itr_); }
  };

  iterator begin();
  iterator end();
  iterator find( const string& );
  
  /* ------------------ *
   *|  const_iterator  |*
   * ------------------ */
  class const_iterator : public std::iterator<bidirectional_iterator_tag, T const>
  {
  private:
    vector<string>::const_iterator itr_;
    const map<string,T>&         val_;
    
    const_iterator( ){}
  public:
    const_iterator( const vector<string>::const_iterator& i, const map<string,T>& v ):itr_(i),val_(v){}
    const_iterator( const const_iterator& i ):itr_(i.itr_),val_(i.val_){}

    const T& operator*()const{ return ( val_.at(*itr_) ); }

    const_iterator& operator++(){ ++itr_; return *this; }
    const_iterator  operator++(int){ const_iterator i(*this); ++(*this); return i; }
    const_iterator& operator--(){ --itr_; return *this; }
    const_iterator  operator--(int){ const_iterator i(*this); --(*this); return i; }

    bool operator!=( const const_iterator& i )const{ return (itr_ != i.itr_); }
    bool operator==( const const_iterator& i )const{ return (itr_ == i.itr_); }
  };

  const_iterator begin() const;
  const_iterator end() const;
};

#include "dict.cpp"

#endif // CLASS_T_DICT_H

