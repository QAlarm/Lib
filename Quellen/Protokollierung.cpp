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
#include "Protokollierung.h"

Q_LOGGING_CATEGORY(qalarm_Protokollierung, "QAlarm.Protokollierung")
Protokollierung::Protokollierung(const int &ebene, QObject *eltern): QObject(eltern)
{
	QString Protokollfilter;
	switch (ebene)
	{
		case 1:
				Protokollfilter="*.critical=true\n*.warning=false\n*.info=false\n*.debug=false";
				break;
		case 2:
				Protokollfilter="*.critical=true\n*.warning=true\n*.info=false\n*.debug=false";
				break;
		case 3:
				Protokollfilter="*.critical=true\n*.warning=true\n*.info=true\n*.debug=false";
				break;
		case 4:
		default:
				Protokollfilter="*.critical=true\n*.warning=true\n*.info=true\n*.debug=true\n"\
								"qt.qpa.input.debug=false";
				break;
	}
	QLoggingCategory::setFilterRules(Protokollfilter);
	QLoggingCategory *Protokollkategorie=QLoggingCategory::defaultCategory();
	qCInfo(qalarm_Protokollierung)<<tr("Setzte Protokoll auf: \n\tKritisch: %1.\n\tWarnung: %2\n\tInfo: %3\n\tDebug: %4.").arg(Protokollkategorie->isCriticalEnabled())
																														   .arg(Protokollkategorie->isWarningEnabled())
																														   .arg(Protokollkategorie->isInfoEnabled())
																														   .arg(Protokollkategorie->isDebugEnabled()).toUtf8().constData();
}
