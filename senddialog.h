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
    explicit SendDialog(QWidget *parent, JidsViewModel *jidListModel, int account);
    ~SendDialog();

private:
    Ui::SendDialog *ui;
    int account_;

private slots:
    void jidListClick(const QModelIndex & index);

signals:
    void sendMessage(int account, QString jid, QString message, bool imp);
};

#endif // SENDDIALOG_H
