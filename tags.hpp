/*|=====================================
 *|  Copyright (c) 2011-2014 hightoro
 *|  All rights reserved
 *|=====================================
 */

#ifndef HIGHTORO_CPP_ORIGINAL_TAGS_FUNCTIONS_H
#define HIGHTORO_CPP_ORIGINAL_TAGS_FUNCTIONS_H

/* ----------------- *
 *| escape sequence |*
 * ----------------- */
struct tags
{
  static constexpr char* ERROR  = (char*)" \x1b[1;4;31m[ERROR]\x1b[0m  ";
  static constexpr char* WARN   = (char*)    " \x1b[34m[WARNING]\x1b[0m";
  static constexpr char* INFO   = (char*)  " \x1b[1;33m[INFO]\x1b[0m   ";
  static constexpr char* WS     = (char*)"           ";
};

#endif

