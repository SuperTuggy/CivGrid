#pragma once
#include <cstdint>
#include <osmium/handler.hpp>
#include <osmium/osm/types.hpp>
#include <unordered_map>

struct Node {
  osmium::object_id_type id = 0;
  double x = 0;
  double y = 0;
};

class DataExtractor : public osmium::handler::Handler {
private:
  int node_count = 0;
  int way_count = 0;
  int relation_count = 0;
  std::unordered_map<osmium::object_id_type, Node> nodes;

public:
  DataExtractor();

  void node(const osmium::Node &);
  void way(const osmium::Way &);
  void relation(const osmium::Relation &);

  int get_node_count() const { return node_count; }
  int get_way_count() const { return way_count; }
  int get_relation_count() const { return relation_count; }
};
