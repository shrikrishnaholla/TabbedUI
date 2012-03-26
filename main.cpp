#include <cstdlib>

#include <KApplication>
#include <KAboutData>
#include <KCmdLineArgs>
#include <KMessageBox>
#include <KLocale>

#include "tabmainwindow.h"

//class TabMainWindow;
//#include "tabmainwindow.cpp"

//#include "tabwidget.h"
//#include "tabwidget.cpp"

int main (int argc, char *argv[])
{
    KAboutData aboutData(
                         // The program name used internally.
                         "NewTab",
                         // The message catalog name
                         // If null, program name is used instead.
                         0,
                         // A displayable program name string.
                         ki18n("Tab Widget"),
                         // The program version string.
                         "1.0",
                         // Short description of what the app does.
                         ki18n("Displays a Tabbed Window"),
                         // The license this code is released under
                         KAboutData::License_GPL,
                         // Copyright Statement
                         ki18n("(c) 2012"),
                         // Optional text shown in the About box.
                         // Can contain any information desired.
                         ki18n("A small GUI application built to try and implement a tabbed window which shows previews of it's tabs when they are hovered on"),
                         // The program homepage string.
                         "http://kde.org/",
                         // The bug report email address
                         "submit@bugs.kde.org");

    KCmdLineArgs::init( argc, argv, &aboutData );
    KApplication app;

    TabMainWindow* tabber = new TabMainWindow;
    tabber->show();

//    TabWidget* tab = new TabWidget();
//    tab->show();

    return app.exec();
}
