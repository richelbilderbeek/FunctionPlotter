#ifndef QTFUNCTIONPLOTTERMENUDIALOG_H
#define QTFUNCTIONPLOTTERMENUDIALOG_H

#include "qthideandshowdialog.h"

namespace Ui {
  class QtFunctionPlotterMenuDialog;
}

namespace ribi {

class QtFunctionPlotterMenuDialog : public QtHideAndShowDialog
{
  Q_OBJECT //!OCLINT
    
public:
  explicit QtFunctionPlotterMenuDialog(QWidget *parent = 0);
  QtFunctionPlotterMenuDialog(const QtFunctionPlotterMenuDialog&) = delete;
  QtFunctionPlotterMenuDialog& operator=(const QtFunctionPlotterMenuDialog&) = delete;
  ~QtFunctionPlotterMenuDialog() noexcept;
    
private slots:
  void on_button_start_clicked() noexcept;
  void on_button_about_clicked() noexcept;
  void on_button_quit_clicked() noexcept;

private:
  Ui::QtFunctionPlotterMenuDialog *ui;
};

} //~namespace ribi

#endif // QTFUNCTIONPLOTTERMENUDIALOG_H
