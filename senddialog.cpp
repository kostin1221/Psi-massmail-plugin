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
   /* QVariant checked = index.data(Qt::CheckStateRole);

    QAbstractItemModel *mdl =  index.model();
    if (mdl->hasChildren(index)){
        for( int i = 0; i < mdl->rowCount() ; i++ ) {
            QModelIndex childIndex = mdl->index( i, 0, index );

            mdl->itemFromIndex(childIndex)->setData(checked, Qt::CheckStateRole);
          //  static_cast<QStandardItem *>( childIndex.internalPointer() )->setData(checked, Qt::CheckStateRole);
        }
    }*/

    //qDebug() << index.data(Qt::CheckStateRole);
    //qDebug() << index.data(Qt::EditRole);
}

