#include <QCoreApplication>
#include <QMap>

struct Student{
    int shifr;
    QString fio;
    QString group;
};

class StudentList{
    StudentList();
    ~StudentList();
    Student at(int shifr) const
    {
        return _studentmap_shifr.value(shifr);
    }
    Student at(const QString &fio) const
    {
        return _studentmap_fio.value(fio);
    }
    void add(const Student &s)
    {
        _studentmap_shifr.insert(s.shifr, s);
        _studentmap_fio.insert(s.fio, s);
    }
    void remove(int shifr)
    {/*
        for (auto it = _studentmap_shifr.begin(); it != _studentmap_shifr.end();)
            if (it.value().shifr == shifr)
                it = _studentmap_shifr.erase(it);
            else
                ++it;*/
    }
    void remove(const QString &fio) const;

private:
    QMap<int, Student> _studentmap_shifr;
    QMap<QString, Student> _studentmap_fio;
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
