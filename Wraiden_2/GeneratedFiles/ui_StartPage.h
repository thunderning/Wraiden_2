/********************************************************************************
** Form generated from reading UI file 'StartPage.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTPAGE_H
#define UI_STARTPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartPage
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QMainWindow *StartPage)
    {
        if (StartPage->objectName().isEmpty())
            StartPage->setObjectName(QStringLiteral("StartPage"));
        StartPage->resize(600, 800);
        centralwidget = new QWidget(StartPage);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(225, 550, 150, 40));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(225, 450, 150, 40));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 150, 300, 125));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(225, 350, 150, 40));
        StartPage->setCentralWidget(centralwidget);

        retranslateUi(StartPage);

        QMetaObject::connectSlotsByName(StartPage);
    } // setupUi

    void retranslateUi(QMainWindow *StartPage)
    {
        StartPage->setWindowTitle(QApplication::translate("StartPage", "MainWindow", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("StartPage", "\346\223\215\344\275\234\350\257\264\346\230\216", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("StartPage", "\350\256\276\347\275\256\351\232\276\345\272\246", Q_NULLPTR));
        label->setText(QApplication::translate("StartPage", "Wraiden2", Q_NULLPTR));
        pushButton->setText(QApplication::translate("StartPage", "\345\274\200\345\247\213\346\270\270\346\210\217", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class StartPage: public Ui_StartPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTPAGE_H
