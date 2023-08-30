#include <QApplication>
#include <QtWidgets>
#include "datasaver.h"
#include "mainwidget.h"
#include "tableasanawidget.h"
#include "searchasanawidget.h"
#include "asanadetailwidget.h"
#include "addasanawidget.h"
#include "langform.h"

// Splash Screen
void loadModules(QSplashScreen* splscr) {
    splscr->setPixmap(QPixmap(":/helper/helper_icons/splash.png"));
    splscr->show();
    // Delay
    QString msg = "";
    for (int i=1; i<51; i++){
        Sleep(50);
        msg = i<50 ? QObject::tr("Loading Asanas: ") + QString().number(i*2) + "%" : QObject::tr("Initializing...");
        splscr->showMessage(msg, Qt::AlignHCenter | Qt::AlignBottom, Qt::white);
    }
    qApp->processEvents();
    splscr->finish(new QLabel(QObject::tr("READY")));
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Setting StyleSheet
    QFile cssFile(":/style.qss");
    cssFile.open(QFile::ReadOnly);
    QString theStyle = QLatin1String(cssFile.readAll());
    app.setStyleSheet(theStyle);

    // Initial Lang Choosing Form
    LangForm* lf = new LangForm();
    lf->setWindowIcon(QIcon(QPixmap(":/helper/helper_icons/enso.png")));
    lf->show();

    // Main Part After Selected Lang
    auto lam = [&](bool lang){
        lf->close();

        QTranslator translator;
        translator.load(lang ? "ru.qm" : "en.qm", ".");
        app.installTranslator(&translator);

        QSplashScreen splash;
        loadModules(&splash);

        // Loading Modules
        DataSaver *database = new DataSaver(lang);
        MainWidget *mainWidget = nullptr;
        TableAsanaWidget* tableAsanaWid = nullptr;
        SearchAsanaWidget* searchAsanaWid = nullptr;
        AsanaDetailWidget* asanaDetailWid = nullptr;
        AddAsanaWidget* addAsasaWid = nullptr;
        // Bad Database Loading Status
        if (database->error()) {
            //qDebug() << "DB ERROR";
            delete database;
            app.exit();
        }
        // OK Database Loading Status
        else {
            tableAsanaWid = new TableAsanaWidget(*database);
            searchAsanaWid = new SearchAsanaWidget(*database, 4);
            asanaDetailWid = new AsanaDetailWidget(*database);
            addAsasaWid = new AddAsanaWidget(*database);
            mainWidget = new MainWidget(tableAsanaWid, asanaDetailWid, searchAsanaWid, addAsasaWid, lang);
            app.setWindowIcon(QIcon(QPixmap(":/helper/helper_icons/enso.png")));
        }
        // All Modules Are Active
        if (mainWidget) mainWidget->show();
    };

    // Bind Main Part To Init Screen
    lf->func = lam;

    return app.exec();
}
