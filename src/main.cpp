#include "nts.hpp"

int main() 
{
    std::string path = "~/Downloads/B-OOP-400_nanotekspice/2076_rom.nts";
    nts::parser(path);
    return 0; 
}
