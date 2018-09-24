#include "EngineHandler.h"

void EngineHandler::scan(const QString &path)
{
	switch (engine.fileScan(path)) {
		case static_cast<int>(utils::Verdict ::Clear):
			jsonHelper.clearJSON();
			jsonHelper.addToJSON("file_name", path);
			jsonHelper.addToJSON("verdict", "No threat detected");
			jsonHelper.createNode();
			utils.qStdOut() << jsonHelper.createJSON().toJson(QJsonDocument::Indented);
			break;
		case static_cast<int>(utils::Verdict ::Threat):
			jsonHelper.clearJSON();
			jsonHelper.addToJSON("file_name", path);
			jsonHelper.addToJSON("verdict", "blocked");
			jsonHelper.createNode();
			utils.qStdOut() << jsonHelper.createJSON().toJson(QJsonDocument::Indented);
			break;
		case static_cast<int>(utils::Verdict ::Error):
			jsonHelper.clearJSON();
			jsonHelper.addToJSON("file_name", path);
			jsonHelper.addToJSON("error", "file not found!");
			jsonHelper.createNode();
			utils.qStdOut() << jsonHelper.createJSON().toJson(QJsonDocument::Indented);
			break;
		default:
			break;
	}
}
void EngineHandler::generate( QString path )
{
	jsonHelper.clearJSON();
	jsonHelper.addToJSON("file_name", path);
	jsonHelper.addToJSON("md5", engine.fileHashGenerate(path, QCryptographicHash::Md5));
	jsonHelper.addToJSON("sha1", engine.fileHashGenerate(path, QCryptographicHash::Sha1));
	jsonHelper.addToJSON("sha256", engine.fileHashGenerate(path, QCryptographicHash::Sha256));
	jsonHelper.createNode();
	utils.qStdOut() << jsonHelper.createJSON().toJson(QJsonDocument::Indented);
}

