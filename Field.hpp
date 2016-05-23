#ifndef FIELD_HPP
#define FIELD_HPP

#include <QObject>
#include <QVector>

class Cell;

class Field : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int width READ width WRITE setWidth NOTIFY widthChanged)
    Q_PROPERTY(int height READ height WRITE setHeight NOTIFY heightChanged)
public:
    explicit Field(QObject *parent = 0);

    enum State {
        WinX,
        Win0,
        Play
    };

    Q_ENUM(State)

    int width() const { return m_width; }
    int height() const { return m_height; }

    void setState(State state);

    Q_INVOKABLE Cell *cellAt(int x, int y);

signals:
    void widthChanged(int width);
    void heightChanged(int height);

protected slots:
    void winX();
    void winO();

public slots:
    void setWidth(int width);
    void setHeight(int height);

private:
    void applySize();

    QVector<Cell*> m_cells;

    State m_state;

    int m_width;
    int m_height;

};

#endif // FIELD_HPP
