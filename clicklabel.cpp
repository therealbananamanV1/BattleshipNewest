#include "clicklabel.h"

myLabel::myLabel( const QString & text, QWidget * parent )
:QLabel(parent)
{
    connect( this, SIGNAL( clicked() ), this, SLOT( slotClicked() ) );
}

void myLabel::slotClicked()
{
    qDebug()<<"Clicked";
}

void myLabel::mousePressEvent ( QMouseEvent * event )
{
    emit clicked();
}
