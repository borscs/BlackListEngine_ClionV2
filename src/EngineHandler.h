#pragma once

#include <QString>
#include <QtDebug>
#include <QFileInfo>

#include "Engine.h"
#include "Utils.h"
#include "JsonHelper.h"

class EngineHandler
{
public:

	void scan(const QString &path);

private:

	Engine engine;
	utils::Utils utils;
	JsonHelper jsonHelper;

};