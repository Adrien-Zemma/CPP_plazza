#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QTextBrowser>
#include <iostream>
#include <vector>
#include <QLabel>
#include <QDebug>

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

private:
    Ui::MainWindow *ui;
    QString         actual_path;
    std::vector<std::pair<std::pair<QLabel *, QLabel *>, QPushButton *>> _files_labels;
};

#endif // MAINWINDOW_H
