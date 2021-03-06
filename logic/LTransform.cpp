#include "LTransform.h"

#include "LConst.h"

#include <QRadioButton>
#include <QPushButton>
#include <QGroupBox>
#include <QBoxLayout>

struct LTransformPrivate
{
	QVBoxLayout* lytMain;

	QGroupBox* gbFigures;
	QHBoxLayout* lytFigures;

	QRadioButton* rdQueen;
	QRadioButton* rdElephant;
	QRadioButton* rdHorse;
	QRadioButton* rdRook;

	QPushButton* btnOk;

	LTransformPrivate();
	~LTransformPrivate();
};

LTransformPrivate::LTransformPrivate()
	:
	lytMain(new QVBoxLayout),

	gbFigures(new QGroupBox("Select figure")),
	lytFigures(new QHBoxLayout),

	rdQueen(new QRadioButton("Queen")),
	rdElephant(new QRadioButton("Elephant")),
	rdHorse(new QRadioButton("Horse")),
	rdRook(new QRadioButton("Rook")),

	btnOk(new QPushButton("Ok"))
{
	lytMain->addWidget(gbFigures);
	lytMain->addWidget(btnOk);

	gbFigures->setLayout(lytFigures);
	lytFigures->addWidget(rdQueen);
	lytFigures->addWidget(rdElephant);
	lytFigures->addWidget(rdHorse);
	lytFigures->addWidget(rdRook);

	rdQueen->setChecked(true);
}

LTransformPrivate::~LTransformPrivate()
{
	delete btnOk;

	delete rdQueen;
	delete rdElephant;
	delete rdHorse;
	delete rdRook;

	delete lytFigures;
	delete gbFigures;

	delete lytMain;
}

LTransform::LTransform(QWidget* widget)
	:
	QDialog(widget, Qt::WindowTitleHint | Qt::WindowSystemMenuHint),
	m(new LTransformPrivate)
{
	connect(m->btnOk, SIGNAL(clicked()), SLOT(accept()));

	setWindowTitle("Transformation");
	setLayout(m->lytMain);
	setModal(true);
	show();
}

LTransform::~LTransform()
{
	delete m;
}

int LTransform::getFigure()
{
	if (m->rdQueen->isChecked())
	{
		return L_FIGURE_QUEEN;
	}
	else if (m->rdElephant->isChecked())
	{
		return L_FIGURE_ELEPHANT;
	}
	else if (m->rdHorse->isChecked())
	{
		return L_FIGURE_HORSE;
	}
	else
	{
		return L_FIGURE_ROOK;
	}
}
