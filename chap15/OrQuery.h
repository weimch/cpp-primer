#pragma once

#include <memory>
#include "Query.h"
#include "BinaryQuery.h"

class OrQuery : public BinaryQuery {
  friend Query operator|(const Query &lhs, const Query &rhs) {
    return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
  }
  OrQuery(const Query &left, const Query &right) :
    BinaryQuery(left, right, "|") { }
  QueryResult eval(const TextQuery&) const;
};
