/* ========================= eCAL LICENSE =================================
 *
 * Copyright (C) 2016 - 2019 Continental Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *      http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * ========================= eCAL LICENSE =================================
*/

#pragma once

#include <QWidget>
#include "ui_scenario_widget.h"

#include "q_ecal_play.h"

#include <CustomQt/QStandardTreeModel.h>
#include <CustomQt/QStandardTreeItem.h>
#include <CustomQt/QStableSortFilterProxyModel.h>

class ScenarioWidget : public QWidget
{
  Q_OBJECT

public:
  ScenarioWidget(QWidget *parent = Q_NULLPTR);
  ~ScenarioWidget();

public slots:
  void measurementLoaded(const QString& path);
  void measurementClosed();

  void resetLayout();

private slots:
  void jumpToSelectedScenario() const;


private:
  Ui::ScenarioWidget ui_;

  std::pair<eCAL::Time::ecal_clock::time_point, eCAL::Time::ecal_clock::time_point> measurement_boundaries_;

  QStandardTreeModel*          scenario_tree_model_;
  QStableSortFilterProxyModel* scenario_tree_proxy_model_;

  QByteArray initial_tree_state_;

  void reloadScenarioTree();
  QList<QStandardTreeItem*> selectedItems() const;

  void autoSizeColumns();

  void saveLayout();
  void restoreLayout();
  void saveInitialLayout();
};
