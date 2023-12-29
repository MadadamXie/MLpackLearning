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

namespace po = boost::program_options;

CLI* CLI::singleton = NULL;

static ProgramDoc emptyProgramDoc = ProgramDoc("", "");

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
