#pragma once
#include "../mathlib/GeoMath.hpp"
#include <osmium/handler.hpp>
#include <osmium/osm/types.hpp>
#include <vector>

struct Node {
  GeoMath::Point position;
  osmium::object_id_type id = 0;
  std::pair<osmium::object_id_type, GeoMath::Point> nodes;
  std::vector<osmium::object_id_type> highways;
};

class DataExtractor : public osmium::handler::Handler {
private:
  int node_count = 0;
  int way_count = 0;
  int relation_count = 0;

public:
  DataExtractor();

  Node nodes;
  void node(const osmium::Node &);
  void way(const osmium::Way &);
  void relation(const osmium::Relation &);

  int get_node_count() const { return node_count; }
  int get_way_count() const { return way_count; }
  int get_relation_count() const { return relation_count; }
};
