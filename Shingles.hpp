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
public:
    Shingles();
public slots:
    QString cannonize(QString s);
    QStringList getshingles(QString s);
    QString check(QStringList s,QStringList f);
};

#endif // SHINGLES_HPP
