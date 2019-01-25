#ifndef REASONERINVERSEOF_H
#define REASONERINVERSEOF_H

#include "ontoloGenius/core/reasoner/plugins/ReasonerInterface.h"

class ReasonerInverseOf : public ReasonerInterface
{
public:
  ReasonerInverseOf() {}
  ~ReasonerInverseOf() {}

  virtual void preReason();
  virtual void postReason();

  virtual std::string getName();
  virtual std::string getDesciption();

  virtual bool defaultAvtive() {return true;}
private:

  void insetInverse(IndividualBranch_t* indiv_on, ObjectPropertyBranch_t* inv_prop, IndividualBranch_t* inv_indiv);
};

#endif