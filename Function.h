#ifndef FUNCTION_H
#define FUNCTION_H

#include <QWidget>

class QPushButton;
class QLabel;
class QLineEdit;
class QTableWidget;
class QTableWidgetItem;

class Function : public QWidget
{
	Q_OBJECT
public:
	Function (QWidget* pwgt = 0);
public slots:
	void calculate();
private:
	QLabel* m_head;
	QLabel* m_abscissaF;
	QLabel* m_abscissaS;
	QLabel* m_step;
	QLabel* m_error;

	QLineEdit* m_enterAbsF;
	QLineEdit* m_enterAbsS;
	QLineEdit* m_enterStep;

	QPushButton* m_butRun;

	QTableWidget* m_table;
	QTableWidgetItem* m_tItemX;
	QTableWidgetItem* m_tItemY;
};
#endif // FUNCTION_H
