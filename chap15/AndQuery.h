#pragma once

#include <memory>

#include "BinaryQuery.h"
#include "Query.h"

class AndQuery : public BinaryQuery {
  friend Query operator&(const Query &lhs, const Query &rhs) {
    return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
  }
  AndQuery(const Query &left, const Query &right) :
    BinaryQuery(left, right, "&") { }
  QueryResult eval(const TextQuery&) const;
};
