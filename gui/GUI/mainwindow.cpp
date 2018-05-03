#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Browse_clicked()
{
    QString directory = QFileDialog::getOpenFileName(this,
                                tr("Find Files"), QDir::currentPath());
    if (!directory.isEmpty()) {
        this->actual_path = directory;
    }
}

void MainWindow::on_click_delete()
{
    QPushButton *button = (QPushButton *)sender();
    int i = 0;

    for (auto &it : _files_labels) {
        if (button == it.second) {
            it.first.first->deleteLater();
            it.first.second->deleteLater();
            it.second->deleteLater();
            _files_labels.erase(_files_labels.begin() + i);
        }
        i++;
    }
}

void MainWindow::on_valid_clicked()
{
    QLabel    *file = new QLabel;
    QLabel    *regex = new QLabel;
    QPushButton    *del = new QPushButton("Delete");

    file->setText(this->actual_path);
    regex->setText(this->actual_path);
    _files_labels.push_back(std::pair<std::pair<QLabel *, QLabel *>, QPushButton *>(std::pair<QLabel *, QLabel *>(file, regex), del));

    this->ui->list->addRow(file);
    this->ui->list->addRow(regex);
    this->ui->list->addRow(del);
    connect(del, SIGNAL (clicked()), this, SLOT (on_click_delete()));
}
