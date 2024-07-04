#ifndef SAMPLE_WINDOW_HPP
#define SAMPLE_WINDOW_HPP

#include <QString>
#include "GuiObject.hpp"

class SampleWindow : public GuiObject
{
	Q_OBJECT
	Q_PROPERTY(QString text MEMBER m_text NOTIFY textChanged)

public:
	explicit SampleWindow(int windowId = 0) : GuiObject(windowId) {}
	void setText(const QString &text) { m_text = text; emit textChanged(); }

private:
	QString m_text;

signals:
	void textChanged();
};

#endif /* SAMPLE_WINDOW_HPP */
