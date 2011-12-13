
#include "jiditemmodel.h"

JidsViewModel::JidsViewModel(QObject *parent)
    :QStandardItemModel(parent)
{

}

//При активизации чекбокса - у всех детей чекбокс выставляется такимже как у родителя
bool JidsViewModel::setData(const QModelIndex & index, const QVariant & value, int role)
{
    if (role == Qt::CheckStateRole) {
        QStandardItem *item = itemFromIndex(index);
        for( int i = 0; i < item->rowCount() ; i++ )
        {
            QStandardItem *childItem = item->child(i);
            setData(childItem->index(), value, role);
        }
    }

    return QStandardItemModel::setData(index, value, role);
}

QString JidsViewModel::findNameByJid(QString jid){
    QModelIndexList mdllist = match( index(0,0), Qt::UserRole, jid, -1, Qt::MatchRecursive | Qt::MatchExactly );

    if ( mdllist.size() > 0) {
        QString name = mdllist.at(0).data(Qt::DisplayRole).toString();
        return name;
    }    else return jid; //QString::fromUtf8("неизвестного получателя");
}
