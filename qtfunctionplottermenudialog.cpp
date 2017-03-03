#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#pragma GCC diagnostic ignored "-Wunused-but-set-parameter"
#include "qtaboutdialog.h"
#include "functionplottermenudialog.h"
#include "qtfunctionplotterplot2ddialog.h"
#include "qtfunctionplottermenudialog.h"
#include "ui_qtfunctionplottermenudialog.h"
#include "testtimer.h"
#include "trace.h"
#pragma GCC diagnostic pop

ribi::QtFunctionPlotterMenuDialog::QtFunctionPlotterMenuDialog(QWidget *parent)
  : QtHideAndShowDialog(parent),
    ui(new Ui::QtFunctionPlotterMenuDialog)
{
  ui->setupUi(this);
}

ribi::QtFunctionPlotterMenuDialog::~QtFunctionPlotterMenuDialog() noexcept
{
    delete ui;
}

void ribi::QtFunctionPlotterMenuDialog::on_button_start_clicked() noexcept
{
  QtFunctionPlotterPlot2dDialog d;
  this->ShowChild(&d);
}

void ribi::QtFunctionPlotterMenuDialog::on_button_about_clicked() noexcept
{
  About a(FunctionPlotterMenuDialog().GetAbout());
  //a.AddLibrary("QtSurfacePlotWidget version: " + QtSurfacePlotWidget::GetVersion());
  QtAboutDialog d(a);
  this->ShowChild(&d);
}

void ribi::QtFunctionPlotterMenuDialog::on_button_quit_clicked() noexcept
{
  this->close();
}
