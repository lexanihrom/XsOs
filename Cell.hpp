#ifndef CELL_HPP
#define CELL_HPP

#include <QObject>

class Cell : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Mark mark READ mark WRITE setMark NOTIFY markChanged)
public:
    explicit Cell(QObject *parent = 0);

    enum Mark {
        MarkNothing,
        MarkX,
        MarkO
    };
    Q_ENUM(Mark)

    Mark mark() const {return m_mark; }
    void setMark(Mark mark);

public slots:
    void openX();
    void openO();

signals:
    void markChanged(Mark mark);
    void openedx();
    void openedo();

private:
    Mark m_mark;
};

#endif // CELL_HPP
