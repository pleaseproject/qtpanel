#ifndef PANELAPPLICATION_H
#define PANELAPPLICATION_H

#include <QtCore/QSettings>                                                        
#include <QtCore/QTimer>
#if QT_VERSION >= 0x050000
#include <QApplication>
#include <QFont>
#else
#include <QtGui/QApplication>
#include <QtGui/QFont>
#endif

#include "iconloader.h"                                                            
#include "dpisupport.h"                                                            
#include "desktopapplications.h"                                                   
#include "ui_panelapplicationsettings.h"
#include "panelwindow.h"
#include "x11support.h"

class IconLoader;
class X11Support;
class DesktopApplications;

class PanelApplication: public QApplication
{
	Q_OBJECT
public:
	PanelApplication(int& argc, char** argv);
	~PanelApplication();

	static PanelApplication* instance()
	{
		return m_instance;
	}

	bool x11EventFilter(XEvent* event);

	void init();

	void reset();

	void setFontName(const QString& fontName);
	void setIconThemeName(const QString& iconThemeName);

	const QFont& panelFont() const
	{
		return m_panelFont;
	}

public slots:
	void showConfigurationDialog();

private slots:
	void reinit();

private:
	static PanelApplication* m_instance;
	IconLoader* m_iconLoader;
	X11Support* m_x11support;
	DesktopApplications* m_desktopApplications;

	QString m_fontName;
	QString m_iconThemeName;
	PanelWindow::Anchor m_verticalAnchor;
	QString m_defaultIconThemeName;
	QFont m_panelFont;
	QVector<PanelWindow*> m_panelWindows;
};

#endif
