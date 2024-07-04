#ifndef WINDOW_MANAGER_HPP
#define WINDOW_MANAGER_HPP

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "GuiObject.hpp"

class GuiManager : public QObject
{
	Q_OBJECT

public:
	explicit GuiManager(
		QQmlApplicationEngine *engine = nullptr,
		GuiObject *window = nullptr
	);
	int registerContext(GuiObject *window);

private:
	static const int m_maxWindows = 64;
	QQmlApplicationEngine *m_pEngine = nullptr;
	GuiObject *m_pGuiObj[m_maxWindows] = {nullptr};

private slots:
	void onWindowChanged(int windowId);
};

#endif /* WINDOW_MANAGER_HPP */
