#include "Field.hpp"

#include "Cell.hpp"

Field::Field(QObject *parent) :
    QObject(parent),
    m_width(10),
    m_height(10),
    m_state(Play)
{
    applySize();
}

void Field::setState(State state)
{
    m_state = state;
}

Cell *Field::cellAt(int x, int y)
{
    if (x < 0 || x >= width()) {
        return nullptr;
    }

    if (y < 0 || y >= height()) {
        return nullptr;
    }

    int index = x + y * width();

    if (index >= m_cells.count()) {
        return nullptr;
    }

    return m_cells.at(index);
}

void Field::setWidth(int width)
{
    if (m_width == width) {
        return;
    }

    m_width = width;
    emit widthChanged(width);
}

void Field::setHeight(int height)
{
    if (m_height == height) {
        return;
    }

    m_height = height;
    emit heightChanged(height);
}

void Field::applySize()
{
    for (Cell *cell : m_cells) {
        delete cell;
    }

    m_cells.clear();

    for (int y = 0; y < height(); ++y) {
        for (int x = 0; x < width(); ++x) {
            Cell *cell = new Cell(this);
            connect(cell, SIGNAL(openedx()), this, SLOT(winX()));
            connect(cell, SIGNAL(openedo()), this, SLOT(winO()));
            m_cells.append(cell);
        }
    }
}

void Field::winX()
{
    for (int j = 0; j < 10; j++){
        int k = 10 * j;
        for (int i = 0; i < 7; i++){
            if (m_cells[k+i]->mark() == Cell::MarkX && m_cells[k+1+i]->mark() == Cell::MarkX && m_cells[k+2+i]->mark() == Cell::MarkX && m_cells[k+3+i]->mark() == Cell::MarkX){
                for (int i = 0; i < m_cells.size(); i++) {
                    m_cells[i]->setMark(Cell::MarkNothing);
                }
                m_cells[0]->setMark(Cell::MarkX);
                m_cells[11]->setMark(Cell::MarkX);
                m_cells[22]->setMark(Cell::MarkX);
                m_cells[33]->setMark(Cell::MarkX);
                m_cells[44]->setMark(Cell::MarkX);
                m_cells[55]->setMark(Cell::MarkX);
                m_cells[66]->setMark(Cell::MarkX);
                m_cells[77]->setMark(Cell::MarkX);
                m_cells[88]->setMark(Cell::MarkX);
                m_cells[99]->setMark(Cell::MarkX);
                m_cells[9]->setMark(Cell::MarkX);
                m_cells[18]->setMark(Cell::MarkX);
                m_cells[27]->setMark(Cell::MarkX);
                m_cells[36]->setMark(Cell::MarkX);
                m_cells[45]->setMark(Cell::MarkX);
                m_cells[54]->setMark(Cell::MarkX);
                m_cells[63]->setMark(Cell::MarkX);
                m_cells[72]->setMark(Cell::MarkX);
                m_cells[81]->setMark(Cell::MarkX);
                m_cells[90]->setMark(Cell::MarkX);
            }
        }
    } //горизонт

    for (int j = 0; j < 10; j++){
        int k = j;
        for (int i = 0; i < 7; i++){
            if (m_cells[k]->mark() == Cell::MarkX && m_cells[k+10]->mark() == Cell::MarkX && m_cells[k+20]->mark() == Cell::MarkX && m_cells[k+30]->mark() == Cell::MarkX){
                for (int i = 0; i < m_cells.size(); i++) {
                    m_cells[i]->setMark(Cell::MarkNothing);
                }
                m_cells[0]->setMark(Cell::MarkX);
                m_cells[11]->setMark(Cell::MarkX);
                m_cells[22]->setMark(Cell::MarkX);
                m_cells[33]->setMark(Cell::MarkX);
                m_cells[44]->setMark(Cell::MarkX);
                m_cells[55]->setMark(Cell::MarkX);
                m_cells[66]->setMark(Cell::MarkX);
                m_cells[77]->setMark(Cell::MarkX);
                m_cells[88]->setMark(Cell::MarkX);
                m_cells[99]->setMark(Cell::MarkX);
                m_cells[9]->setMark(Cell::MarkX);
                m_cells[18]->setMark(Cell::MarkX);
                m_cells[27]->setMark(Cell::MarkX);
                m_cells[36]->setMark(Cell::MarkX);
                m_cells[45]->setMark(Cell::MarkX);
                m_cells[54]->setMark(Cell::MarkX);
                m_cells[63]->setMark(Cell::MarkX);
                m_cells[72]->setMark(Cell::MarkX);
                m_cells[81]->setMark(Cell::MarkX);
                m_cells[90]->setMark(Cell::MarkX);
            }
            k += 10;
        }
    } //вертикаль

    for (int j = 0; j < 7; j++){
        int k = j * 10;
        for (int i = 0; i < 7; i++){
            if (m_cells[k]->mark() == Cell::MarkX && m_cells[k+11]->mark() == Cell::MarkX && m_cells[k+22]->mark() == Cell::MarkX && m_cells[k+33]->mark() == Cell::MarkX){
                for (int i = 0; i < m_cells.size(); i++) {
                    m_cells[i]->setMark(Cell::MarkNothing);
                }
                m_cells[0]->setMark(Cell::MarkX);
                m_cells[11]->setMark(Cell::MarkX);
                m_cells[22]->setMark(Cell::MarkX);
                m_cells[33]->setMark(Cell::MarkX);
                m_cells[44]->setMark(Cell::MarkX);
                m_cells[55]->setMark(Cell::MarkX);
                m_cells[66]->setMark(Cell::MarkX);
                m_cells[77]->setMark(Cell::MarkX);
                m_cells[88]->setMark(Cell::MarkX);
                m_cells[99]->setMark(Cell::MarkX);
                m_cells[9]->setMark(Cell::MarkX);
                m_cells[18]->setMark(Cell::MarkX);
                m_cells[27]->setMark(Cell::MarkX);
                m_cells[36]->setMark(Cell::MarkX);
                m_cells[45]->setMark(Cell::MarkX);
                m_cells[54]->setMark(Cell::MarkX);
                m_cells[63]->setMark(Cell::MarkX);
                m_cells[72]->setMark(Cell::MarkX);
                m_cells[81]->setMark(Cell::MarkX);
                m_cells[90]->setMark(Cell::MarkX);
            }
            k++;
        }
    } //слева направо диагональ

    for (int j = 0; j < 7; j++){
        int k = j * 10;
        for (int i = 0; i < 7; i++){
            if (m_cells[k+30]->mark() == Cell::MarkX && m_cells[k+21]->mark() == Cell::MarkX && m_cells[k+12]->mark() == Cell::MarkX && m_cells[k+3]->mark() == Cell::MarkX){
                for (int i = 0; i < m_cells.size(); i++) {
                    m_cells[i]->setMark(Cell::MarkNothing);
                }
                m_cells[0]->setMark(Cell::MarkX);
                m_cells[11]->setMark(Cell::MarkX);
                m_cells[22]->setMark(Cell::MarkX);
                m_cells[33]->setMark(Cell::MarkX);
                m_cells[44]->setMark(Cell::MarkX);
                m_cells[55]->setMark(Cell::MarkX);
                m_cells[66]->setMark(Cell::MarkX);
                m_cells[77]->setMark(Cell::MarkX);
                m_cells[88]->setMark(Cell::MarkX);
                m_cells[99]->setMark(Cell::MarkX);
                m_cells[9]->setMark(Cell::MarkX);
                m_cells[18]->setMark(Cell::MarkX);
                m_cells[27]->setMark(Cell::MarkX);
                m_cells[36]->setMark(Cell::MarkX);
                m_cells[45]->setMark(Cell::MarkX);
                m_cells[54]->setMark(Cell::MarkX);
                m_cells[63]->setMark(Cell::MarkX);
                m_cells[72]->setMark(Cell::MarkX);
                m_cells[81]->setMark(Cell::MarkX);
                m_cells[90]->setMark(Cell::MarkX);
            }
            k++;
        }
    } //справа налево диагональ
}

void Field::winO()
{
    for (int j = 0; j < 10; j++){
        int k = 10 * j;
        for (int i = 0; i < 7; i++){
            if (m_cells[k+i]->mark() == Cell::MarkO && m_cells[k+1+i]->mark() == Cell::MarkO && m_cells[k+2+i]->mark() == Cell::MarkO && m_cells[k+3+i]->mark() == Cell::MarkO){
                for (int i = 0; i < m_cells.size(); i++) {
                    m_cells[i]->setMark(Cell::MarkNothing);
                }
                m_cells[4]->setMark(Cell::MarkO);
                m_cells[5]->setMark(Cell::MarkO);
                m_cells[13]->setMark(Cell::MarkO);
                m_cells[16]->setMark(Cell::MarkO);
                m_cells[22]->setMark(Cell::MarkO);
                m_cells[27]->setMark(Cell::MarkO);
                m_cells[31]->setMark(Cell::MarkO);
                m_cells[38]->setMark(Cell::MarkO);
                m_cells[40]->setMark(Cell::MarkO);
                m_cells[49]->setMark(Cell::MarkO);
                m_cells[50]->setMark(Cell::MarkO);
                m_cells[59]->setMark(Cell::MarkO);
                m_cells[61]->setMark(Cell::MarkO);
                m_cells[68]->setMark(Cell::MarkO);
                m_cells[72]->setMark(Cell::MarkO);
                m_cells[77]->setMark(Cell::MarkO);
                m_cells[83]->setMark(Cell::MarkO);
                m_cells[86]->setMark(Cell::MarkO);
                m_cells[94]->setMark(Cell::MarkO);
                m_cells[95]->setMark(Cell::MarkO);
            }
        }
    } //горизонт

    for (int j = 0; j < 10; j++){
        int k = j;
        for (int i = 0; i < 7; i++){
            if (m_cells[k]->mark() == Cell::MarkO && m_cells[k+10]->mark() == Cell::MarkO && m_cells[k+20]->mark() == Cell::MarkO && m_cells[k+30]->mark() == Cell::MarkO){
                for (int i = 0; i < m_cells.size(); i++) {
                    m_cells[i]->setMark(Cell::MarkNothing);
                }
                m_cells[4]->setMark(Cell::MarkO);
                m_cells[5]->setMark(Cell::MarkO);
                m_cells[13]->setMark(Cell::MarkO);
                m_cells[16]->setMark(Cell::MarkO);
                m_cells[22]->setMark(Cell::MarkO);
                m_cells[27]->setMark(Cell::MarkO);
                m_cells[31]->setMark(Cell::MarkO);
                m_cells[38]->setMark(Cell::MarkO);
                m_cells[40]->setMark(Cell::MarkO);
                m_cells[49]->setMark(Cell::MarkO);
                m_cells[50]->setMark(Cell::MarkO);
                m_cells[59]->setMark(Cell::MarkO);
                m_cells[61]->setMark(Cell::MarkO);
                m_cells[68]->setMark(Cell::MarkO);
                m_cells[72]->setMark(Cell::MarkO);
                m_cells[77]->setMark(Cell::MarkO);
                m_cells[83]->setMark(Cell::MarkO);
                m_cells[86]->setMark(Cell::MarkO);
                m_cells[94]->setMark(Cell::MarkO);
                m_cells[95]->setMark(Cell::MarkO);
            }
            k += 10;
        }
    } //вертикаль

    for (int j = 0; j < 7; j++){
        int k = j * 10;
        for (int i = 0; i < 7; i++){
            if (m_cells[k]->mark() == Cell::MarkO && m_cells[k+11]->mark() == Cell::MarkO && m_cells[k+22]->mark() == Cell::MarkO && m_cells[k+33]->mark() == Cell::MarkO){
                for (int i = 0; i < m_cells.size(); i++) {
                    m_cells[i]->setMark(Cell::MarkNothing);
                }
                m_cells[4]->setMark(Cell::MarkO);
                m_cells[5]->setMark(Cell::MarkO);
                m_cells[13]->setMark(Cell::MarkO);
                m_cells[16]->setMark(Cell::MarkO);
                m_cells[22]->setMark(Cell::MarkO);
                m_cells[27]->setMark(Cell::MarkO);
                m_cells[31]->setMark(Cell::MarkO);
                m_cells[38]->setMark(Cell::MarkO);
                m_cells[40]->setMark(Cell::MarkO);
                m_cells[49]->setMark(Cell::MarkO);
                m_cells[50]->setMark(Cell::MarkO);
                m_cells[59]->setMark(Cell::MarkO);
                m_cells[61]->setMark(Cell::MarkO);
                m_cells[68]->setMark(Cell::MarkO);
                m_cells[72]->setMark(Cell::MarkO);
                m_cells[77]->setMark(Cell::MarkO);
                m_cells[83]->setMark(Cell::MarkO);
                m_cells[86]->setMark(Cell::MarkO);
                m_cells[94]->setMark(Cell::MarkO);
                m_cells[95]->setMark(Cell::MarkO);
            }
            k++;
        }
    } //слева направо диагональ

    for (int j = 0; j < 7; j++){
        int k = j * 10;
        for (int i = 0; i < 7; i++){
            if (m_cells[k+30]->mark() == Cell::MarkO && m_cells[k+21]->mark() == Cell::MarkO && m_cells[k+12]->mark() == Cell::MarkO && m_cells[k+3]->mark() == Cell::MarkO){
                for (int i = 0; i < m_cells.size(); i++) {
                    m_cells[i]->setMark(Cell::MarkNothing);
                }
                m_cells[4]->setMark(Cell::MarkO);
                m_cells[5]->setMark(Cell::MarkO);
                m_cells[13]->setMark(Cell::MarkO);
                m_cells[16]->setMark(Cell::MarkO);
                m_cells[22]->setMark(Cell::MarkO);
                m_cells[27]->setMark(Cell::MarkO);
                m_cells[31]->setMark(Cell::MarkO);
                m_cells[38]->setMark(Cell::MarkO);
                m_cells[40]->setMark(Cell::MarkO);
                m_cells[49]->setMark(Cell::MarkO);
                m_cells[50]->setMark(Cell::MarkO);
                m_cells[59]->setMark(Cell::MarkO);
                m_cells[61]->setMark(Cell::MarkO);
                m_cells[68]->setMark(Cell::MarkO);
                m_cells[72]->setMark(Cell::MarkO);
                m_cells[77]->setMark(Cell::MarkO);
                m_cells[83]->setMark(Cell::MarkO);
                m_cells[86]->setMark(Cell::MarkO);
                m_cells[94]->setMark(Cell::MarkO);
                m_cells[95]->setMark(Cell::MarkO);
            }
            k++;
        }
    } //справа налево диагональ
}
