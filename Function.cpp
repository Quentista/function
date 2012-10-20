#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QTableWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "Function.h"

Function::Function (QWidget *pwgt) : QWidget(pwgt)
{
    m_head = new QLabel("Y=X^2+X");
    m_abscissaF = new QLabel("Enter X1: ");
    m_abscissaS = new QLabel("Enter X2: ");
    m_step = new QLabel("Step: ");

    m_enterAbsF = new QLineEdit;
    m_enterAbsS = new QLineEdit;
    m_enterStep = new QLineEdit;

    m_table = new QTableWidget(10,2);

    m_butRun = new QPushButton ("Run");

    QObject::connect(
                m_butRun, SIGNAL(clicked()),
                SLOT (slotButtonClicked()));


    //Layout setup

     QVBoxLayout* mainLayout = new QVBoxLayout;
     QHBoxLayout* firstLayout = new QHBoxLayout;

     firstLayout->setMargin(5);
     firstLayout->setSpacing(5);
     firstLayout->addWidget(m_abscissaF);
     firstLayout->addWidget(m_enterAbsF);
     firstLayout->addWidget(m_abscissaS);
     firstLayout->addWidget(m_enterAbsS);
     firstLayout->addWidget(m_step);
     firstLayout->addWidget(m_enterStep);
     firstLayout->addWidget(m_butRun);

     mainLayout->setMargin(5);
     mainLayout->setSpacing(5);
     mainLayout->addWidget(m_head);
     mainLayout->addLayout(firstLayout);
     mainLayout->addWidget(m_table);

     setLayout(mainLayout);
}

void Function::slotButtonClicked()
{
    QString m_strX;
    QString m_strY;

        int i =0;

    double m_x1 =m_enterAbsF->text().toDouble();
    double m_x2 =m_enterAbsS->text().toDouble();
    double m_st = m_enterStep->text().toDouble();
    double m_y=0;

    int n = ((m_x2 - m_x1)/m_st)+1;

    m_table->setRowCount(n);
    m_table->setColumnCount(2);

    for (i =0; m_x1<=m_x2; ++i)
    {
        m_strX.setNum(m_x1);
        m_tItemX = new QTableWidgetItem(m_strX.arg(i).arg(0));

        m_y = m_x1*m_x1 + m_x1;
        m_strY.setNum(m_y);
        m_tItemY = new QTableWidgetItem(m_strY.arg(i).arg(1));

        m_x1 = m_x1 + m_st;


        m_table->setItem(i,0, m_tItemX);
        m_table->setItem(i,1, m_tItemY);
    }
}
