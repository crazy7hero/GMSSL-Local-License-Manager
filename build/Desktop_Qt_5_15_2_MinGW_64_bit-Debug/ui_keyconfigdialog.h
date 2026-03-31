/********************************************************************************
** Form generated from reading UI file 'keyconfigdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEYCONFIGDIALOG_H
#define UI_KEYCONFIGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_KeyConfigDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_sm4;
    QHBoxLayout *horizontalLayout;
    QLineEdit *sm4KeyEdit;
    QPushButton *browseSm4Button;
    QLabel *label_private;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *privateKeyEdit;
    QPushButton *browsePrivateKeyButton;
    QLabel *label_public;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *publicKeyEdit;
    QPushButton *browsePublicKeyButton;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *saveButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *KeyConfigDialog)
    {
        if (KeyConfigDialog->objectName().isEmpty())
            KeyConfigDialog->setObjectName(QString::fromUtf8("KeyConfigDialog"));
        KeyConfigDialog->resize(600, 300);
        verticalLayout = new QVBoxLayout(KeyConfigDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(KeyConfigDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_sm4 = new QLabel(groupBox);
        label_sm4->setObjectName(QString::fromUtf8("label_sm4"));

        gridLayout->addWidget(label_sm4, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        sm4KeyEdit = new QLineEdit(groupBox);
        sm4KeyEdit->setObjectName(QString::fromUtf8("sm4KeyEdit"));

        horizontalLayout->addWidget(sm4KeyEdit);

        browseSm4Button = new QPushButton(groupBox);
        browseSm4Button->setObjectName(QString::fromUtf8("browseSm4Button"));

        horizontalLayout->addWidget(browseSm4Button);


        gridLayout->addLayout(horizontalLayout, 0, 1, 1, 1);

        label_private = new QLabel(groupBox);
        label_private->setObjectName(QString::fromUtf8("label_private"));

        gridLayout->addWidget(label_private, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        privateKeyEdit = new QLineEdit(groupBox);
        privateKeyEdit->setObjectName(QString::fromUtf8("privateKeyEdit"));

        horizontalLayout_2->addWidget(privateKeyEdit);

        browsePrivateKeyButton = new QPushButton(groupBox);
        browsePrivateKeyButton->setObjectName(QString::fromUtf8("browsePrivateKeyButton"));

        horizontalLayout_2->addWidget(browsePrivateKeyButton);


        gridLayout->addLayout(horizontalLayout_2, 1, 1, 1, 1);

        label_public = new QLabel(groupBox);
        label_public->setObjectName(QString::fromUtf8("label_public"));

        gridLayout->addWidget(label_public, 2, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        publicKeyEdit = new QLineEdit(groupBox);
        publicKeyEdit->setObjectName(QString::fromUtf8("publicKeyEdit"));

        horizontalLayout_3->addWidget(publicKeyEdit);

        browsePublicKeyButton = new QPushButton(groupBox);
        browsePublicKeyButton->setObjectName(QString::fromUtf8("browsePublicKeyButton"));

        horizontalLayout_3->addWidget(browsePublicKeyButton);


        gridLayout->addLayout(horizontalLayout_3, 2, 1, 1, 1);


        verticalLayout->addWidget(groupBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        saveButton = new QPushButton(KeyConfigDialog);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-weight: bold;\n"
"    padding: 8px 16px;\n"
"    background-color: #4CAF50;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #45a049;\n"
"}"));

        horizontalLayout_4->addWidget(saveButton);

        cancelButton = new QPushButton(KeyConfigDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    padding: 8px 16px;\n"
"    background-color: #f44336;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #d32f2f;\n"
"}"));

        horizontalLayout_4->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(KeyConfigDialog);

        QMetaObject::connectSlotsByName(KeyConfigDialog);
    } // setupUi

    void retranslateUi(QDialog *KeyConfigDialog)
    {
        KeyConfigDialog->setWindowTitle(QCoreApplication::translate("KeyConfigDialog", "\345\257\206\351\222\245\351\205\215\347\275\256", nullptr));
        groupBox->setTitle(QCoreApplication::translate("KeyConfigDialog", "\345\257\206\351\222\245\346\226\207\344\273\266\350\267\257\345\276\204\351\205\215\347\275\256", nullptr));
        label_sm4->setText(QCoreApplication::translate("KeyConfigDialog", "SM4\345\257\206\351\222\245\346\226\207\344\273\266:", nullptr));
        sm4KeyEdit->setPlaceholderText(QCoreApplication::translate("KeyConfigDialog", "sm4_key.bin \350\267\257\345\276\204", nullptr));
        browseSm4Button->setText(QCoreApplication::translate("KeyConfigDialog", "\351\207\215\346\226\260\351\205\215\347\275\256", nullptr));
        label_private->setText(QCoreApplication::translate("KeyConfigDialog", "SM2\347\247\201\351\222\245\346\226\207\344\273\266:", nullptr));
        privateKeyEdit->setPlaceholderText(QCoreApplication::translate("KeyConfigDialog", "sm2_private.pem \350\267\257\345\276\204", nullptr));
        browsePrivateKeyButton->setText(QCoreApplication::translate("KeyConfigDialog", "\351\207\215\346\226\260\351\205\215\347\275\256", nullptr));
        label_public->setText(QCoreApplication::translate("KeyConfigDialog", "SM2\345\205\254\351\222\245\346\226\207\344\273\266:", nullptr));
        publicKeyEdit->setPlaceholderText(QCoreApplication::translate("KeyConfigDialog", "sm2_public.pem \350\267\257\345\276\204", nullptr));
        browsePublicKeyButton->setText(QCoreApplication::translate("KeyConfigDialog", "\351\207\215\346\226\260\351\205\215\347\275\256", nullptr));
        saveButton->setText(QCoreApplication::translate("KeyConfigDialog", "\344\277\235\345\255\230\351\205\215\347\275\256", nullptr));
        cancelButton->setText(QCoreApplication::translate("KeyConfigDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class KeyConfigDialog: public Ui_KeyConfigDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEYCONFIGDIALOG_H
