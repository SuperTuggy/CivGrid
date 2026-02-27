#include "DataExtraction.hpp"
#include "../mathlib/GeoMath.hpp"
#include <iostream>
#include <nlohmann/json.hpp>
#include <osmium/osm/node.hpp>
#include <osmium/osm/types.hpp>
#include <osmium/osm/way.hpp>
using json = nlohmann::json;

DataExtractor::DataExtractor()
    : node_count(0), way_count(0), relation_count(0) {
  std::cout << "DataExtractor created!\n";
}
void DataExtractor::node(const osmium::Node &n) {
  nodes.id = n.id();
  nodes.position.x = n.location().lon();
  nodes.position.y = n.location().lat();

  nodes.nodes.first = n.id();
  nodes.nodes.second = nodes.position;

  node_count++;
}
void DataExtractor::way(const osmium::Way &w) {
  way_count++;

  const char *highway = w.tags()["highway"];

  if (!highway) {
    return;
  }

  for (const osmium::NodeRef &nr : w.nodes()) {
    std::cout << "\rNow looking for Highways" << std::flush;
    osmium::object_id_type id = nr.ref();

    nodes.highways.push_back(id);
  }
}

void DataExtractor::relation(const osmium::Relation &) { relation_count++; }
