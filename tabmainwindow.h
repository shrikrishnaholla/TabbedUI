#ifndef TABMAINWINDOW_H
#define TABMAINWINDOW_H

#include<KXmlGuiWindow>
#include <QtGui>
#include <QObject>

//#include "tabwidget.cpp"
#include "tabwidget.h"
#include <KTabWidget>
class TabMainWindow : public KXmlGuiWindow
{
    Q_OBJECT
public:
    explicit TabMainWindow(QWidget *parent = 0);

private:
    TabWidget *tab;


signals:

public slots:

};

#endif // TABMAINWINDOW_H
