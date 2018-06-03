/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2011 Morgan Leborgne
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <QApplication>
#include <QFrame>
#include <QMainWindow>
#include <QPushButton>
#include <QSlider>
#include <QVBoxLayout>

#include "QProgressIndicator.h"

int
main(int argc, char** argv)
{
    QApplication app(argc, argv);

    QMainWindow* mw = new QMainWindow;

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
