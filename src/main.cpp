#include "nts.hpp"
#include <cassert>
#include "falseComponent.hpp"

int main(int argc, char **argv) 
{
    nts::FalseComponent fals;
    parser(argv[1]);
    return nts::execute();; 
}
