#include <QDesktopWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSizePolicy>
#include <QGroupBox>
#include <QSplitter>

#include "tnotesmainwindow.h"
#include "tnotestexteditor.h"
#include "tnotesbookcategory.h"
#include "tnotescategory.h"
#include "tnotessearchtool.h"


tNotesMainWindow::tNotesMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
	/* set window size */

	setMainWindowsSize();

	/* initialization */
	centralWidget = new QGroupBox(tr("central widget"));
	setCentralWidget(centralWidget);
	centralWidget->setSizePolicy(QSizePolicy::Expanding,
			QSizePolicy::Expanding);
	
	notesBookCategory = new tNotesBookCategory;
	notesTextEditor = new tNotesTextEditor;
	searchTool = new tNotesSearchTool;
	notesCategory = new tNotesCategory;

	/*
	 * set layout
	 */
	QHBoxLayout *toolLayout = new QHBoxLayout;
	toolLayout->addStretch(3);
	toolLayout->addWidget(searchTool, 1);

	QHBoxLayout *noteLayout = new QHBoxLayout;
	splitter = new QSplitter;
	splitter->setChildrenCollapsible(false);
	splitter->addWidget(notesBookCategory);
	splitter->addWidget(notesCategory);
	splitter->addWidget(notesTextEditor);
	noteLayout->addWidget(splitter);
	/*  
	noteLayout->addWidget(notesBookCategory, 1);
	noteLayout->addWidget(notesCategory, 1);
	noteLayout->addWidget(notesTextEditor, 2);
	*/

	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->addLayout(toolLayout, 1);
	mainLayout->addLayout(noteLayout, 9);
	
	centralWidget->setLayout(mainLayout);
}

tNotesMainWindow::~tNotesMainWindow()
{

}

void tNotesMainWindow::setMainWindowsSize(){
	QDesktopWidget dw;
	int x = dw.width()*0.8;
	int y = dw.height()*0.7;
	this->resize(x, y);
}
