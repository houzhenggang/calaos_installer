#ifndef FORMRULES_H
#define FORMRULES_H

#include <QtGui>

#include <dialognewroom.h>
#include <dialognewwago.h>
#include <dialognewvolet.h>
#include <dialognewdali.h>
#include <dialognewdalirgb.h>
#include <dialognewtemp.h>
#include <dialognewcamera.h>
#include <dialognewaudio.h>
#include <dialognewinternal.h>
#include <dialognewscenario.h>
#include <dialognewtime.h>
#include <dialogcameraview.h>
#include <dialogioproperties.h>
#include <dialognewrule.h>
#include <dialogioplagehoraire.h>

#include <FormConditionStd.h>
#include <FormConditionStart.h>
#include <FormActionStd.h>
#include <FormActionMail.h>

#include <qtreewidget_addition.h>

#include <ListeRoom.h>
#include <ListeRule.h>
#include <Room.h>
#include <IOBase.h>

enum { ITEM_ROOM=0, ITEM_INTER, ITEM_LIGHT, ITEM_VOLET, ITEM_DALI,
       ITEM_DALIRGB, ITEM_TEMP, ITEM_CAMERA, ITEM_MUSIC, ITEM_INTERN,
       ITEM_SCENARIO, ITEM_TIME };

namespace Ui
{
        class FormRules;
}

class FormRules : public QWidget
{
        Q_OBJECT

        public:
                explicit FormRules(QWidget *parent = 0);
                ~FormRules();

                void PopulateRoomsTree();
                void PopulateRulesTree();

                QTreeWidgetItemRoom *addItemRoom(Room *room, bool selected = false);
                QTreeWidgetItemInput *addItemInput(Input *in, QTreeWidgetItemRoom *parent, bool selected = false);
                QTreeWidgetItemOutput *addItemOutput(Output *out, QTreeWidgetItemRoom *parent, bool selected = false);
                QTreeWidgetItemInput *addItemInput(Input *in, Room *parent, bool selected = false);
                QTreeWidgetItemOutput *addItemOutput(Output *out, Room *parent, bool selected = false);

                QTreeWidgetItemRule *addItemRule(Rule *rule, bool selected = false);
                QTreeWidgetItem *addItemCondition(Condition *condition, bool selected = false, bool show_popup = false);
                QTreeWidgetItem *addItemAction(Action *action, bool selected = false, bool show_popup = false);

                static void updateItemInfos(QTreeWidgetItemRoom *item);
                static void updateItemInfos(QTreeWidgetItemInput *item);
                static void updateItemInfos(QTreeWidgetItemOutput *item);
                static void updateItemInfos(QTreeWidgetItemRule *item);
                static void updateItemCondition(QTreeWidgetItem *item, Condition *condition);
                static void updateItemAction(QTreeWidgetItem *item, Action *action);

                Rule *getCurrentRule();

                bool projectChanged() { return project_changed; }

                void ClearProject();

        protected:
                void changeEvent(QEvent *e);

        private:
                Ui::FormRules *ui;

                Room *current_room; //Current used room in the interface

                QMenu *add_menu, *addConditionMenu, *addActionMenu;

                //Item used by right-click menu in tree
                QTreeWidgetItem *treeItem, *treeItem_condition, *treeItem_action;

                bool project_changed;

                FormConditionStd *popupConditionStd;
                FormConditionStart *popupConditionStart;

                FormActionStd *popupActionStd;
                FormActionMail *popupActionMail;


        public slots:
                void addCalaosItem(int item);
                void showPopup_tree(const QPoint point);
                void showPopup_condition(const QPoint point);
                void showPopup_action(const QPoint point);
                void showPopup_rule(const QPoint point);
                void deleteItem();
                void deleteItemCondition();
                void deleteItemAction();
                void goSelectRule();
                void showPropertiesItem();
                void addCondition(int type);
                void addAction(int type);

                void itemLightOn();
                void itemLightOff();
                void itemVoletUp();
                void itemVoletDown();
                void itemVoletStop();
                void itemShowCamera();
                void itemPlagesHoraires();
                void itemConvertInterTriple();
                void itemConvertInterBP();
                void itemConvertVoletStandard();
                void itemConvertVoletSmart();

        private slots:
                void on_pushButtonAction_clicked();
                void on_pushButtonCond_clicked();
                void on_tree_rules_itemDoubleClicked(QTreeWidgetItem* item, int column);
                void on_bt_action_del_clicked();
                void on_bt_condition_del_clicked();
                void on_tree_action_itemClicked(QTreeWidgetItem* item, int column);
                void on_tree_condition_itemClicked(QTreeWidgetItem* item, int column);
                void on_filterEditRules_textChanged(QString );
                void on_filterEditHome_textChanged(QString );
                void on_bt_rules_del_clicked();
                void on_tree_rules_currentItemChanged(QTreeWidgetItem* current, QTreeWidgetItem* previous);
                void on_bt_rules_add_clicked();
                void on_tree_home_itemDoubleClicked(QTreeWidgetItem* item, int column);
                void on_tree_home_currentItemChanged(QTreeWidgetItem* current, QTreeWidgetItem* previous);
};

#endif // FORMRULES_H