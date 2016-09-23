/*
	Copyright (C) 2016 Frank Büttner qalarm@terrortux.de

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>
*/
#ifndef WEBSOCKET_H
#define WEBSOCKET_H

#include "qalarmlib_global.h"
#include <QtCore>
#include <QWebSocket>

Q_DECLARE_LOGGING_CATEGORY(qalarm_Websocket)
class LIBSHARED_EXPORT Websocket : public QWebSocket
{
	Q_OBJECT
	public:
		Websocket(QObject *eltern=Q_NULLPTR);

	Q_SIGNALS:
		void	Fehler(const QString &meldung);

	private Q_SLOTS:
		void	Socketfehler(QAbstractSocket::SocketError fehler);
		void	SSL_Fehler(const QList<QSslError> &fehler);
};

#endif // WEBSOCKET_H
