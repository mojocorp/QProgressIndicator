#include <QApplication>
#include <QtGui/QtGui>

#include "QProgressIndicator.h"

int main(int argc, char ** argv)
{
    QApplication app(argc, argv);

    QMainWindow * mw = new QMainWindow;

    QProgressIndicator* pi = new QProgressIndicator();

    QFrame* frame = new QFrame;

    QVBoxLayout* vbl = new QVBoxLayout;

    QPushButton* startPb = new QPushButton("start spin");
    QObject::connect(startPb, SIGNAL(clicked(bool)), pi, SLOT(startAnimation()));

    QPushButton* stopPb = new QPushButton("stop spin");
    QObject::connect(stopPb, SIGNAL(clicked(bool)), pi, SLOT(stopAnimation()));

    QSlider* delaySlider = new QSlider;
    delaySlider->setRange(0, 100);
    delaySlider->setValue(pi->animationDelay());
    delaySlider->setOrientation(Qt::Horizontal);
    QObject::connect(delaySlider, SIGNAL(valueChanged(int)), pi, SLOT(setAnimationDelay(int)));

    vbl->addWidget(startPb);
    vbl->addWidget(stopPb);
    vbl->addWidget(delaySlider);

    QHBoxLayout* hbl = new QHBoxLayout(frame);
    hbl->addWidget(pi);
    hbl->addLayout(vbl);

    pi->startAnimation();

    mw->setCentralWidget(frame);

    mw->show();

    return app.exec();
}
