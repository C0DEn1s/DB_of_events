//
// Created by denis on 13.08.2020.
//

#include "node.h"

EmptyNode::EmptyNode() = default;

bool EmptyNode::Evaluate(const Date& date, const string& event) const {
    return true;
}

DateComparisonNode::DateComparisonNode(Comparison cmp, const Date& date) :
    date_info(date),
    date_cmp(cmp) {}

bool DateComparisonNode::Evaluate(const Date& date, const string& event) const{
    if (date_cmp == Comparison::Equal) {
        tuple<int, int, int> left = make_tuple(date.GetYear(), date.GetMonth(), date.GetDay());
        tuple<int, int, int> right = make_tuple(date_info.GetYear(), date_info.GetMonth(), date_info.GetDay());
        return left == right;
    } else if (date_cmp == Comparison::GreaterOrEqual) {
        return !(date < date_info);
    } else if (date_cmp == Comparison::Greater) {
        return date > date_info;
    } else if (date_cmp == Comparison::Less) {
        return date < date_info;
    } else if (date_cmp == Comparison::LessOrEqual) {
        return !(date > date_info);
    } else if (date_cmp == Comparison::NotEqual) {
        tuple<int, int, int> left = make_tuple(date.GetYear(), date.GetMonth(), date.GetDay());
        tuple<int, int, int> right = make_tuple(date_info.GetYear(), date_info.GetMonth(), date_info.GetDay());
        return left != right;
    }
    return false;
}

EventComparisonNode::EventComparisonNode(Comparison cmp, const string& event) :
        event_info(event),
        event_cmp(cmp) {}

bool EventComparisonNode::Evaluate(const Date& date, const string& event) const {
    if (event_cmp == Comparison::Equal) {
        return event == event_info;
    } else if (event_cmp == Comparison::NotEqual) {
        return event != event_info;
    } else if (event_cmp == Comparison::GreaterOrEqual) {
        return event >= event_info;
    } else if (event_cmp == Comparison::Greater) {
        return event > event_info;
    } else if (event_cmp == Comparison::Less) {
        return event < event_info;
    } else if (event_cmp == Comparison::LessOrEqual) {
        return event <= event_info;
    }
    return false;
}

LogicalOperationNode::LogicalOperationNode(const LogicalOperation &op, const shared_ptr<Node> &lhs,
                                           const shared_ptr<Node> &rhs) :
                                           logic_operation(op),
                                           lhs_(lhs),
                                           rhs_(rhs) {}

bool LogicalOperationNode::Evaluate(const Date& date, const string& event) const {
    switch (logic_operation) {
        case LogicalOperation::And:
            return lhs_->Evaluate(date, event) && rhs_->Evaluate(date, event);
        case LogicalOperation::Or:
            return lhs_->Evaluate(date, event) || rhs_->Evaluate(date, event);
    }
}