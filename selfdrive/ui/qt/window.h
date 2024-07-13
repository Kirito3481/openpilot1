#pragma once

#include <QStackedLayout>
#include <QWidget>

#include "selfdrive/ui/qt/offroad/onboarding.h"
#include "selfdrive/ui/qt/offroad/settings.h"

#ifdef SUNNYPILOT
#include "selfdrive/ui/sunnypilot/qt/sp_priv_home.h"
#define HomeWindow HomeWindowSP
#else
#include "selfdrive/ui/qt/home.h"
#endif

class MainWindow : public QWidget {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);

private:
  bool eventFilter(QObject *obj, QEvent *event) override;
  void openSettings(int index = 0, const QString &param = "");
  void closeSettings();

  QStackedLayout *main_layout;
  HomeWindow *homeWindow;
  SettingsWindow *settingsWindow;
  OnboardingWindow *onboardingWindow;
};
