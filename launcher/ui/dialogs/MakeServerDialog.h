#pragma once

#include <QDialog>

class MakeServerDialog : public QDialog {
    Q_OBJECT

public:
    explicit MakeServerDialog(QWidget *parent = nullptr);
    ~MakeServerDialog();

private slots:
    void on_customButtonClicked();
    void on_okButtonClicked();
    void on_cancelButtonClicked();

private:
    void setupUI();
};
