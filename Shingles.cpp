#include "Shingles.hpp"



Shingles::Shingles():
    QObject()
{

}


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

QString Shingles::check(QStringList s,QStringList f){
    double g=0;
    double size1 = s.length();
    double size2 = f.size()+1;
    if (s.size() > f.size()){
        for (int i=0; i<f.size(); i++){
            for (int k=0; k<f.size(); k++){
                if (s[i] == f[k]){
                    g=g+1;
                }
            }
        }
        return QString::number((g/size2) * 100);
    } else {
        for (int i=0; i<s.size(); i++){
            for (int k=0; k<s.size(); k++){
                if (s[i] == f[k]){
                    g=g+1;
                }
            }
        }
        return QString::number((g/size1) * 100);
    }
}
