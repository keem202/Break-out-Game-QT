/********************************************************************************
** Form generated from reading UI file 'levelmanager.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEVELMANAGER_H
#define UI_LEVELMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LevelManager
{
public:

    void setupUi(QWidget *LevelManager)
    {
        if (LevelManager->objectName().isEmpty())
            LevelManager->setObjectName("LevelManager");
        LevelManager->resize(400, 300);

        retranslateUi(LevelManager);

        QMetaObject::connectSlotsByName(LevelManager);
    } // setupUi

    void retranslateUi(QWidget *LevelManager)
    {
        LevelManager->setWindowTitle(QCoreApplication::translate("LevelManager", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LevelManager: public Ui_LevelManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEVELMANAGER_H
