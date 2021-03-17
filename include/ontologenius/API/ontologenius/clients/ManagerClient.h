#ifndef ONTOLOGENIUS_MANAGERCLIENT_H
#define ONTOLOGENIUS_MANAGERCLIENT_H

#include "ontologenius/API/ontologenius/clients/ClientBase.h"

/// @brief The ManagerClient class provides an abstraction ontologenius manage ROS services.
/// The manager client is used to manage ontology instances in multi-ontology usage.
/// This makes it possible to start new ontologies or to stop old ones, but also to study the
/// differences of knowledge between several instances.
/// With the manager client, it is easy to develop software using theory of mind.
/// This class is based on ClientBase and so ensure a persistent connection with the service based on.
/// The persistent connection ensures a minimal response time.
/// A reconnection logic is implemented in the event that the persistent connection fails. 
class ManagerClient : public ClientBase
{
public:
  /// @brief Constructs a manager client.
  /// Can be used in a multi-ontology mode by specifying the name of the ontology name.
  /// @param n is an initialized ROS node handle.
  /// @param name is the instance to be connected to. For classic use, name should be defined as "".
  ManagerClient(ros::NodeHandle* n) : ClientBase(n, "manage")
  {
  }

  /// @brief Gets the name of the instantiated ontologies.
  /// @return the list as the instantiated ontologies in the form of a verctor of string.
  std::vector<std::string> list();
  /// @brief Creates an ontology instance.
  /// @param name is the name of the instance to be created.
  /// @return false if the service call fails.
  bool add(const std::string& name);
  /// @brief Copies an ontology instance.
  /// @param dest_name is the name of the instance to be created.
  /// @param src_name is the name of the instance to be copied.
  /// @return false if the service call fails.
  bool copy(const std::string& dest_name, const std::string& src_name);
  /// @brief Deletes an ontology instance.
  /// @param name is the name of the instance to be deleted.
  /// @return false if the service call fails.
  bool del(const std::string& name);
  /// @brief Returns the difference of knowledge between two instances regarding a concept (class or individual).
  /// @param onto1 is the name of the instance of reference.
  /// @param onto2 is the name of the instance to compare.
  /// @param concept is the name of the concept on which the difference have to be computed.
  /// @return The elements of the returned vector are formated as : [+]concept_from|property|concept_on OR [-]concept_from|property|concept_on.
  /// An element is positive if it is present in onto_1 and not in onto_2 and negative in reverse.
  /// The difference in inheritance knowledge between concepts is returned with the property isA.
  std::vector<std::string> getDifference(const std::string& onto1, const std::string& onto2, const std::string& concept);

private:

};

#endif // ONTOLOGENIUS_MANAGERCLIENT_H
