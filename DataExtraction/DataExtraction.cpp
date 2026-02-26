#include "DataExtraction.hpp"
#include "../mathlib/GeoMath.hpp"
#include <iostream>
#include <nlohmann/json.hpp>
#include <osmium/osm/node.hpp>
#include <osmium/osm/way.hpp>
using json = nlohmann::json;

DataExtractor::DataExtractor()
    : node_count(0), way_count(0), relation_count(0) {
  std::cout << "DataExtractor created!\n";
}

void DataExtractor::node(const osmium::Node &n) {
  Node node;

  node.id = n.id();
  node.x = n.location().lon();
  node.y = n.location().lat();

  node.nodes[node.id] = node;
  node_count++;
}
void DataExtractor::way(const osmium::Way &w) {
  way_count++;

  const char *highway = w.tags()["highway"];

  if (!highway) {
    return;
  }

  for (size_t i = 0; i + 1 < w.nodes().size(); i++) {
  }
}

void DataExtractor::relation(const osmium::Relation &) { relation_count++; }
