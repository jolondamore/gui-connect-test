#include <QDebug>
#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "GuiManager.hpp"
#include "GuiObject.hpp"

GuiManager::GuiManager(QQmlApplicationEngine *engine, GuiObject *mainWindow) :
		m_pEngine(engine)
{
	registerContext(mainWindow);
	engine->rootContext()->setContextProperty("gui", mainWindow);
}

int GuiManager::registerContext(GuiObject *guiObj)
{
	int windowId = guiObj->getWindowId();
	if (windowId < 0 || windowId >= m_maxWindows) {
		qDebug() << "Invalid window ID " << windowId;
		return -1;
	}

	m_pGuiObj[windowId] = guiObj;
	connect( guiObj, &GuiObject::windowChanged,  this,
            &GuiManager::onWindowChanged );

	return 0;
}

void GuiManager::onWindowChanged(int windowId)
{
	GuiObject *gui = m_pGuiObj[windowId];
	if (gui == nullptr) {
		qDebug() << "No gui class found for window " << windowId;
		return;
	}

	m_pEngine->rootContext()->setContextProperty("gui", gui);
}
