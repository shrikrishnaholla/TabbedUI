#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <KTabWidget>
#include <KTextEdit>
#include <QtGui>
#include <QObject>
#include <QTabWidget>
#include <QTabBar>
#include <QRect>
#include <QCursor>
#include <QFrame>
#include <Qt>
#include <QHoverEvent>
#include <QPicture>
#include <QLabel>

#include "tabpreviewpopup.h"

class TabPreviewPopup;

class TabWidget: public KTabWidget
{
    Q_OBJECT
public:
    TabWidget(QWidget *parent=0);

    virtual ~TabWidget();

signals:

    void onTab1();
    void onTab2();
    void onTab3();

public slots:

    void showTab1Preview();
    void showTab2Preview();
    void showTab3Preview();


protected:
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void leaveEvent(QMouseEvent *event);

private:

    KTextEdit* m_text;
    QLabel* m_picture;
    QLabel* m_label;

    TabPreviewPopup *m_tab;

};

#endif // TABWIDGET_H
