#ifndef TABPREVIEWPOPUP_H
#define TABPREVIEWPOPUP_H

#include <KPassivePopup>
#include <QLabel>
#include <QVBoxLayout>
#include <QPalette>
#include <QWidget>

#include "tabwidget.h"

class TabPreviewPopup : public KPassivePopup
{
public:
    explicit TabPreviewPopup(QWidget *wid, QWidget *parent = 0);
    virtual ~TabPreviewPopup();

private:
    QLabel *m_thumbnail;

private:
    void setThumbnail(QPixmap &pixmap);
    void setPreview(QWidget *wid);
};

#endif // TABPREVIEWPOPUP_H
