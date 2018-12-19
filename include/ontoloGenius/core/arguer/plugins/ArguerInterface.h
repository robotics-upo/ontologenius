#ifndef ARGUERINTERFACE_H
#define ARGUERINTERFACE_H

#include "ontoloGenius/core/ontoGraphs/Ontology.h"
#include <string>

class ArguerInterface
{
public:
  virtual ~ArguerInterface() {}

  virtual void initialize(Ontology* onto) {ontology_ = onto; }

  virtual void preReason() {}
  virtual void postReason() {}
  virtual void periodicReason() {}

  virtual std::string getName() = 0;
  virtual std::string getDesciption() = 0;

  virtual bool defaultAvtive() {return false;}

  static size_t getNbUpdates() {return nb_update_; }
  static void resetNbUpdates() {nb_update_ = 0; }

  std::vector<std::string> getNotifications()
  {
    std::vector<std::string> tmp = notifications_;
    notifications_.clear();
    return tmp;
  }
protected:
  ArguerInterface() { }

  Ontology* ontology_;

  std::vector<std::string> notifications_;

  static size_t nb_update_;
};

#endif