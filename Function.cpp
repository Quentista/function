#include "Function.h"

#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QTableWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QApplication>


Function::Function (QWidget *pwgt) : QWidget(pwgt)
{
	m_head = new QLabel("Y=X^2+X");
	m_abscissaF = new QLabel("Enter X1: ");
	m_abscissaS = new QLabel("Enter X2: ");
	m_step = new QLabel("Step: ");
	m_error = new QLabel("very funny joke");
	m_error->hide();

	m_enterAbsF = new QLineEdit;
	m_enterAbsS = new QLineEdit;
	m_enterStep = new QLineEdit;

	m_table = new QTableWidget;
	m_table->hide();

	m_butRun = new QPushButton ("Run");

	this->connect(m_butRun, SIGNAL(clicked()), SLOT (calculate()));


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
	mainLayout->addStretch();
	mainLayout->addWidget(m_table);
	mainLayout->addWidget(m_error);

	setLayout(mainLayout);
}

void Function::calculate()
{
	bool checkX1;
	bool checkX2;
	bool checkS;

	double x1 =m_enterAbsF->text().toDouble(&checkX1);
	double x2 =m_enterAbsS->text().toDouble(&checkX2);
	double step = m_enterStep->text().toDouble(&checkS);
	//double y=0;

	if (x1<=x2 && step>0 && checkX1 && checkX2 && checkS)
	{
		int j=0;
		int n = ((x2 - x1)/step)+2;
		m_table->setRowCount(n);
		m_table->setColumnCount(2);

		m_table->show();

		count(&x1, &x2, &step, &j);
		
		if (x1<x2)
		{
			QString m_strX;
			QString m_strY;
			double y=0;
			m_strX.setNum(x2);
			m_tItemX = new QTableWidgetItem(m_strX);
	
			y = x2*x2 + x2;
			m_strY.setNum(y);
			m_tItemY = new QTableWidgetItem(m_strY);
	
			m_table->setItem(j,0, m_tItemX);
			m_table->setItem(j,1, m_tItemY);
		}
	}
	else
	{
		m_table->hide();
		m_error->show();
	}
}

void Function::count(double *c_x1, double *c_x2, double *c_step, int* i)
{
	for (*i =0; (*c_x1)<=(*c_x2); (*c_x1)+=(*c_step), ++(*i))
	{
		QString m_strX;
		QString m_strY;
		double y=0;
		m_strX.setNum(*c_x1);
		m_tItemX = new QTableWidgetItem(m_strX);

		y = (*c_x1)*(*c_x1) + (*c_x1);
		m_strY.setNum(y);
		m_tItemY = new QTableWidgetItem(m_strY);

		m_table->setItem(*i,0, m_tItemX);
		m_table->setItem(*i,1, m_tItemY);

		if( ((*i)%100)==0 )
		{
			qApp->processEvents();
		}
	}
}

