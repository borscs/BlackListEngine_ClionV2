#include <QtCore/QCoreApplication>
#include <QtCore/QCommandLineParser>
#include <QFileInfo>

#include "EngineHandler.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	QCoreApplication::setApplicationName("Blacklist Engine");
	QCoreApplication::setApplicationVersion("1.1.0");

	EngineHandler engineHandler;


	QCommandLineParser parser;
	parser.setApplicationDescription(QCoreApplication::translate("main",
																 "Given a file or folder, the application checks whether it was compromised or not."));
	parser.addHelpOption();
	parser.addVersionOption();

	QCommandLineOption scanOption(QStringList() << "s" << "scan",
								  QCoreApplication::translate("main", "Find the given file's hash in the database."),
								  QCoreApplication::translate("main", "file"),
								  "");
	parser.addOption(scanOption);

	QCommandLineOption lookupOption(QStringList() << "l" << "lookup",
									QCoreApplication::translate("main", "Lookup a hash in the database."),
									QCoreApplication::translate("main", "hash"),
									"");
	parser.addOption(lookupOption);

	QCommandLineOption generateOption(QStringList() << "g" << "generate",
									  QCoreApplication::translate("main", "Generate a file's hash."),
									  QCoreApplication::translate("main", "file"),
									  "");
	parser.addOption(generateOption);

	QCommandLineOption scanFolderOption(QStringList() << "f" << "folder",
										QCoreApplication::translate("main", "Scan files in a folder"),
										QCoreApplication::translate("main", "folder"),
										"");
	parser.addOption(scanFolderOption);

	parser.process(a);

	if (parser.isSet(scanOption)) {

		engineHandler.scan(parser.value(scanOption));

		return 0;
	}
	else if (parser.isSet(lookupOption)) {


		return 0;
	}
	else if (parser.isSet(generateOption)) {



		return 0;
	}
	else if (parser.isSet(scanFolderOption)) {


		return 0;
	}

	parser.showHelp();
}