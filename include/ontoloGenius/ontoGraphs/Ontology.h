#ifndef ONTOLOGY_H
#define ONTOLOGY_H

#include "ontoloGenius/ontoGraphs/Graphs/ClassGraph.h"
#include "ontoloGenius/ontoGraphs/Graphs/ObjectPropertyGraph.h"
#include "ontoloGenius/ontoGraphs/Graphs/DataPropertyGraph.h"
#include "ontoloGenius/ontoGraphs/Graphs/IndividualGraph.h"

#include "ontoloGenius/ontoGraphs/OntologyReader.h"

class Ontology
{
public:
  Ontology(std::string language = "en");
  ~Ontology() {}

  int close();

  int readFromUri(std::string uri);
  int readFromFile(std::string fileName);

  bool isInit();
  void setLanguage(std::string language);

  ClassGraph class_graph_;
  ObjectPropertyGraph object_property_graph_;
  DataPropertyGraph data_property_graph_;
  IndividualGraph individual_graph_;

private:
  OntologyReader reader;
  std::vector<std::string> files_;
  std::vector<std::string> uri_;

  bool is_init_;
};


#endif
