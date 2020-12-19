//
// Created by denis on 13.08.2020.
//

#ifndef FINAL_NODE_H
#define FINAL_NODE_H

#include "date.h"
#include <string>
#include <memory>
using namespace std;

enum class Comparison {
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual
};

enum class LogicalOperation {
    Or,
    And
};

class Node {
public:
    Node() = default;
    virtual bool Evaluate(const Date& date, const string& event) const = 0;
};

class EmptyNode : public Node {
public:
    EmptyNode();
    bool Evaluate(const Date& date, const string& event) const override;
private:
};

class DateComparisonNode : public Node {
public:
    DateComparisonNode(Comparison cmp, const Date& date);
    bool Evaluate(const Date& date, const string& event) const override;
private:
    const Date date_info;
    const Comparison date_cmp;
};

class EventComparisonNode : public Node {
public:
    EventComparisonNode(Comparison cmp, const string& event);
    bool Evaluate(const Date& d, const string& event) const override;
private:
    const string event_info;
    const Comparison event_cmp;
};

class LogicalOperationNode : public Node {
public:
    LogicalOperationNode(const LogicalOperation& op, const shared_ptr<Node>& lhs, const shared_ptr<Node>& rhs);
    bool Evaluate(const Date& date, const string& event) const override;
private:
    const LogicalOperation logic_operation;
    const shared_ptr<Node> lhs_, rhs_;
};

#endif //FINAL_NODE_H
