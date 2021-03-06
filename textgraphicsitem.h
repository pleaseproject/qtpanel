/* Copyright (C) 2014 Leslie Zhai <xiang.zhai@i-soft.com.cn> */

#ifndef TEXTGRAPHICSITEM_H
#define TEXTGRAPHICSITEM_H

#include <QtGui/QColor>
#include <QtGui/QFont>
#if QT_VERSION >= 0x050000
#include <QGraphicsItem>
#else
#include <QtGui/QGraphicsItem>
#endif

class TextGraphicsItem: public QGraphicsItem
{
public:
	TextGraphicsItem(QGraphicsItem* parent = NULL);
	~TextGraphicsItem();

	void setColor(const QColor& color);
	void setFont(const QFont& font);
	void setText(const QString& text);
    void setImage(const QImage& image);

	const QFont& font() const { return m_font; }

	QRectF boundingRect() const;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);

private:
	QColor m_color;
	QFont m_font;
	QString m_text;
    QImage m_image;
};

#endif
