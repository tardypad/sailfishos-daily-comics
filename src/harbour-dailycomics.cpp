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
#include "FavoriteComicsModel.h"
#include "src/Comic.h"
#include "src/ComicProxy.h"
#include "src/Settings.h"

int main(int argc, char *argv[])
{
    qmlRegisterType<ComicProxy>("harbour.dailycomics.Comics", 1, 0, "ComicProxy");
    qmlRegisterType<Comic>();
    qmlRegisterType<ComicsModel>("harbour.dailycomics.Comics", 1, 0, "ComicsModel");
    qmlRegisterType<FavoriteComicsModel>("harbour.dailycomics.Comics", 1, 0, "FavoriteComicsModel");

    QScopedPointer<QGuiApplication> app(SailfishApp::application(argc, argv));
    QScopedPointer<QQuickView> view(SailfishApp::createView());

    app->setApplicationVersion(QString(APP_VERSION));

    QQmlContext* context = view->rootContext();

    QScopedPointer<Settings> settings(Settings::instance());
    context->setContextProperty("_settings", settings.data());

    view->setSource(SailfishApp::pathTo("qml/harbour-dailycomics.qml"));
    view->show();

    return app->exec();
}

