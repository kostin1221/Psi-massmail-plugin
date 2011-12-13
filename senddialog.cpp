#include "senddialog.h"
#include "ui_senddialog.h"

SendDialog::SendDialog(QWidget *parent, JidsViewModel *jidListModel, int account) :
    QDialog(parent),
    ui(new Ui::SendDialog)
{
    ui->setupUi(this);
    ui->jidsView->setModel(jidListModel);
    account_ = account;
}

SendDialog::~SendDialog()
{
    delete ui;
}

void SendDialog::jidListClick(const QModelIndex & index){
    QModelIndexList mdllist = index.model()->match( index.model()->index(0,0), Qt::CheckStateRole, 2, -1, Qt::MatchRecursive | Qt::MatchExactly );

    for (int i = 0; i < mdllist.size(); ++i) {
        //QStandardItem *item = static_cast<QStandardItem*>(mdllist.at(i).internalPointer());
        qDebug() << mdllist.at(i).data(Qt::UserRole);
        //qDebug() << item->data(Qt::DisplayRole);
      //  ui->jidsView->g

    }
}

void SendDialog::sendBtnClick(){

    QModelIndexList mdllist = ui->jidsView->model()->match(   ui->jidsView->model()->index(0,0), Qt::CheckStateRole, 2, -1, Qt::MatchRecursive | Qt::MatchExactly );

    for (int i = 0; i < mdllist.size(); ++i) {
        //QStandardItem *item = static_cast<QStandardItem*>(mdllist.at(i).internalPointer());
        QString jid = mdllist.at(i).data(Qt::UserRole).toString();
        if ( jid.contains( "@" ) ){
            sendMessage(account_, jid, ui->messageEditor->toPlainText(), ui->srochnoChk->checkState() == 2);
            //qDebug() << jid;
        }

    }
    close();
}
