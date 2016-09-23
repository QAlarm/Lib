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
#include "Websocket.h"

Q_LOGGING_CATEGORY(qalarm_Websocket, "QAlarm.Websocket")
Websocket::Websocket(QObject *eltern) : QWebSocket(QString(),QWebSocketProtocol::VersionLatest,eltern)
{
	//FIXME doof geschrieben
	//connect(this,&QWebSocket::error,this,&Websocket::Socketfehler);
	connect(this,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(Socketfehler(QAbstractSocket::SocketError)));
	connect(this,&QWebSocket::sslErrors,this,&Websocket::SSL_Fehler);
}

void Websocket::Socketfehler(QAbstractSocket::SocketError fehler)
{
	Q_UNUSED(fehler);
	Q_EMIT(Fehler(errorString()));
}

void Websocket::SSL_Fehler(const QList<QSslError> &fehler)
{
	QString Fehler;
	for (auto SSL_Fehler:fehler)
		Fehler.append("\t").append(SSL_Fehler.errorString()).append("\r");
	qCDebug(qalarm_Websocket)<<tr("SSL Fehler:\r%1").arg(Fehler).toUtf8().constData();
}
