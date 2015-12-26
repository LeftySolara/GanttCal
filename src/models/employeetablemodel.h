#ifndef EMPLOYEETABLEMODEL_H
#define EMPLOYEETABLEMODEL_H

#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QModelIndex>
#include <QSqlQuery>


class EmployeeTableModel : public QSqlTableModel
{
public:
    EmployeeTableModel(QObject *parent = 0, QSqlDatabase database = QSqlDatabase());
    ~EmployeeTableModel();
//    QModelIndex index(int row, int column,const QModelIndex &parent = QModelIndex()) const;
//    QModelIndex parent(const QModelIndex &child) const;
//    int rowCount(const QModelIndex &parent = QModelIndex()) const;
//    int columnCount(const QModelIndex &parent = QModelIndex()) const;
//    QVariant data(const QModelIndex &idx, int role = Qt::DisplayRole) const;
//    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
//    Qt::ItemFlags flags(const QModelIndex &index) const;
//	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
//    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role = Qt::EditRole);
//    QSqlDatabase database() const;

private:
    QSqlDatabase db;
    QSqlQuery qry;
};

#endif // EMPLOYEETABLEMODEL_H
