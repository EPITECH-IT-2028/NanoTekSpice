#include "Factory.hpp"
#include "nts.hpp"
#include <map>
#include <memory>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include <iostream>

void getComponents(std::ifstream *strm)
{
    std::string res;
    std::string component;
    std::string name;
    nts::Factory factory;
    while (std::getline(*strm, res)) {
        if (res.find(".links:") != res.npos)
            return;
        if (res.size() == 0 || res[0] == '#')
            continue;
        std::stringstream line(res);
        line >> component >> name;
        std::cout << "name: " << name << " component: " << component << std::endl;
        // addComponent()
    }
    return;
}

void split_inf(const std::string& str, char delimiter, std::vector<std::string>& inf) {
    std::stringstream s(str);
    std::string info;
    while (std::getline(s, info, delimiter))
        inf.push_back(info);
}

void getLinks(std::ifstream *strm)
{
    std::string res;
    std::string cp1;
    std::string cp2;
    while (std::getline(*strm, res)) {
        if (res.size() == 0 || res[0] == '#')
            continue;
        std::stringstream line(res);
        line >> cp1 >> cp2;
        std::cout << "cp1: " << cp1 << " cp2: " << cp2 << std::endl;
        std::vector<std::string> inf_cp1;
        split_inf(cp1, ':', inf_cp1);
        std::vector<std::string> inf_cp2;
        split_inf(cp2, ':', inf_cp2);
        //findComponent()
        //setLinks()
    }
}

void parser(const std::string &path)
{
    std::ifstream strm;
    std::string res;
    std::map<std::string, std::unique_ptr<nts::IComponent>> map;
    strm.open(path, std::ifstream::in);
    if (!strm.is_open())
        return;
    while (std::getline(strm, res)) {
        if (res.size() == 0 || res[0] == '#')
            continue;
        if (res.find(".chipsets:") != res.npos) {
            getComponents(&strm);
            getLinks(&strm);
        }
    }
    strm.close();
}