#include "../src/ktechlab.h"
#include "config.h"
#include "docmanager.h"

#include <kaboutdata.h>
#include <kapplication.h>
#include <kcmdlineargs.h>
#include <klocalizedstring.h>

#include <qdebug.h>
#include <qtest.h>

static const char description[] =
    I18N_NOOP("An IDE for microcontrollers and electronics");

class KtlTestsAppFixture : public QObject {
    Q_OBJECT

public:
    KApplication *app;
    KTechlab *ktechlab;

private slots:
    void initTestCase() {
        int argc = 1;
        char argv0[] = "tests_app";
        char *argv[] = { argv0, NULL };

        KAboutData about(QByteArray("ktechlab"), QByteArray("ktechlab"), ki18n("KTechLab"), VERSION, ki18n(description),
                    KAboutData::License_GPL, ki18n("(C) 2003-2017, The KTechLab developers"),
                    KLocalizedString(), "https://userbase.kde.org/KTechlab", "ktechlab-devel@kde.org" );
        KCmdLineArgs::init(argc, argv, &about);
        app = new KApplication;
        ktechlab = new KTechlab;

    }
    void cleanupTestCase() {
        delete ktechlab;
        ktechlab = NULL;
        //delete app; // this crashes apparently
        app = NULL;
    }

    void testDocumentOpen() {
        DocManager::self()->closeAll();
        QCOMPARE( DocManager::self()->m_documentList.size(), 0);
        QFile exFile(SRC_EXAMPLES_DIR "/basic/resistors-series.circuit");
        KUrl exUrl(exFile.fileName());
        DocManager::self()->openURL(exUrl, NULL);
        QCOMPARE( DocManager::self()->m_documentList.size(), 1);
    }
};

QTEST_MAIN(KtlTestsAppFixture)
#include "tests_app.moc"