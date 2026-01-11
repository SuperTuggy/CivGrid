#include "DataExtraction.hpp"
#include <iostream>
#include <osmium/osm/node.hpp>


DataExtractor::DataExtractor() : node_count(0), way_count(0), relation_count(0) {
    std::cout << "DataExtractor created!\n";
}

void DataExtractor::node(const osmium::Node& n){
    lat = n.location().lat();
    lon = n.location().lon();

    node_count++;
}

void DataExtractor::way (const osmium::Way&){
    way_count++;
}

void DataExtractor::relation(const osmium::Relation&){
    relation_count++;
}


    
