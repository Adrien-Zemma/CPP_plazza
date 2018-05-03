/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGroupBox *Files;
    QGridLayout *gridLayout_2;
    QFormLayout *list;
    QPushButton *Browse;
    QPushButton *valid;
    QComboBox *comboBox;
    QPushButton *STATUS;
    QGroupBox *Results;
    QPushButton *START;
    QPushButton *regex;
    QPushButton *clear;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(943, 486);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        Files = new QGroupBox(centralWidget);
        Files->setObjectName(QStringLiteral("Files"));
        Files->setCheckable(false);
        gridLayout_2 = new QGridLayout(Files);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        list = new QFormLayout();
        list->setSpacing(6);
        list->setObjectName(QStringLiteral("list"));

        gridLayout_2->addLayout(list, 1, 0, 1, 3);

        Browse = new QPushButton(Files);
        Browse->setObjectName(QStringLiteral("Browse"));

        gridLayout_2->addWidget(Browse, 0, 0, 1, 1);

        valid = new QPushButton(Files);
        valid->setObjectName(QStringLiteral("valid"));
        valid->setAutoFillBackground(false);
        QIcon icon;
        icon.addFile(QStringLiteral("imgs/plus.png"), QSize(), QIcon::Normal, QIcon::Off);
        valid->setIcon(icon);

        gridLayout_2->addWidget(valid, 0, 2, 1, 1);

        comboBox = new QComboBox(Files);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout_2->addWidget(comboBox, 0, 1, 1, 1);


        gridLayout->addWidget(Files, 1, 0, 1, 3);

        STATUS = new QPushButton(centralWidget);
        STATUS->setObjectName(QStringLiteral("STATUS"));

        gridLayout->addWidget(STATUS, 0, 1, 1, 1);

        Results = new QGroupBox(centralWidget);
        Results->setObjectName(QStringLiteral("Results"));

        gridLayout->addWidget(Results, 1, 3, 1, 1);

        START = new QPushButton(centralWidget);
        START->setObjectName(QStringLiteral("START"));

        gridLayout->addWidget(START, 0, 0, 1, 1);

        regex = new QPushButton(centralWidget);
        regex->setObjectName(QStringLiteral("regex"));

        gridLayout->addWidget(regex, 0, 2, 1, 1);

        clear = new QPushButton(centralWidget);
        clear->setObjectName(QStringLiteral("clear"));

        gridLayout->addWidget(clear, 2, 3, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 943, 17));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        Files->setTitle(QApplication::translate("MainWindow", "File to parse", nullptr));
        Browse->setText(QApplication::translate("MainWindow", "Find file", nullptr));
        valid->setText(QString());
        comboBox->setItemText(0, QApplication::translate("MainWindow", "ip", nullptr));
        comboBox->setItemText(1, QApplication::translate("MainWindow", "Mail", nullptr));

        STATUS->setText(QApplication::translate("MainWindow", "STATUS", nullptr));
        Results->setTitle(QApplication::translate("MainWindow", "Results", nullptr));
        START->setText(QApplication::translate("MainWindow", "START", nullptr));
        regex->setText(QApplication::translate("MainWindow", "ADD REGEX", nullptr));
        clear->setText(QApplication::translate("MainWindow", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
