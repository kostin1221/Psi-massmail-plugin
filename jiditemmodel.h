#ifndef JIDITEMMODEL_H
#define JIDITEMMODEL_H

#include <QModelIndex>
#include <QStandardItem>
#include <QStandardItemModel>

class JidsViewModel : public QStandardItemModel
{
    Q_OBJECT
public:
    JidsViewModel(QObject *parent = 0);
    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);
    QString findNameByJid(QString jid);


signals:

public slots:

};

#endif // JIDITEMMODEL_H
