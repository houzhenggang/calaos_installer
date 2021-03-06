/******************************************************************************
**  Copyright (c) 2007-2008, Calaos. All Rights Reserved.
**
**  This file is part of Calaos Home.
**
**  Calaos Home is free software; you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation; either version 3 of the License, or
**  (at your option) any later version.
**
**  Calaos Home is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License
**  along with Foobar; if not, write to the Free Software
**  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
**
******************************************************************************/
#ifndef S_RULE_H
#define S_RULE_H

#include <Utils.h>
#include <Condition.h>
#include <Action.h>

namespace Calaos
{

class Rule
{
protected:
    std::vector<Condition *> conds;
    std::vector<Action *> actions;

public:
    Rule(Params p):
        ruleParams(p)
    { }
    ~Rule();

    Params ruleParams;

    void AddCondition(Condition *p);
    void AddAction(Action *p);
    void RemoveCondition(int i);
    void RemoveAction(int i);

    void MoveConditionUp(int pos);
    void MoveConditionDown(int pos);
    void MoveActionUp(int pos);
    void MoveActionDown(int pos);

    Condition *get_condition(int i) { return conds[i]; }
    Action *get_action(int i) { return actions[i]; }

    int get_size_conds() { return conds.size(); }
    int get_size_actions() { return actions.size(); }

    string get_type() { return ruleParams["type"]; }
    string get_name() { return ruleParams["name"]; }

    void set_type(string s) { ruleParams.Add("type", s); }
    void set_name(string s) { ruleParams.Add("name", s); }

    Rule *duplicate();

    void Print();
};

}
#endif
