#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include <boost/filesystem.hpp>

#include <boost/filesystem.hpp>
#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/device/back_inserter.hpp>
#include <boost/iostreams/filter/zlib.hpp>
#include <boost/iostreams/filtering_streambuf.hpp>
#include <boost/uuid/detail/sha1.hpp>

void clearIntermediateFile();

std::string getSHA(std::string &inputStr);
std::string readFile(std::string &filePath);

bool pathExists(std::string &path);
bool fileExists(std::string &filePath);