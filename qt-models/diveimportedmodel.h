#ifndef DIVEIMPORTEDMODEL_H
#define DIVEIMPORTEDMODEL_H

#include <QAbstractTableModel>
#include "core/dive.h"

class DiveImportedModel : public QAbstractTableModel
{
	Q_OBJECT
public:
	DiveImportedModel(QObject *o);
    void setDiveTable(struct dive_table *table);
	int columnCount(const QModelIndex& index = QModelIndex()) const;
	int rowCount(const QModelIndex& index = QModelIndex()) const;
	QVariant data(const QModelIndex& index, int role) const;
	QVariant headerData(int section, Qt::Orientation orientation, int role) const;
	void setImportedDivesIndexes(int first, int last);
	Qt::ItemFlags flags(const QModelIndex &index) const;
	void clearTable();

public
slots:
	void changeSelected(QModelIndex clickedIndex);
	void selectAll();
	void selectNone();

private:
	int firstIndex;
	int lastIndex;
	bool *checkStates;
    struct dive_table *diveTable;
};

#endif
