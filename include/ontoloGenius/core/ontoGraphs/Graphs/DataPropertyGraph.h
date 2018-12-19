#include <string>
#include <vector>
#include <unordered_set>
#include <map>
#include <stdint.h>

#include "ontoloGenius/core/ontoGraphs/Graphs/OntoGraph.h"

#include "ontoloGenius/core/ontoGraphs/Branchs/DataPropertyBranch.h"
#include "ontoloGenius/core/ontoGraphs/Branchs/ClassBranch.h"

#ifndef DATAPROPERTYGRAPH_H
#define DATAPROPERTYGRAPH_H

struct DataPropertyVectors_t
{
   std::vector<std::string> mothers_;
   std::vector<std::string> disjoints_;
   std::vector<std::string> domains_;
   std::vector<std::string> ranges_;
   Properties_t properties_;
   std::map<std::string, std::vector<std::string>> dictionary_;
};

//for friend
class DataPropertyDrawer;
class IndividualGraph;

//for graphs usage
class ClassGraph;

class DataPropertyGraph : public OntoGraph<DataPropertyBranch_t>
{
  friend DataPropertyDrawer;
  friend IndividualGraph;
  friend ClassGraph;
public:
  DataPropertyGraph(ClassGraph* class_graph) {class_graph_ = class_graph; }
  ~DataPropertyGraph() {}

  void linkGraph(ClassGraph* class_graph) {class_graph_ = class_graph; }

  void add(std::string value, DataPropertyVectors_t& property_vectors);
  void add(std::vector<std::string>& disjoints);

  std::unordered_set<std::string> getDisjoint(const std::string& value);
  std::unordered_set<std::string> getDomain(const std::string& value);
  std::unordered_set<std::string> getRange(const std::string& value);
  std::unordered_set<std::string> select(std::unordered_set<std::string>& on, const std::string& selector);

  bool add(DataPropertyBranch_t* prop, std::string& relation, std::string& data);
  bool addInvert(DataPropertyBranch_t* prop, std::string& relation, std::string& data);
  bool remove(DataPropertyBranch_t* prop, std::string& relation, std::string& data);

private:
  ClassGraph* class_graph_;

  void isMyDisjoint(DataPropertyBranch_t* me, const std::string& disjoint, std::vector<DataPropertyBranch_t*>& vect, bool& find, bool all = true)
  {
    if(find)
      return;

    for(size_t i = 0; i < vect.size(); i++)
      if(disjoint == vect[i]->value())
      {
        me->setSteady_disjoint(vect[i]);
        if(all)
          vect[i]->disjoints_.push_back(me);
        find = true;
        break;
      }
  }

  void isMyDomain(DataPropertyBranch_t* me, const std::string& domain, std::vector<ClassBranch_t*>& vect, bool& find)
  {
    if(find)
      return;

    for(size_t i = 0; i < vect.size(); i++)
      if(domain == vect[i]->value())
      {
        me->setSteady_domain(vect[i]);
        find = true;
        break;
      }
  }
};

#endif /* DATAPROPERTYGRAPH_H */