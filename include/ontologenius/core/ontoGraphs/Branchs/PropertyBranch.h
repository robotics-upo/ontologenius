#ifndef ONTOLOGENIUS_PROPERTYBRANCH_H
#define ONTOLOGENIUS_PROPERTYBRANCH_H

#include <string>
#include <vector>

#include "ontologenius/core/ontoGraphs/Branchs/Branch.h"
#include "ontologenius/core/ontoGraphs/Branchs/Elements.h"

namespace ontologenius {

struct Properties_t
{
  bool functional_property_;
  bool inverse_functional_property_;
  bool transitive_property_;
  bool symetric_property_;
  bool antisymetric_property_;
  bool reflexive_property_;
  bool irreflexive_property_;

  Properties_t() : functional_property_(false),
                    inverse_functional_property_(false),
                    transitive_property_(false),
                    symetric_property_(false),
                    antisymetric_property_(false),
                    reflexive_property_(false),
                    irreflexive_property_(false) {};
};

template <typename B>
class PropertyBranch_t
{
public:
  std::vector<Single_t<B*>> disjoints_;
  Properties_t properties_;
};

} // namespace ontologenius

#endif // ONTOLOGENIUS_PROPERTYBRANCH_H