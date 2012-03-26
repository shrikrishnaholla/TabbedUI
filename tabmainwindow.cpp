#include "tabmainwindow.h"

TabMainWindow::TabMainWindow(QWidget *parent) :
    KXmlGuiWindow(parent)
{
    tab = new TabWidget;
    setCentralWidget(tab);
    tab->show();
    setupGUI();
}

#include "tabmainwindow.moc"
