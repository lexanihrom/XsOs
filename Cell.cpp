#include "Cell.hpp"
#include "Field.hpp"

Cell::Cell(QObject *parent) :
    QObject(parent),
    m_mark(MarkNothing)
{

}

void Cell::setMark(Cell::Mark mark)
{
    if (m_mark == mark) {
        return;
    }

    m_mark = mark;
    emit markChanged(mark);
}

void Cell::openX()
{
    if (mark() == MarkNothing){
    setMark(MarkX);
    emit markChanged(mark());
    } else {
        return;
    }
    emit openedx();
}

void Cell::openO()
{
    if (mark() == MarkNothing){
    setMark(MarkO);
    emit markChanged(mark());
    } else {
        return;
    }
    emit openedo();
}
