#include "DataExtraction.hpp"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <osmium/osm/node.hpp>

using json = nlohmann::json;

DataExtractor::DataExtractor()
    : node_count(0), way_count(0), relation_count(0) {
  std::cout << "DataExtractor created!\n";
}

void DataExtractor::node(const osmium::Node &n) {
  Node nodes {
    nodes.id;
    nodes.lat;
    nodes.lon;
  };

  node_count++;
}
void DataExtractor::way(const osmium::Way &) {}

void DataExtractor::relation(const osmium::Relation &) { relation_count++; }
