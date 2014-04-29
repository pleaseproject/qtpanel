#ifndef APPLICATIONSMENUAPPLET_H
#define APPLICATIONSMENUAPPLET_H

#include <QtCore/QList>
#include <QtCore/QMap>
#if QT_VERSION >= 0x050000
#include <QAction>
#include <QStyleFactory>
#else
#include <QtGui/QAction>
#include <QtGui/QPlastiqueStyle>
#endif
#include "applet.h"

#if QT_VERSION < 0x050000
class ApplicationsMenuStyle: public QPlastiqueStyle
{
	Q_OBJECT
public:
	int pixelMetric(PixelMetric metric, const QStyleOption* option, const QWidget* widget) const;
};
#endif

class SubMenu
{
public:
	SubMenu()
	{
	}

	SubMenu(QMenu* parent, const QString& title, const QString& category, const QString& icon);

	QMenu* menu()
	{
		return m_menu;
	}

	const QString& category() const
	{
		return m_category;
	}

private:
	QMenu* m_menu;
	QString m_category;
};

class TextGraphicsItem;
class DesktopApplication;

class ApplicationsMenuApplet: public Applet
{
	Q_OBJECT
public:
	ApplicationsMenuApplet(PanelWindow* panelWindow);
	~ApplicationsMenuApplet();

	bool init();
	QSize desiredSize();
	void clicked();

protected:
	void layoutChanged();
	bool isHighlighted();

private slots:
	void actionTriggered();
	void applicationUpdated(const DesktopApplication& app);
	void applicationRemoved(const QString& path);

private:
#if QT_VERSION < 0x050000
    ApplicationsMenuStyle m_style;
#endif
	TextGraphicsItem* m_textItem;
	bool m_menuOpened;
	QMenu* m_menu;
	QList<SubMenu> m_subMenus;
	QMap<QString, QAction*> m_actions;
};

#endif
