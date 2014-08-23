#ifndef ST_OPERATIONS_H
#define ST_OPERATIONS_H

#include <QObject>
#include <QVector>
#include <QSqlDatabase>
#include "st_message.h"
namespace ParkinglotsSvr{



	class st_operations : public QObject
	{
		Q_OBJECT
	public:
		explicit st_operations(QSqlDatabase * db, QObject *parent = 0);
	protected:
		QSqlDatabase * m_pDb;
		QString hex2ascii(const quint8 ptr[], int sz);
	public:
		quint8 regisit_host(QString serialnum, quint32 * host_id );
		quint8 login_host(QString serialnum, quint32 host_id );
		bool   insert_device_table (int nItems, QVector<QString> & vec_dev_names,QVector<QString> & vec_dev_nos,QVector<QString> & vec_dev_ids, quint32 macid);
		bool   insert_mac_table(quint32 macID, const QString & macSerial,const stMsg_SendMacInfoReq_internal & info);
	};
}

#endif // ST_OPERATIONS_H
