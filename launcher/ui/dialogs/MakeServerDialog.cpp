#include "MakeServerDialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>

MakeServerDialog::MakeServerDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Make Server");
    setModal(true);
    setMinimumWidth(400);
    setMinimumHeight(300);
    
    setupUI();
}

MakeServerDialog::~MakeServerDialog()
{
}

void MakeServerDialog::setupUI()
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    
    // Header label
    QLabel *headerLabel = new QLabel("Create a new Server", this);
    mainLayout->addWidget(headerLabel);
    
    // Info label
    QLabel *infoLabel = new QLabel(
        "Select server type:",
        this
    );
    mainLayout->addWidget(infoLabel);
    
    // Custom option button (for now, only this is available)
    QPushButton *customButton = new QPushButton("Custom Server", this);
    customButton->setMinimumHeight(50);
    connect(customButton, &QPushButton::clicked, this, &MakeServerDialog::on_customButtonClicked);
    mainLayout->addWidget(customButton);
    
    // Stretch to fill space
    mainLayout->addStretch();
    
    // Bottom buttons (OK and Cancel)
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    
    QPushButton *okButton = new QPushButton("OK", this);
    QPushButton *cancelButton = new QPushButton("Cancel", this);
    
    buttonLayout->addStretch();
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);
    
    mainLayout->addLayout(buttonLayout);
    
    // Connect buttons
    connect(okButton, &QPushButton::clicked, this, &MakeServerDialog::on_okButtonClicked);
    connect(cancelButton, &QPushButton::clicked, this, &MakeServerDialog::on_cancelButtonClicked);
    
    setLayout(mainLayout);
}

void MakeServerDialog::on_customButtonClicked()
{
    // For now, just show a message that custom was selected
    QMessageBox::information(this, "Custom Server", "Custom server option selected!");
}

void MakeServerDialog::on_okButtonClicked()
{
    // Currently does nothing - placeholder for future functionality
    accept();
}

void MakeServerDialog::on_cancelButtonClicked()
{
    reject();
}
