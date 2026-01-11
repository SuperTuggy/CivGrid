#include <iostream>
#include <osmium/io/any_input.hpp>
#include <osmium/handler.hpp>
#include "DataExtraction/DataExtraction.hpp"
#include "osmium/visitor.hpp"



int main(){

  //TODO: Allows user to choose path from the file system

  std::string path = "/home/woofwoofmachine/github/CivGrid/data/new-york-260103.osm.pbf";

  try{
    osmium::io::Reader my_file(path);
    DataExtractor extractor;

    osmium::apply(my_file, extractor);
    std::cout << "The number of nodes in the file are: " << extractor.get_node_count() << std::endl;
    std::cout << "The number of ways in the file are: " << extractor.get_way_count() << std::endl;
    std::cout << "The number of relations in the file are: " << extractor.get_relation_count() << std::endl;
    my_file.close();



  }
  catch (const std::exception& e){
    std::cerr << "Error" << e.what() << std::endl;

  }
}

