#include "JsonHelper.h"

#include <QVariant>

void JsonHelper::clearJSON()
{
	recordObject = QJsonObject();
}

void JsonHelper::addToJSON(const QString &tag, const QString &data)
{

	QVariant qvariant(data);
	recordObject.insert(tag,QJsonValue::fromVariant(qvariant));
}

void JsonHelper::createNode()
{

}

QJsonDocument JsonHelper::createJSON(QJsonArray array)
{
	QJsonObject jsonObject;
	jsonObject.insert("result", array);
	QJsonDocument jsonDocument(jsonObject);
	return jsonDocument;
}

QJsonDocument JsonHelper::createJSON()
{
	QJsonObject jsonObject;
	jsonObject.insert("result", recordObject);
	QJsonDocument jsonDocument(jsonObject);
	return jsonDocument;
}

QJsonArray JsonHelper::getQJsonArray() const
{
	return qJsonArray;
}
