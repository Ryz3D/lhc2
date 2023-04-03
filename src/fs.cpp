#include "fs.h"

std::string FS::read_file(std::string path)
{
    std::string content = "";
    FILE *f = fopen(path.c_str(), "r");
    if (f != NULL)
    {
        size_t read_count;
        char buf[FS_BUF_SIZE];
        while ((read_count = fread(buf, 1, FS_BUF_SIZE, f)) > 0)
        {
            content.append(buf, read_count);
        }
    }
    else
    {
        std::cout << "Could not read file \"" << path << "\"" << std::endl;
    }
    return content;
}
