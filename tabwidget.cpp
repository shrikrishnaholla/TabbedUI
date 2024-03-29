#include "tabwidget.h"

TabWidget::TabWidget(QWidget *parent):KTabWidget(parent)
{


    m_text = new KTextEdit(QString("Hello World!"));
    m_tab = NULL;
    QPicture pic;
    pic.load("kde.png");

    m_picture = new QLabel;
    m_picture->setPicture( pic );

    m_label = new QLabel(tr("Hello World"));

    addTab( m_text, QString("Tab &1") );
    addTab( m_picture, QString("Tab &2") );
    addTab( m_label, QString("Tab &3") );

    this->setHoverCloseButton(true);

    this->setMouseTracking(true);

    connect( this , SIGNAL( onTab1() ) , this, SLOT( showTab1Preview() ) );
    connect( this , SIGNAL( onTab2() ) , this, SLOT( showTab2Preview() ) );
    connect( this , SIGNAL( onTab3() ) , this, SLOT( showTab3Preview() ) );

}

TabWidget::~TabWidget()
{
    delete m_text;
    delete m_picture;
    delete m_label;

}

void TabWidget::mouseMoveEvent(QMouseEvent *event)
{
    KTabWidget::mouseMoveEvent(event);

    if( this->tabBar()->tabRect(0).contains( event->pos() )  )
        emit onTab1();

    else if( this->tabBar()->tabRect(1).contains( event->pos() )  )
        emit onTab2();

    else if( this->tabBar()->tabRect(2).contains( event->pos() )  )
        emit onTab3();

    else
    {
        if(m_tab != NULL)
        {
            delete m_tab;
            m_tab = NULL;
        }

    }

}

void TabWidget::leaveEvent(QMouseEvent *event)
{
    KTabWidget::leaveEvent(event);
    if( m_tab != NULL )
    {
        delete m_tab;
        m_tab = NULL;
    }
}

void TabWidget::showTab1Preview()
{
    if(this->currentIndex()!=0)
    {
        if(m_tab == NULL)
        {
            m_tab = new TabPreviewPopup(m_text);
            QPoint pos1(this->tabBar()->tabRect(0).x(), this->tabBar()->tabRect(0).y() + this->tabBar()->tabRect(0).height() );
            m_tab->show(mapToGlobal(pos1));
        }
    }
}

void TabWidget::showTab2Preview()
{
    if(this->currentIndex()!=1)
    {
        if(m_tab == NULL)
        {
            m_tab = new TabPreviewPopup(m_picture);
            QPoint pos2(this->tabBar()->tabRect(1).x(), this->tabBar()->tabRect(1).y() + this->tabBar()->tabRect(1).height() );
            m_tab->show(mapToGlobal(pos2));
        }
    }
}

void TabWidget::showTab3Preview()
{
    if(this->currentIndex()!=2)
    {
        if(m_tab == NULL)
        {
            m_tab = new TabPreviewPopup(m_label);
            QPoint pos3(this->tabBar()->tabRect(2).x(), this->tabBar()->tabRect(2).y() + this->tabBar()->tabRect(2).height() );
            m_tab->show(mapToGlobal(pos3));
        }
    }
}

#include "tabwidget.moc"
