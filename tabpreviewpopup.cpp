#include "tabpreviewpopup.h"

TabPreviewPopup::TabPreviewPopup( QWidget *wid, QWidget *parent ): KPassivePopup(parent), m_thumbnail(new QLabel(this))
{
    m_thumbnail->setAlignment(Qt::AlignHCenter);
    m_vb = new QVBoxLayout(this);
    m_vb->addWidget(m_thumbnail);
    this->setLayout(m_vb);
    layout()->setAlignment(Qt::AlignTop);
    layout()->setMargin(0);

    setPopupStyle(KPassivePopup::CustomStyle);

    QPalette p;
    // Use Tooltip's colors
    p.setColor(backgroundRole(), p.color(QPalette::ToolTipBase));
    p.setColor(QPalette::Base, p.color(QPalette::ToolTipBase));

    p.setColor(foregroundRole(), p.color(QPalette::ToolTipText));
    p.setColor(QPalette::Text, p.color(QPalette::ToolTipText));

    setPalette(p);

    // window flags and attributes
    setWindowFlags(Qt::ToolTip);
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowOpacity(style()->styleHint(QStyle::SH_ToolTipLabel_Opacity, 0, this) / 255.0);

    // margins
    const int margin = style()->pixelMetric(QStyle::PM_ToolTipLabelFrameWidth, 0, this);
    setContentsMargins(margin, margin, margin, margin);

    setPreview(wid);


}

TabPreviewPopup::~TabPreviewPopup()
{
    delete m_thumbnail;
    delete m_vb;
}


void TabPreviewPopup::setPreview(QWidget *wid)
{
    int w = (wid->parentWidget()->sizeHint().width() /4 ) - 5 ;
    int h = ( wid->size().height() / wid->size().width() );
    QPixmap thumb(wid->size());
    wid->render(&thumb);
    thumb = thumb.scaledToWidth(w, Qt:: SmoothTransformation);
    setThumbnail(thumb);

}

void TabPreviewPopup::setThumbnail(const QPixmap& pixmap)
{
    m_thumbnail->setPixmap(pixmap);
}


