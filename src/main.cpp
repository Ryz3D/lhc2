#include "main.h"

void help()
{
    std::cout << "Usage: lhc [Input]" << std::endl;
}

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        help();
        return 0;
    }

    std::string src = FS::read_file(std::string(argv[1]));

    std::cout << "LHC Done!" << std::endl;

    return 0;
}
