/**
 * @file cli.cpp 
 * @author mlpack
 *
 * cli.cpp implement the basic function of command line.
 *
 * This file is part of command line testing
 *
 * mlpack is free software; you may redstribute it and/or modify it under the
 * terms of the 3-clause BSD license.  You should have received a copy of the
 * 3-clause BSD license along with mlpack.  If not, see
 * http://www.opensource.org/licenses/BSD-3-Clause for more information.
 */
#include <list>
#include <boost/program_options.hpp>
#include <boost/any.hpp>
#include <boost/scoped_ptr.hpp>
#include <string>

#include <iostream>
#include <map>
#include "cli.hpp"
#include "option.hpp"

using namespace util;

// empty ProgramDoc and CLI singleleton;
CLI* CLI::singleton = NULL;
static ProgramDoc emptyProgramDoc = ProgramDoc("", "");


/*
 * @func Constructors, Destructors, Copy constructors;
 *
 * Make the constructor private, to preclude unauthorized instances 
 *
 * @brief constructor of CLI, mostly called by GetSingleton();
 * 
 * @func1 Generally used by caller;
 * @func2 Not used;
 * @func3 Not used(singleton);
 */ 
CLI::CLI() : desc("Allowed Options") , didParse(false), doc(&emptyProgramDoc)
{
  return;
}

CLI::CLI(const std::string& optionsName) :
    desc(optionsName), didParse(false), doc(&emptyProgramDoc)
{
  return;
}

CLI::CLI(const CLI& other) : desc(other.desc),
    didParse(false), doc(&emptyProgramDoc)
{
  return;
}

CLI::~CLI()
{
}

/**
 * @func return the pointer to the instance of the singleton;
 *
 * @param none
 */
CLI& CLI::GetSingleton()
{
  if (singleton == NULL)
    singleton = new CLI();

  return *singleton;
}

void CLI::RegisterProgramDoc(ProgramDoc* doc)
{
  if (doc != &emptyProgramDoc)
    GetSingleton().doc = doc;
}
