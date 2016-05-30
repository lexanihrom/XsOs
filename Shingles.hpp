#ifndef SHINGLES_HPP
#define SHINGLES_HPP
#include <QCoreApplication>
#include <time.h>
#include <QString>
#include <qstring.h>
#include <string>
#include <string.h>
#include <QByteArray>
#include <QCryptographicHash>
#include <QObject>
#include <QtMath>
using namespace std;

class Shingles : public QObject
{
    Q_OBJECT
public slots:
    QString cannonize(QString s);
    QStringList getshingles(QString s);
    double check(QStringList s,QStringList f);
    QString readFile(QString a);
};

#endif // SHINGLES_HPP
