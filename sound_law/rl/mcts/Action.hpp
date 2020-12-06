#pragma once

#include "common.hpp"
#include "SiteGraph.hpp"
#include "Word.hpp"

class TreeNode;

class ActionSpace
{
public:
    ActionSpace(SiteSpace *, WordSpace *);

    SiteSpace *site_space;
    WordSpace *word_space;

    void register_edge(abc_t, abc_t);
    action_t get_action_id(const Action &);
    Action get_action(action_t);
    void set_action_allowed(TreeNode *);

private:
    boost::unordered_map<abc_t, std::vector<abc_t>> edges;
    boost::unordered_map<Action, action_t> a2i; // mapping from actions to action ids;
    std::vector<Action> actions;
};