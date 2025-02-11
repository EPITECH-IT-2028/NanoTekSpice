#include "Factory.hpp"
#include "nts.hpp"
#include <fstream>
#include <map>
#include <memory>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

std::map<std::string, std::shared_ptr<nts::IComponent>>
getComponents(std::ifstream *strm) {
  std::map<std::string, std::shared_ptr<nts::IComponent>> map;
  std::string res;
  std::string component;
  std::string name;
  nts::Factory factory;

  while (std::getline(*strm, res)) {
    if (res.find(".links:") != res.npos)
      break;
    if (res.size() == 0 || res[0] == '#')
      continue;
    std::stringstream line(res);
    line >> component >> name;
    map[name] = factory.createComponent(component);
  }
  return map;
}

void split_inf(const std::string &str, char delimiter,
               std::vector<std::string> &inf) {
  std::stringstream s(str);
  std::string info;

  while (std::getline(s, info, delimiter))
    inf.push_back(info);
}

void getLinks(std::ifstream *strm,
              std::map<std::string, std::shared_ptr<nts::IComponent>> &map) {
  std::map<std::pair<std::shared_ptr<nts::IComponent>, nts::Tristate>,
           std::pair<std::shared_ptr<nts::IComponent>, nts::Tristate>>
      links;
  std::string res;
  std::string cp1;
  std::string cp2;

  while (std::getline(*strm, res)) {
    if (res.size() == 0 || res[0] == '#')
      continue;
    std::stringstream line(res);
    line >> cp1 >> cp2;
    std::vector<std::string> inf_cp1;
    split_inf(cp1, ':', inf_cp1);
    std::vector<std::string> inf_cp2;
    split_inf(cp2, ':', inf_cp2);
    map[inf_cp1[0]]->setLink(std::stol(inf_cp1[1]), *map[inf_cp2[0]],
                             std::stol(inf_cp2[1]));
    map[inf_cp2[0]]->setLink(std::stol(inf_cp2[1]), *map[inf_cp1[0]],
                             std::stol(inf_cp1[1]));
  }
}

/*
 * This function is the parser of the program.
 * @param std::string path
 * @return void or throw exception
 */
void parser(const std::string &path) {
  std::ifstream strm;
  std::string res;
  std::map<std::string, std::shared_ptr<nts::IComponent>> map;

  strm.open(path, std::ifstream::in);
  if (!strm.is_open())
    return; // TODO: throw exeception
  while (std::getline(strm, res)) {
    if (res.size() == 0 || res[0] == '#')
      continue;
    if (res.find(".chipsets:") != res.npos) {
      map = getComponents(&strm);
      getLinks(&strm, map);
    }
  }
  strm.close();
}
