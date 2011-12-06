/********************************************************************************
** Form generated from reading UI file 'options.ui'
**
** Created: Sat Nov 26 18:09:51 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONS_H
#define UI_OPTIONS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "view.h"

QT_BEGIN_NAMESPACE

class Ui_Options
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QTextEdit *te_question;
    QLabel *label_2;
    QLineEdit *le_answer;
    QLabel *label_3;
    QTextEdit *te_congratulation;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *cb_enable_muc;
    QGroupBox *gb_affiliations;
    QHBoxLayout *horizontalLayout;
    QCheckBox *cb_owner;
    QCheckBox *cb_admin;
    QCheckBox *cb_member;
    QCheckBox *cb_none;
    QSpacerItem *horizontalSpacer_4;
    QGroupBox *gb_rules;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *cb_moderator;
    QCheckBox *cb_participant;
    QCheckBox *cb_visitor;
    QSpacerItem *horizontalSpacer_5;
    QCheckBox *cb_block_privates;
    QCheckBox *cb_send_block_all_mes;
    QTextEdit *te_muc;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *le_number;
    QPushButton *pb_view;
    QPushButton *pb_reset;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QSpinBox *sb_times;
    QLabel *label_6;
    QLabel *label_7;
    QSpinBox *sb_reset;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *cb_log_history;
    Viewer *tv_rules;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pb_add;
    QPushButton *pb_del;
    QCheckBox *cb_default_act;
    QLabel *wiki;

    void setupUi(QWidget *Options)
    {
        if (Options->objectName().isEmpty())
            Options->setObjectName(QString::fromUtf8("Options"));
        Options->resize(600, 497);
        verticalLayout = new QVBoxLayout(Options);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(Options);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tab->sizePolicy().hasHeightForWidth());
        tab->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        te_question = new QTextEdit(tab);
        te_question->setObjectName(QString::fromUtf8("te_question"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(te_question->sizePolicy().hasHeightForWidth());
        te_question->setSizePolicy(sizePolicy1);
        te_question->setMinimumSize(QSize(0, 0));

        verticalLayout_2->addWidget(te_question);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        le_answer = new QLineEdit(tab);
        le_answer->setObjectName(QString::fromUtf8("le_answer"));

        verticalLayout_2->addWidget(le_answer);

        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        te_congratulation = new QTextEdit(tab);
        te_congratulation->setObjectName(QString::fromUtf8("te_congratulation"));
        sizePolicy1.setHeightForWidth(te_congratulation->sizePolicy().hasHeightForWidth());
        te_congratulation->setSizePolicy(sizePolicy1);
        te_congratulation->setMaximumSize(QSize(16777215, 70));

        verticalLayout_2->addWidget(te_congratulation);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        cb_enable_muc = new QCheckBox(tab_2);
        cb_enable_muc->setObjectName(QString::fromUtf8("cb_enable_muc"));

        verticalLayout_3->addWidget(cb_enable_muc);

        gb_affiliations = new QGroupBox(tab_2);
        gb_affiliations->setObjectName(QString::fromUtf8("gb_affiliations"));
        horizontalLayout = new QHBoxLayout(gb_affiliations);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        cb_owner = new QCheckBox(gb_affiliations);
        cb_owner->setObjectName(QString::fromUtf8("cb_owner"));

        horizontalLayout->addWidget(cb_owner);

        cb_admin = new QCheckBox(gb_affiliations);
        cb_admin->setObjectName(QString::fromUtf8("cb_admin"));

        horizontalLayout->addWidget(cb_admin);

        cb_member = new QCheckBox(gb_affiliations);
        cb_member->setObjectName(QString::fromUtf8("cb_member"));

        horizontalLayout->addWidget(cb_member);

        cb_none = new QCheckBox(gb_affiliations);
        cb_none->setObjectName(QString::fromUtf8("cb_none"));

        horizontalLayout->addWidget(cb_none);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout_3->addWidget(gb_affiliations);

        gb_rules = new QGroupBox(tab_2);
        gb_rules->setObjectName(QString::fromUtf8("gb_rules"));
        horizontalLayout_2 = new QHBoxLayout(gb_rules);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        cb_moderator = new QCheckBox(gb_rules);
        cb_moderator->setObjectName(QString::fromUtf8("cb_moderator"));

        horizontalLayout_2->addWidget(cb_moderator);

        cb_participant = new QCheckBox(gb_rules);
        cb_participant->setObjectName(QString::fromUtf8("cb_participant"));

        horizontalLayout_2->addWidget(cb_participant);

        cb_visitor = new QCheckBox(gb_rules);
        cb_visitor->setObjectName(QString::fromUtf8("cb_visitor"));

        horizontalLayout_2->addWidget(cb_visitor);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        verticalLayout_3->addWidget(gb_rules);

        cb_block_privates = new QCheckBox(tab_2);
        cb_block_privates->setObjectName(QString::fromUtf8("cb_block_privates"));

        verticalLayout_3->addWidget(cb_block_privates);

        cb_send_block_all_mes = new QCheckBox(tab_2);
        cb_send_block_all_mes->setObjectName(QString::fromUtf8("cb_send_block_all_mes"));

        verticalLayout_3->addWidget(cb_send_block_all_mes);

        te_muc = new QTextEdit(tab_2);
        te_muc->setObjectName(QString::fromUtf8("te_muc"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(te_muc->sizePolicy().hasHeightForWidth());
        te_muc->setSizePolicy(sizePolicy2);

        verticalLayout_3->addWidget(te_muc);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_4 = new QVBoxLayout(tab_3);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(tab_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        le_number = new QLineEdit(tab_3);
        le_number->setObjectName(QString::fromUtf8("le_number"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(le_number->sizePolicy().hasHeightForWidth());
        le_number->setSizePolicy(sizePolicy3);
        le_number->setMinimumSize(QSize(0, 0));
        le_number->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_3->addWidget(le_number);

        pb_view = new QPushButton(tab_3);
        pb_view->setObjectName(QString::fromUtf8("pb_view"));

        horizontalLayout_3->addWidget(pb_view);

        pb_reset = new QPushButton(tab_3);
        pb_reset->setObjectName(QString::fromUtf8("pb_reset"));

        horizontalLayout_3->addWidget(pb_reset);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout_4->addLayout(horizontalLayout_3);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_5 = new QLabel(tab_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        sb_times = new QSpinBox(tab_3);
        sb_times->setObjectName(QString::fromUtf8("sb_times"));
        sb_times->setMaximumSize(QSize(60, 16777215));

        gridLayout->addWidget(sb_times, 0, 1, 1, 1);

        label_6 = new QLabel(tab_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 0, 2, 1, 1);

        label_7 = new QLabel(tab_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_7, 1, 0, 1, 1);

        sb_reset = new QSpinBox(tab_3);
        sb_reset->setObjectName(QString::fromUtf8("sb_reset"));
        sb_reset->setMaximumSize(QSize(60, 16777215));

        gridLayout->addWidget(sb_reset, 1, 1, 1, 1);

        label_8 = new QLabel(tab_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 1, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 3, 1, 1);


        verticalLayout_4->addLayout(gridLayout);

        cb_log_history = new QCheckBox(tab_3);
        cb_log_history->setObjectName(QString::fromUtf8("cb_log_history"));

        verticalLayout_4->addWidget(cb_log_history);

        tv_rules = new Viewer(tab_3);
        tv_rules->setObjectName(QString::fromUtf8("tv_rules"));
        sizePolicy.setHeightForWidth(tv_rules->sizePolicy().hasHeightForWidth());
        tv_rules->setSizePolicy(sizePolicy);

        verticalLayout_4->addWidget(tv_rules);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        pb_add = new QPushButton(tab_3);
        pb_add->setObjectName(QString::fromUtf8("pb_add"));

        horizontalLayout_4->addWidget(pb_add);

        pb_del = new QPushButton(tab_3);
        pb_del->setObjectName(QString::fromUtf8("pb_del"));

        horizontalLayout_4->addWidget(pb_del);


        verticalLayout_4->addLayout(horizontalLayout_4);

        cb_default_act = new QCheckBox(tab_3);
        cb_default_act->setObjectName(QString::fromUtf8("cb_default_act"));

        verticalLayout_4->addWidget(cb_default_act);

        tabWidget->addTab(tab_3, QString());

        verticalLayout->addWidget(tabWidget);

        wiki = new QLabel(Options);
        wiki->setObjectName(QString::fromUtf8("wiki"));
        wiki->setOpenExternalLinks(true);

        verticalLayout->addWidget(wiki);


        retranslateUi(Options);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Options);
    } // setupUi

    void retranslateUi(QWidget *Options)
    {
        Options->setWindowTitle(QApplication::translate("Options", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Options", "Question:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Options", "Answer:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Options", "Congratulation:", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Options", "Main", 0, QApplication::UnicodeUTF8));
        cb_enable_muc->setText(QApplication::translate("Options", "Enable Stop Spam for private messages in MUC", 0, QApplication::UnicodeUTF8));
        gb_affiliations->setTitle(QApplication::translate("Options", "Enable Stop Spam for affiliations:", 0, QApplication::UnicodeUTF8));
        cb_owner->setText(QApplication::translate("Options", "Owner", 0, QApplication::UnicodeUTF8));
        cb_admin->setText(QApplication::translate("Options", "Admin", 0, QApplication::UnicodeUTF8));
        cb_member->setText(QApplication::translate("Options", "Member", 0, QApplication::UnicodeUTF8));
        cb_none->setText(QApplication::translate("Options", "None", 0, QApplication::UnicodeUTF8));
        gb_rules->setTitle(QApplication::translate("Options", "Enable Stop Spam for roles:", 0, QApplication::UnicodeUTF8));
        cb_moderator->setText(QApplication::translate("Options", "Moderator", 0, QApplication::UnicodeUTF8));
        cb_participant->setText(QApplication::translate("Options", "Participant", 0, QApplication::UnicodeUTF8));
        cb_visitor->setText(QApplication::translate("Options", "Visitor", 0, QApplication::UnicodeUTF8));
        cb_block_privates->setText(QApplication::translate("Options", "Block all private messages", 0, QApplication::UnicodeUTF8));
        cb_send_block_all_mes->setText(QApplication::translate("Options", "Send message:", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Options", "MUC", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Options", "Number of blocked stanzas:", 0, QApplication::UnicodeUTF8));
        pb_view->setText(QApplication::translate("Options", "View Log", 0, QApplication::UnicodeUTF8));
        pb_reset->setText(QApplication::translate("Options", "Reset", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Options", "Send maximum", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Options", "times", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Options", "Timeout to reset counter:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Options", "min.", 0, QApplication::UnicodeUTF8));
        cb_log_history->setText(QApplication::translate("Options", "Log blocked messages to contact's history", 0, QApplication::UnicodeUTF8));
        pb_add->setText(QApplication::translate("Options", "Add", 0, QApplication::UnicodeUTF8));
        pb_del->setText(QApplication::translate("Options", "Del", 0, QApplication::UnicodeUTF8));
        cb_default_act->setText(QApplication::translate("Options", "Disable stopspam, if don't match any rule above\n"
"(does not work for muc private messages)", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Options", "Misc", 0, QApplication::UnicodeUTF8));
        wiki->setText(QApplication::translate("Options", "<a href=\"http://psi-plus.com/wiki/plugins#stop_spam_plugin\">Wiki (Online)</a>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Options: public Ui_Options {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONS_H
