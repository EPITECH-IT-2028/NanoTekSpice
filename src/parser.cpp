#include "Factory.hpp"
#include "nts.hpp"
#include <map>
#include <memory>
#include <sstream>
#include <string>
#include <fstream>

void parser(const std::string &path)
{
    std::ifstream strm;
    std::string res;
    nts::Factory factory;
    std::map<std::string, std::unique_ptr<nts::IComponent>> map;
    strm.open(path, std::ifstream::in);
    if (!strm.is_open())
        return;
    while (std::getline(strm, res)) {
        while (res.find(".links:") == res.npos) {
            std::stringstream line;
            std::string component;
            std::string name;
            line >> component >> name;
            std::cout << "name: " << name << " component: " << component << std::endl;
            // map[name] = factory.createComponent(component);
            // addComponent(name, component);
        }

    }
    strm.close();
}