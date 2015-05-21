#include <panels.h>

//==============================
//      数据面板
//==============================
DataPanel::DataPanel(int x, int y, int w, int z)
{
    rect=QRectF(x,y,w,z);
    fps=0.0f;
    mEyePosition=mPosition=QVector3D(0,0,0);
}

QRectF DataPanel::boundingRect() const
{
    return rect;
}

void DataPanel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QColor color=QColor(0,0,0,50);
    painter->setPen(color);
    QBrush brush=QBrush(color);
    painter->setBrush(brush);
    painter->drawRect(boundingRect());
    painter->setPen(Qt::white);
    QRectF fpsRect(5,0,boundingRect().width()/2,20);
    QString fpsStr="FPS : "+QString::number(fps);
    painter->drawText(fpsRect,fpsStr);

    fpsRect=QRectF(boundingRect().width()/2+5,0,boundingRect().width()/2,20);
    QString rStr=QObject::tr("Radius : %1").arg(displayRadius);
    painter->drawText(fpsRect,rStr);

    QRectF posRect(5,20,100,80);
    QString posStr=QObject::tr("pos: \nX: %1\nY: %2\nZ: %3").arg(mPosition.x()).arg(mPosition.y()).arg(mPosition.z());
    painter->drawText(posRect,posStr);

    QRectF eyeRect(105,20,100,80);
    QString eyeStr=QObject::tr("pos: \nX: %1\nY: %2\nZ: %3").arg(mEyePosition.x()).arg(mEyePosition.y()).arg(mEyePosition.z());
    painter->drawText(eyeRect,eyeStr);
}

void DataPanel::setFps(int f)
{
    this->fps=f;
}

void DataPanel::setPosition(const QVector3D &pos, const QVector3D &ePos)
{
    this->mPosition=pos;
    this->mEyePosition=ePos;
}

void DataPanel::setDisplayRadius(int r)
{
    displayRadius=r;
}