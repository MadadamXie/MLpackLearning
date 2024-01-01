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
#ifndef  __MLPACK_CORE_UTIL_OPTION_HPP
#define  __MLPACK_CORE_UTIL_OPTION_HPP

#include "cli.hpp"

using namespace std;

namespace util{

template<typename N>
class Option
{
 public:

  /**
   * Construct an Option object.  When constructed, it will register
   * itself with CLI.
   *
   * @param ignoreTemplate Whether or not the template type matters for this
   *     option.  Essentially differs options with no value (flags) from those
   *     that do, and thus require a type.
   * @param defaultValue Default value this parameter will be initialized to.
   * @param identifier The name of the option (no dashes in front; for --help,
   *      we would pass "help").
   * @param description A short string describing the option.
   * @param parent Full pathname of the parent module that "owns" this option.
   *      The default is the root node (an empty string).
   * @param required Whether or not the option is required at runtime.
   */
  Option(bool ignoreTemplate,
         N defaultValue,
         const std::string& identifier,
         const std::string& description,
         const std::string& parent = std::string(""),
         bool required = false);

  /**
   * Constructs an Option object.  When constructed, it will register a flag
   * with CLI.
   *
   * @param identifier The name of the option (no dashes in front); for --help
   *     we would pass "help".
   * @param description A short string describing the option.
   * @param parent Full pathname of the parent module that "owns" this option.
   *     The default is the root node (an empty string).
   */
  Option(const std::string& identifier,
         const std::string& description,
         const std::string& parent = std::string(""));
};

class ProgramDoc
{
 public:
  /**
   * Construct a ProgramDoc object.  When constructed, it will register itself
   * with CLI.
   *
   * @param programName Short string representing the name of the program.
   * @param documentation Long string containing documentation on how to use the
   *     program and what it is.  No newline characters are necessary; this is
   *     taken care of by CLI later.
   */
  ProgramDoc(const std::string& programName,
             const std::string& documentation);

  //! The name of the program.
  std::string programName;
  //! Documentation for what the program does.
  std::string documentation;
};
}

#endif
