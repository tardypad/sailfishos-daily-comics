/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifdef QT_QML_DEBUG
#include <QtQuick>
#endif

#include <sailfishapp.h>

#include <QDebug>
#include <QGuiApplication>
#include <QQuickView>
#include <QQmlContext>
#include <QtQml>

#include "src/ComicsModel.h"
#include "src/ComicProxy.h"
#include "src/Settings.h"

int main(int argc, char *argv[])
{
    qmlRegisterType<ComicProxy>("Comics", 1, 0, "Comic");
    qmlRegisterType<ComicsModel>("Comics", 1, 0, "ComicsModel");
    qmlRegisterType<Settings>("Settings", 1, 0, "Settings");

    QScopedPointer<QGuiApplication> app(SailfishApp::application(argc, argv));
    QScopedPointer<QQuickView> view(SailfishApp::createView());

    view->setSource(SailfishApp::pathTo("qml/harbour-dailycomics.qml"));
    view->show();

    return app->exec();
}

