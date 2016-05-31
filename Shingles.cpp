#include "Shingles.hpp"
#include <QFile>
#include <QDebug>

QCryptographicHash hash(QCryptographicHash::Md5);

using namespace std;

QString Shingles::cannonize(QString s)
{

    QString stopwords[5] = {"and","or","no","not","if"};
    QString stopsymbols[7] = {".",",","-",";",":","!","?"};
    for(int i = 0; i < 5; i++)
    {
        s.remove(stopwords[i],Qt::CaseSensitive);
    }

    for(int i = 0; i < 7; i++)
    {
        s.replace(stopsymbols[i],QString(" "));
    }
    return s;

}

QStringList Shingles::getshingles(QString s){
    QStringList list;
    QString F;
    QStringList L;
    list = s.split(" ");
    for (int i=0; i<(list.size()-1);i++){
        for (int j=0; j<2; j++){
            F.append(list[j+i]);
        }
          L.append(QCryptographicHash::hash((F.toUtf8()),QCryptographicHash::Md5).toHex());
        F.clear();

    }
    return L;
}

double Shingles::check(QStringList s,QStringList f){
    double g=0;
    double size1 = s.size();
    double size2 = f.size();
    if (s.size() > f.size()){
        for (int i=0; i<f.size(); i++){
            for (int k=0; k<f.size(); k++){
                if (s[i] == f[k]){
                    g=g+1;
                }
            }
        }
        return (g/size2) * 100;
    } else {
        for (int i=0; i<s.size(); i++){
            for (int k=0; k<s.size(); k++){
                if (s[i] == f[k]){
                    g=g+1;
                }
            }
        }
        return (g/size1) * 100;
    }
}

QString Shingles::readFile(QString a)
{
        QString b = a.section("/",3,-1);
        QFile file(b);
        QString fileContent;
        if ( file.open(QIODevice::ReadOnly) ) {
            QString line;
            QTextStream t( &file );
            do {
                line = t.readLine();
                fileContent += line;
             } while (!line.isNull());

            file.close();
        }
        return fileContent;
}
