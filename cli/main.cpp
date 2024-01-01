/**
 * @file main.cpp
 * @author XieYuhan
 *
 * main.cpp is to test the command line components;
 * 
 * This file is part of command line test
 *
 * mlpack is free software; you may redstribute it and/or modify it under the
 * terms of the 3-clause BSD license.  You should have received a copy of the
 * 3-clause BSD license along with mlpack.  If not, see
 * http://www.opensource.org/licenses/BSD-3-Clause for more information.
 */
#include <iostream>
#include "cli.hpp"

PROGRAM_INFO("Test", "Test program doc for command line.\r\n");

//PARAM_STRING_REQ("command1","Test Command 1","c");


int main(int argc, char** argv){
    cout << CLI::GetSingleton().doc->programName << endl;
}
