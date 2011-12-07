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
        QStandardItem *item = static_cast<QStandardItem*>(mdllist.at(i).internalPointer());
        qDebug() << item->data(Qt::DisplayRole);
      //  ui->jidsView->g

        //    cout << "Found Jane at position " << i << endl;
    }
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

