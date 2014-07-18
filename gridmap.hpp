/*|=====================================
 *|  Copyright (c) 2011-2014 hightoro
 *|  All rights reserved
 *|=====================================
 */

#ifndef HIGHTORO_CPP_ORIGINAL_GRIDMAP_CLASS_H
#define HIGHTORO_CPP_ORIGINAL_GRIDMAP_CLASS_H
//namespace pporig{

template <typename T>
class gridmap
{
  //using size_t = unsigned int;

private:
  int min_x_;
  int min_y_;
  int max_x_;
  int max_y_;

  std::map<coord<2>,T>

public:
  /* ------------------------ *
   *|  Construct & Destruct  |*
   * ------------------------ */
  constexpr gridmap():                  // Construct (Default)
    min_x_(0),min_y_(0),max_x_(1),max_y_(1){}
  ~gridmap()=default;                   // Destruct

  explicit constexpr gridmap(int x1,int y1):
    min_x_(0),min_y_(0),max_x_(x1),max_y_(y1){}

  explicit constexpr gridmap(int x1,int y1,int x0,int y0):
    min_x_(x0),min_y_(y0),max_x_(x1),max_y_(y1){}

  /* ------------------ *
   *|  Copy Construct  |*
   * ------------------ */
  /*constexpr*/ gridmap( const gridmap& )=default;            // Copy Construct 1
  /*constexpr*/ gridmap& operator=(const gridmap&)=default;

  /* ------------------ *
   *|  Move Construct  |*
   * ------------------ */
  /*constexpr*/ gridmap( gridmap&& )=default;              // Move Construct 1
  /*constexpr*/ gridmap& operator=( gridmap&& )=default;   // Move Construct 2


  /* ---------- *
   *|  insert  |*
   * ---------- */



  /* ---------- *
   *|  erase  |*
   * ---------- */


  /* --------- *
   *|  exist  |*
   * --------- */


};
