/**
 * @file cli.hpp
 * @author Matthew Amidon
 *
 * This file implements the CLI subsystem which is intended to replace FX.
 * This can be used more or less regardless of context.  In the future,
 * it might be expanded to include file I/O.
 *
 * This file is part of mlpack 1.0.12.
 *
 * mlpack is free software; you may redstribute it and/or modify it under the
 * terms of the 3-clause BSD license.  You should have received a copy of the
 * 3-clause BSD license along with mlpack.  If not, see
 * http://www.opensource.org/licenses/BSD-3-Clause for more information.
 */
#ifndef  __MLPACK_CORE_UTIL_CLI_HPP
#define  __MLPACK_CORE_UTIL_CLI_HPP

#include <iostream>
#include <map>
#include <string>

#include <boost/any.hpp>
#include <boost/program_options.hpp>



#define PROGRAM_INFO(NAME, DESC) static mlpack::util::ProgramDoc \
    io_programdoc_dummy_object = mlpack::util::ProgramDoc(NAME, DESC);

#define PARAM_FLAG(ID, DESC, ALIAS) \
    PARAM_FLAG_INTERNAL(ID, DESC, ALIAS);

#define PARAM_INT(ID, DESC, ALIAS, DEF) \
    PARAM(int, ID, DESC, ALIAS, DEF, false)

#define PARAM_FLOAT(ID, DESC, ALIAS, DEF) \
    PARAM(float, ID, DESC, ALIAS, DEF, false)

#define PARAM_DOUBLE(ID, DESC, ALIAS, DEF) \
    PARAM(double, ID, DESC, ALIAS, DEF, false)

#define PARAM_STRING(ID, DESC, ALIAS, DEF) \
    PARAM(std::string, ID, DESC, ALIAS, DEF, false)

#define PARAM_VECTOR(T, ID, DESC, ALIAS) \
    PARAM(std::vector<T>, ID, DESC, ALIAS, std::vector<T>(), false)

#define PARAM_INT_REQ(ID, DESC, ALIAS) PARAM(int, ID, DESC, ALIAS, 0, true)

#define PARAM_FLOAT_REQ(ID, DESC, ALIAS) PARAM(float, ID, DESC, ALIAS, 0.0f, \
    true)

#define PARAM_DOUBLE_REQ(ID, DESC, ALIAS) PARAM(double, ID, DESC, ALIAS, \
    0.0f, true)

#define PARAM_STRING_REQ(ID, DESC, ALIAS) PARAM(std::string, ID, DESC, \
    ALIAS, "", true);

#define PARAM_VECTOR_REQ(T, ID, DESC, ALIAS) PARAM(std::vector<T>, ID, DESC, \
    ALIAS, std::vector<T>(), true);

#define JOIN(x, y) JOIN_AGAIN(x, y)
#define JOIN_AGAIN(x, y) x ## y


#define PARAM(T, ID, DESC, ALIAS, DEF, REQ) static mlpack::util::Option<T> \
    JOIN(JOIN(io_option_dummy_object_, __LINE__), opt) (false, DEF, ID, \
    DESC, ALIAS, REQ);

#define PARAM_FLAG_INTERNAL(ID, DESC, ALIAS) static \
    mlpack::util::Option<bool> JOIN(__io_option_flag_object_, __LINE__) \
    (ID, DESC, ALIAS);

#define TYPENAME(x) (std::string(typeid(x).name()))

namespace po = boost::program_options;
namespace util {
  class ProgramDoc;
}


class CLI{
public:
  // Fucntions
  static void RegisterProgramDoc(util::ProgramDoc* doc);
  static CLI& GetSingleton();

  // Members
  static CLI* singleton;
  util::ProgramDoc *doc;
};



#endif

