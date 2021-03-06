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
#ifndef KONFIGURATION_H
#define KONFIGURATION_H

#include "qalarmlib_global.h"
#include <QtCore>

Q_DECLARE_LOGGING_CATEGORY(qalarm_Konfiguration)
class LIBSHARED_EXPORT Konfiguration: public QObject
{
	Q_OBJECT
	public:
		explicit Konfiguration(QObject *eltern);
		explicit Konfiguration(QObject *eltern, const QString &datei);
		const QVariant			WertHolen(const QString &name);
		const QVariant			WertHolen(const QString &name,const QVariant &standart);
		void					WertSetzen(const QString &name, const QVariant &wert);

	Q_SIGNALS:
		void					DateiNichtGefunden();
		void					Geladen();

	private Q_SLOTS:
		void					Laden();

	private:
		Q_DISABLE_COPY(Konfiguration)
		QSettings*				K_Konfig;
		QString					K_Datei;
		QHash<QString,QVariant>	K_Konfigpuffer;
		bool					K_Klientconfig;
};

#endif // KONFIGURATION_H
