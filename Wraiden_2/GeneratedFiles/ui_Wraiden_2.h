/********************************************************************************
** Form generated from reading UI file 'Wraiden_2.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WRAIDEN_2_H
#define UI_WRAIDEN_2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Wraiden_2Class
{
public:
    QWidget *centralWidget;
    QGraphicsView *graphicsView;

    void setupUi(QMainWindow *Wraiden_2Class)
    {
        if (Wraiden_2Class->objectName().isEmpty())
            Wraiden_2Class->setObjectName(QStringLiteral("Wraiden_2Class"));
        Wraiden_2Class->resize(600, 800);
        centralWidget = new QWidget(Wraiden_2Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 600, 775));
        graphicsView->setStyleSheet(QStringLiteral("border:0px;background:transparent;"));
        Wraiden_2Class->setCentralWidget(centralWidget);

        retranslateUi(Wraiden_2Class);

        QMetaObject::connectSlotsByName(Wraiden_2Class);
    } // setupUi

    void retranslateUi(QMainWindow *Wraiden_2Class)
    {
        Wraiden_2Class->setWindowTitle(QApplication::translate("Wraiden_2Class", "Wraiden_2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Wraiden_2Class: public Ui_Wraiden_2Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WRAIDEN_2_H
