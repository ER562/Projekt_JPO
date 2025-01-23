#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "data_base.h"
#include <QMessageBox>
#include <QFileDialog>
#include <fstream>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_zapisz_pressed();

    void on_wyczysc_pressed();

    void on_wyszukaj_pressed();

    void on_Ok_pressed();

    void on_spinBox_valueChanged(int arg1);

    void on_delete_2_pressed();

    void on_pushButton_pressed();

    void on_pushButton_2_pressed();

private:
    Ui::MainWindow *ui;
    data_center base;
};
#endif // MAINWINDOW_H
