#ifndef RELATIONALDATABASE_H_
#define RELATIONALDATABASE_H_

#include "datalogprogram.h"
#include "relation.h"

class RelationalDatabase {
public:
  // methods
  RelationalDatabase(DatalogProgram program);
  void answerQueries();
  void evaluateRules();
  // data members
  std::vector<Relation> relations;
private:
  // methods
  void generateRelations(DatalogProgram program);
  void removeDuplicateTuples(std::vector<std::vector<std::string> > &vec);
  void updateDatabaseSize();
  int getSchemeIndex(Relation relation, std::string id);
  Relation getRelation(std::string id);
  Relation select(Relation relation, int index, std::string token);
  Relation select(Relation relation, int index_one, int index_two);
  Relation rename(Relation relation, int index, std::string token);
  Relation project(Relation relation, std::vector<std::string> id_list);
  Relation naturalJoin(std::vector<Relation> relations);
  std::vector<Relation> evaluatePredicates(Rule rule);
  void unionWithDatabase(Relation relation);
  // data members
  DatalogProgram program;
  int database_size;

};

#endif // RELATIONALDATABASE_H_