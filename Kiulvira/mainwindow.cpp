#include "mainwindow.hpp"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    this->session = new Session();
    createQuickAccessGroupBox();


    QWidget* widget = new QWidget;
    setCentralWidget(widget);

    QVBoxLayout* layout = new QVBoxLayout;
    layout->setMargin(5);
    layout->addWidget(horizontalGroupBox);
    //layout->addWidget(topFiller);
    createActions();
    createMenus();
    createDirectory();
    layout->addWidget(treeView);
    //layout->addWidget(bottomFiller);
    widget->setLayout(layout);




    QString message = tr("A context menu is available by right-clicking");
    statusBar()->showMessage(message);

    setWindowTitle(tr("Kiulvira"));
    setMinimumSize(500, 300);
    resize(800, 500);
}

void MainWindow::createQuickAccessGroupBox() {
    horizontalGroupBox = new QFrame();
    groupQA = new QFrame(horizontalGroupBox);

    groupQA->setFrameStyle(QFrame::StyledPanel);
    layoutGroupQA = new QGridLayout;
    layoutGroupQA->setContentsMargins(0, 0, 0, 0);
    QPushButton* newGroup = new QPushButton("New Group");
    layoutGroupQA->addWidget(newGroup, 0, 0);
    connect(newGroup, SIGNAL (released()), this, SLOT (newGroup()));
    groupQA->setLayout(layoutGroupQA);

    tagQA = new QFrame(horizontalGroupBox);
    tagQA->setFrameStyle(QFrame::StyledPanel);
    layoutTagQA = new QGridLayout;
    layoutTagQA->setContentsMargins(0, 0, 0, 0);
    QPushButton* newTag = new QPushButton("New Tag");
    layoutTagQA->addWidget(newTag, 0, 0);
    connect(newTag, SIGNAL (released()), this, SLOT (newTag()));
    tagQA->setLayout(layoutTagQA);

    horizontalGroupBox->setFrameStyle(QFrame::NoFrame);
    layoutQuickAccess = new QGridLayout;
    layoutQuickAccess->setSpacing(0);
    layoutQuickAccess->addWidget(groupQA,0,0);
    layoutQuickAccess->addWidget(tagQA,0,1);
    horizontalGroupBox->setLayout(layoutQuickAccess);
}

void MainWindow::createDirectory(){
    model = new QDirModel;
    treeView = new QTreeView();
    treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //connect(treeView, SIGNAL(doubleClicked(const QModelIndex &, const QString &)), this, SLOT(addToGroup(QModelIndex, QString)));
    treeView->setModel(model);

    QModelIndex index = treeView->currentIndex();
    QVariant data = treeView->model()->data(index);
    selectDataName = new QString(data.toString());
    connect(treeView, SIGNAL(released()), this, SLOT(changeTag()));

}

MainWindow::~MainWindow() {
    delete ui;
    delete session;
}



void MainWindow::newTag(){
    unsigned int size = this->session->getNumberOfQuickAccessTag() + 1;
    if(size < this->session->getMaxNumberOfQATag()){
        bool ok;
        QString name = QInputDialog::getText(this, tr("New Tag"),
                                             tr("Name of the new tag:"), QLineEdit::Normal,
                                             QDir::home().dirName(), &ok);
        if (ok && !name.isEmpty() && this->session->addTagToQA(new TagHandler(name)) ){
            layoutTagQA->addWidget(
                    new QPushButton(name), 0, size - 1);
            if(size < this->session->getMaxNumberOfQATag()){
                QPushButton* newTag = new QPushButton("New Tag");
                layoutTagQA->addWidget(newTag, 0, size);
                connect(newTag, SIGNAL (released()), this, SLOT (newTag()));
            }
        }
    }else{
        bool ok;
        QString name = QInputDialog::getText(this, tr("New Tag"),
                                             tr("Name of the new tag:"), QLineEdit::Normal,
                                             QDir::home().dirName(), &ok);
        if (ok && !name.isEmpty() && this->session->addTagToQA(new TagHandler(name)) ){
            layoutTagQA->addWidget(new QPushButton(name), 0, size - 1);
        }
    }
}

void MainWindow::newGroup(){
    unsigned int size = this->session->getNumberOfExistingGroup() + 1;
    if(size < this->session->getMaxNumberOfQAGroup()){
        bool ok;
        QString name = QInputDialog::getText(this, tr("New group"),
                                             tr("Name of the new group:"), QLineEdit::Normal,
                                             QDir::home().dirName(), &ok);
        if (ok && !name.isEmpty() && this->session->createNewGroup(name) ){
            QPushButton* group = new QPushButton(name);
            layoutGroupQA->addWidget(group, 0, size - 1);
            //activeGroupName = &name;
            connect(group, SIGNAL (released()), this, SLOT (setSelectGroup()));
            if(size < this->session->getMaxNumberOfQAGroup()){
                QPushButton* newGroup = new QPushButton("New Group");
                layoutGroupQA->addWidget(newGroup, 0, size);
                connect(newGroup, SIGNAL (released()), this, SLOT (newGroup()));
            }
        }
    }else{
        bool ok;
        QString name = QInputDialog::getText(this, tr("New group"),
                                             tr("Name of the new group:"), QLineEdit::Normal,
                                             QDir::home().dirName(), &ok);
        if (ok && !name.isEmpty() && this->session->createNewGroup(name) ){
            QPushButton* group = new QPushButton(name);
            layoutGroupQA->addWidget(group, 0, size - 1);
            //activeGroupName = &name;
            connect(group, SIGNAL (released()), this, SLOT (setSelectGroup()));
        }
    }
}


void MainWindow::addToGroup(){

}

void MainWindow::addToGroupView(const QModelIndex &toAdd, const QString &groupName){
    //int i = this->session->findGroupByName(groupName);
    //this->session->getGroupes().at(i).first.push_back(toAdd);
}

void MainWindow::removeFromGroup(){

}

void MainWindow::changeTag(){
    //1 trouver les Tags
    //2 display
    //3 choisir des tags
    //4 association
    tagDialog = new QDialog(this);
    tagDialog->setWindowTitle("Kiulvira : change associated tag");
    QLabel* label = new QLabel(this);
    QVBoxLayout* layout = new QVBoxLayout();
    label->setText(*selectDataName);
    QListWidget* listWidget = new QListWidget(this);
    QStringList tagsToDisplay;
    for(unsigned int i = 0; i < this->session->getAllTags().size(); ++i){
        tagsToDisplay.push_back(this->session->getAllTags().at(i)->getTagName());
    }
    QStringListModel* model = new QStringListModel();
    model->setStringList(tagsToDisplay);
    //layout->addWidget(model);
    QPushButton* button = new QPushButton("Ok");
    connect(button, SIGNAL (released()), this, SLOT(tagDialogHandleButton()) );
    layout->addWidget(listWidget);
    layout->addWidget(label);
    layout->addWidget(button);
    tagDialog->setLayout(layout);
    tagDialog->setVisible(true);
}

void MainWindow::removeTag(){

}

void MainWindow::removeDataTag(){

}

void MainWindow::associateTag(){

}

void MainWindow::disassociateTag(){

}

void MainWindow::search(){

}

void MainWindow::resetQATag(){
    QList< QWidget* > children;
    do{
       children = tagQA->findChildren< QWidget* >();
       if ( children.count() == 0 ){
           break;
       }
       delete children.at( 0 );
    }while ( true );
    this->session->clearQATags();
    layoutTagQA->setContentsMargins(0, 0, 0, 0);
    QPushButton* newTag = new QPushButton("New Tag");
    layoutTagQA->addWidget(newTag, 0, 0);
    connect(newTag, SIGNAL (released()), this, SLOT (newTag()));
    tagQA->setLayout(layoutTagQA);
    layoutQuickAccess->addWidget(tagQA,0,1);
    horizontalGroupBox->setLayout(layoutQuickAccess);

}

void MainWindow::resetQAGroup(){
    QList< QWidget* > children;
    do{
       children = groupQA->findChildren< QWidget* >();
       if ( children.count() == 0 ){
           break;
       }
       delete children.at( 0 );
    }while ( true );
    this->session->clearGroupes();

    layoutGroupQA->setContentsMargins(0, 0, 0, 0);
    QPushButton* newGroup = new QPushButton("New Group");
    layoutGroupQA->addWidget(newGroup, 0, 0);
    connect(newGroup, SIGNAL (released()), this, SLOT (newGroup()));
    groupQA->setLayout(layoutGroupQA);
    layoutQuickAccess->addWidget(groupQA,0,0);
    horizontalGroupBox->setLayout(layoutQuickAccess);
}

void MainWindow::about(){
   aboutDialog = new QDialog(this);
   aboutDialog->setWindowTitle("About Kiulvira");
   QLabel* label = new QLabel(this);
   QTextEdit* text = new QTextEdit(this);
   text->setText("Kiulvira is a Tag managing software built as a group project from Master ALMA.");
   text->setReadOnly(true);
   QVBoxLayout* layout = new QVBoxLayout();
   label->setText("This project is still a work in progress.");

   QPushButton* button = new QPushButton("Ok");
   connect(button, SIGNAL (released()), this, SLOT(aboutDialogHandleButton()) );

   layout->addWidget(text);

   layout->addWidget(label);

   layout->addWidget(button);
   aboutDialog->setLayout(layout);

   aboutDialog->setVisible(true);
}

void MainWindow::setSelectGroup(){
    //int i = this->session->findGroupByName(activeGroupName);
    //this->session->setSelectGroup(this->session->getGroupes().at(i));
}

void MainWindow::aboutDialogHandleButton() {
    aboutDialog->close();
}

void MainWindow::tagDialogHandleButton() {
    tagDialog->close();
}

void MainWindow::createActions() {
    newTagAct = new QAction(tr("&New Tag..."), this);
    newTagAct->setShortcuts(QKeySequence::New);
    newTagAct->setStatusTip(tr("Create a new tag"));
    connect(newTagAct, &QAction::triggered, this, &MainWindow::newTag);

    newGroupAct = new QAction(tr("&New Group"), this);
    newGroupAct->setShortcuts(QKeySequence::FindNext);
    newGroupAct->setStatusTip(tr("Create a new group"));
    connect(newGroupAct, &QAction::triggered, this, &MainWindow::newGroup);

    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(tr("Exit the application"));
    connect(exitAct, &QAction::triggered, this, &QWidget::close);

    addToGroupAct = new QAction(tr("&Add to Group"), this);
    addToGroupAct->setShortcuts(QKeySequence::AddTab);
    addToGroupAct->setStatusTip(tr("Add this element to the group"));
    connect(addToGroupAct, &QAction::triggered, this, &MainWindow::addToGroup);

    removeFromGroupAct = new QAction(tr("&Remove from a Group"), this);
    //removeFromGroupAct->setShortcuts(QKeySequence::Save);
    removeFromGroupAct->setStatusTip(tr("Remove a file or a directory from this group"));
    connect(removeFromGroupAct, &QAction::triggered, this, &MainWindow::removeFromGroup);

    changeTagAct = new QAction(tr("&Change Tag..."), this);
    changeTagAct->setShortcuts(QKeySequence::Replace);
    changeTagAct->setStatusTip(tr("Change the tag of this element"));
    connect(changeTagAct, &QAction::triggered, this, &MainWindow::changeTag);

    removeTagAct = new QAction(tr("&Remove Tag..."), this);
    //removeTagAct->setShortcuts(QKeySequence::Print);
    removeTagAct->setStatusTip(tr("Delete this tag and disassociate all elements"));
    connect(removeTagAct, &QAction::triggered, this, &MainWindow::removeTag);

    removeDataTagAct = new QAction(tr("Delete Tag and File"), this);
    //removeDataTagAct->setShortcuts(QKeySequence::Quit);
    removeDataTagAct->setStatusTip(tr("Delete this tag and all elements associated to it"));
    connect(removeDataTagAct, &QAction::triggered, this, &MainWindow::removeDataTag);

    associateTagAct = new QAction(tr("&Associate Tag"), this);
    associateTagAct->setShortcuts(QKeySequence::MoveToNextWord);
    associateTagAct->setStatusTip(tr("Associate tag to this element"));
    connect(associateTagAct, &QAction::triggered, this, &MainWindow::associateTag);

    disassociateTagAct = new QAction(tr("&Disassociate Tag"), this);
    disassociateTagAct->setShortcuts(QKeySequence::MoveToPreviousWord);
    disassociateTagAct->setStatusTip(tr("Disassociate tag to this element"));
    connect(disassociateTagAct, &QAction::triggered, this, &MainWindow::disassociateTag);

    searchTagAct = new QAction(tr("&Search by Tag"), this);
    searchTagAct->setShortcuts(QKeySequence::Find);
    searchTagAct->setStatusTip(tr("Search file or directory associate to tags"));
    connect(searchTagAct, &QAction::triggered, this, &MainWindow::search);

    aboutAct = new QAction(tr("&About Kiulvira"), this);
    //aboutAct->setShortcuts(QKeySequence::Redo);
    aboutAct->setStatusTip(tr("About Kiulvira"));
    connect(aboutAct, &QAction::triggered, this, &MainWindow::about);

    resetQAGroupAct = new QAction(tr("&Reset Quick Action Group"), this);
    //resetQAGroupAct->setShortcuts(QKeySequence::Redo);
    resetQAGroupAct->setStatusTip(tr("Reset Quick Action Group"));
    connect(resetQAGroupAct, &QAction::triggered, this, &MainWindow::resetQAGroup);

    resetQATagAct = new QAction(tr("&Reset Quick Action Tag"), this);
    //resetQATagAct->setShortcuts(QKeySequence::Redo);
    resetQATagAct->setStatusTip(tr("Reset Quick Action Tag"));
    connect(resetQATagAct, &QAction::triggered, this, &MainWindow::resetQATag);


}

void MainWindow::createMenus() {

    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newTagAct);
    fileMenu->addAction(newGroupAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(addToGroupAct);
    editMenu->addAction(removeFromGroupAct);
    editMenu->addSeparator();
    editMenu->addAction(changeTagAct);
    editMenu->addSeparator();
    editMenu->addAction(associateTagAct);
    editMenu->addAction(disassociateTagAct);
    editMenu->addSeparator();
    editMenu->addAction(removeTagAct);
    editMenu->addAction(removeDataTagAct);

    findMenu = menuBar()->addMenu(tr("&Find"));
    findMenu->addAction(searchTagAct);

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);

    QAMenu = menuBar()->addMenu(tr("&Quick Access"));
    QAMenu->addAction(resetQAGroupAct);
    QAMenu->addAction(resetQATagAct);
    menuBar()->setVisible(true);
}

