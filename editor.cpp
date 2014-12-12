#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

#include "editor.h"
#include "ui_editor.h"

editor::editor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::editor)
{
    ui->setupUi(this);
}

editor::~editor()
{
    delete ui;
}

void editor::on_quitButton_clicked()
{
    qApp->quit();
}

void editor::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QString(),
        tr("Text Files (*.txt);; C++ Files (*.cpp *.h)"));

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
        }

        QTextStream in(&file);
        ui->textEdit->setText(in.readAll());
        file.close();
    }
}

void editor::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), QString(),
        tr("Text Files (*.txt);;C++ Files(*.cpp *.h)"));

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {

        } else {
            QTextStream stream(&file);
            stream << ui->textEdit->toPlainText();
            stream.flush();
            file.close();
        }
    }
}
