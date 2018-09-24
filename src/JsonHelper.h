
#pragma once

#include <QJsonArray>
#include <QJsonDocument>
#include <QCoreApplication>
#include <QJsonObject>

class JsonHelper
{
public:
	QJsonObject recordObject;
	QJsonArray qJsonArray;

public:
	void clearJSON();
	void addToJSON(const QString &tag,const QString &data);
	void createNode();
	QJsonDocument createJSON(QJsonArray array);
	QJsonDocument createJSON();
	QJsonArray getQJsonArray() const;
};
