#ifndef SENDDIALOG_H
#define SENDDIALOG_H

#include <QDialog>
#include <QDebug>
#include <QStandardItemModel>

#include "jiditemmodel.h"

namespace Ui {
    class SendDialog;
}

class SendDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SendDialog(QWidget *parent, JidsViewModel *jidListModel);
    ~SendDialog();

private:
    Ui::SendDialog *ui;

private slots:
    void jidListClick(const QModelIndex & index);
};

#endif // SENDDIALOG_H
