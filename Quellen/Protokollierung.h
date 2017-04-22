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
#ifndef PROTOKOLLIERUNG_H
#define PROTOKOLLIERUNG_H

#include "qalarmlib_global.h"
#include <QtCore>

Q_DECLARE_LOGGING_CATEGORY(qalarm_Protokollierung)
class LIBSHARED_EXPORT Protokollierung : public QObject
{
	Q_OBJECT
	public:
		explicit Protokollierung(const int &ebene,QObject* eltern=Q_NULLPTR);
#ifdef JOURNAL_NUTZEN
		static void Journal(QtMsgType type, const QMessageLogContext &kontext, const QString &meldung);
#endif

	private:
		Q_DISABLE_COPY(Protokollierung)
};

#endif // PROTOKOLLIERUNG_H
