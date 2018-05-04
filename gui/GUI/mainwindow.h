#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QTextBrowser>
#include <iostream>
#include <vector>
#include <QLabel>
#include <QDebug>

#include "plazza.hpp"
#include "regexform.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Browse_clicked();

    void on_valid_clicked();

    void on_click_delete();

    void on_START_clicked();

    void on_regex_clicked();

private:
    Ui::MainWindow *ui;
    RegexForm   form;
    QString         actual_path;
    std::vector<std::pair<std::pair<QLabel *, QLabel *>, QPushButton *>> _files_labels;
    std::shared_ptr<std::vector<std::pair<std::string, std::string>>> _queu;
    std::shared_ptr<std::map<std::string, std::string>>    _regexList;
    Plazza          *manager;
};

#endif // MAINWINDOW_H
