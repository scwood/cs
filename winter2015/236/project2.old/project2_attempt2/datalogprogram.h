#ifndef DATALOGPROGRAM_H_
#define DATALOGPROGRAM_H_

#include <string>
#include "tokens.h"
#include "scheme.h"
#include "fact.h"
#include "rule.h"
#include "query.h"

class DatalogProgram {
public:
  DatalogProgram();
  ~DatalogProgram();
  std::string toString();
  std::vector<Scheme> schemes;
  std::vector<Fact> facts;
  std::vector<Rule> rules;
  std::vector<Query> queries;
  std::vector<std::string> domain;
};

#endif // DATALOGPROGRAM_H_