

#ifndef FINAL_YELLOW_NODE_H
#define FINAL_YELLOW_NODE_H

#include <memory>

#include "date.h"

enum class LogicalOperation {
    Or,
    And,
};

enum class Comparison {
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual,
};

class Node {
public:
    virtual bool Evaluate(const Date& date, const string& event) const = 0;
};

class DateComparisonNode: public Node {
public:
    DateComparisonNode(Comparison cmp, const Date& date) : cmp_(cmp), date_(date) {}
    bool Evaluate(const Date& date, const string& event) const override;
private:
    Comparison cmp_;
    Date date_;
};

class EventComparisonNode: public Node {
public:
    EventComparisonNode(Comparison cmp, const string& event) : cmp_(cmp), event_(event) {}
    bool Evaluate(const Date& date, const string& event) const override;
private:
    Comparison cmp_;
    string event_;
};

class LogicalOperationNode: public Node {
public:
    LogicalOperationNode(LogicalOperation op, shared_ptr<Node> left, shared_ptr<Node> right) :
            op_(op), left_(left), right_(right) {}
    bool Evaluate(const Date& date, const string& event) const override;

private:
    shared_ptr<Node> left_, right_;
    LogicalOperation op_;
};

class EmptyNode: public Node {
public:
    EmptyNode() {}
    bool Evaluate(const Date& date, const string& event) const override { return true; }
};

#endif //FINAL_YELLOW_NODE_H
