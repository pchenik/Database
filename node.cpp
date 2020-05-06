

#include "date.h"
#include "node.h"

bool DateComparisonNode::Evaluate(const Date& date, const string& event) const {
    switch (cmp_) {
        case Comparison::Less:
            return date < date_;
            break;
        case Comparison::LessOrEqual:
            return date < date_ || date == date_;
            break;
        case Comparison::Greater:
            return date > date_;
            break;
        case Comparison::GreaterOrEqual:
            return date > date_ || date == date_;
            break;
        case Comparison::Equal:
            return date == date_;
            break;
        case Comparison::NotEqual:
            return !(date == date_);
            break;
    }
}

bool EventComparisonNode::Evaluate(const Date& date, const string& event) const {
    switch (cmp_) {
        case Comparison::Less:
            return event < event_;
            break;
        case Comparison::LessOrEqual:
            return event <= event_;
            break;
        case Comparison::Greater:
            return event > event_;
            break;
        case Comparison::GreaterOrEqual:
            return event >= event_;
            break;
        case Comparison::Equal:
            return event == event_;
            break;
        case Comparison::NotEqual:
            return event != event_;
            break;
    }
}

bool LogicalOperationNode::Evaluate(const Date& date, const string& event) const {
    switch (op_) {
        case LogicalOperation::Or:
            return left_->Evaluate(date, event) || right_->Evaluate(date, event);
            break;
        case LogicalOperation::And:
            return left_->Evaluate(date, event) && right_->Evaluate(date, event);
            break;
    }
}