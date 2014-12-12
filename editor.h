#ifndef EDITOR_H
#define EDITOR_H

#include <QMainWindow>

namespace Ui {
class editor;
}

class editor : public QMainWindow
{
    Q_OBJECT

public:
    explicit editor(QWidget *parent = 0);
    ~editor();

private slots:
    void on_quitButton_clicked();

private slots:
    void on_actionOpen_triggered();

private slots:
    void on_actionSave_triggered();

private:
    Ui::editor *ui;
};

#endif // EDITOR_H
