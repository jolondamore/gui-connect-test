#ifndef GUI_OBJECT_HPP
#define GUI_OBJECT_HPP

#include <QObject>

class GuiObject : public QObject
{
	Q_OBJECT

protected:
	explicit GuiObject(int windowId) : m_windowId(windowId) {}
	Q_INVOKABLE void updateWindow(int windowId) { emit windowChanged(windowId); }

public:
	int getWindowId() const { return m_windowId; }

private:
	int m_windowId;

signals:
	void windowChanged(int windowId);
};

#endif /* GUI_OBJECT_HPP */
