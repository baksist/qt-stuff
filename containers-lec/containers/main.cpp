#include "mainwindow.h"

#include <QApplication>
#include <QVector>
#include <QStack>
#include <QQueue>
#include <QDebug>
#include <QSet>

struct Student
{
    int id;
    QString fio;

    bool operator < (const Student &s) {
        return id < s.id;
    }
};

uint qHash(const Student &s)
{
    return qHash(s.id) + qHash(s.fio);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QVector<int> v {3,3,5,8,9};

    v.reserve(10); // size() = 0
    v.resize(10);  // size() = 10

    QVector<Student> v2;

    qDebug() << v[0] << v.at(1);
    v.append(12);
    v.insert(3, 5);
    int findIndex = v.indexOf(10);
    v.removeAt(0);

    QList<Student> l1;
    QList<float> l2;

    QStack<int> s1;
    QQueue<int> q1;

    QMap<int, Student> m1;
    m1.insert(1, Student());
    m1.insert(5, Student());
    m1.value(3);

    QMultiMap<int, int> m3; // QMap<K, QList<T>>
    m3.insert(1,5);
    m3.insert(1,6);
    QList<int> val = m3.values(1);

    QMap<Student, QString> m4;
    QHash<int, Student> h1;
    QHash<Student, int> h2;
    QMultiHash<int, Student> mh1;
    QSet<int> set;

    MainWindow w;
    w.show();
    return a.exec();
}
