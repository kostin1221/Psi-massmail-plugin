
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
