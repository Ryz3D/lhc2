#pragma once

#include <iostream>
#include <string>
#include <stdio.h>

#define FS_BUF_SIZE 100

class FS
{
public:
    static std::string read_file(std::string path);
};
