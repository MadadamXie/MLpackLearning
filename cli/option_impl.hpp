/**
 * @file option_impl.hpp
 * @author Matthew Amidon
 *
 * Implementation of template functions for the Option class.
 *
 * This file is part of mlpack 1.0.12.
 *
 * mlpack is free software; you may redstribute it and/or modify it under the
 * terms of the 3-clause BSD license.  You should have received a copy of the
 * 3-clause BSD license along with mlpack.  If not, see
 * http://www.opensource.org/licenses/BSD-3-Clause for more information.
 */
#ifndef __MLPACK_CORE_UTIL_OPTION_IMPL_HPP
#define __MLPACK_CORE_UTIL_OPTION_IMPL_HPP

// Just in case it has not been included.
#include "option.hpp"

namespace util {

/**
 * Registers a parameter with CLI.
 */
template<typename N>
Option<N>::Option(bool ignoreTemplate,
                  N defaultValue,
                  const std::string& identifier,
                  const std::string& description,
                  const std::string& alias,
                  bool required)
{
}


/**
 * Registers a flag parameter with CLI.
 */
template<typename N>
Option<N>::Option(const std::string& identifier,
                  const std::string& description,
                  const std::string& alias)
{
}

}; // namespace util

#endif

