#include "mainwindow.h"

#include <iomanip>
#include <locale>

#include "./ui_mainwindow.h"

extern "C" {
#include "../../s21_SmartCalc.h"
}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  graph = nullptr;
  credit = nullptr;
}
MainWindow::~MainWindow() { delete ui; }
void MainWindow::openGraph() {
  if (graph) {
    closeGraph();
  }
  graph = new Graph(this);
}
void MainWindow::closeGraph() {
  if (graph) {
    graph->close();
    delete graph;
    graph = nullptr;
  }
}
void MainWindow::openCredit() {
  if (credit) {
    closeCredit();
  }
  credit = new Credit(this);
}
void MainWindow::closeCredit() {
  if (credit) {
    credit->close();
    delete credit;
    credit = nullptr;
  }
}
void MainWindow::on_pushButton_DOT_clicked() {
  ui->result->setText(ui->result->text() + ".");
}
void MainWindow::on_pushButton_0_clicked() {
  ui->result->setText(ui->result->text() + "0");
}
void MainWindow::on_pushButton_1_clicked() {
  ui->result->setText(ui->result->text() + "1");
}
void MainWindow::on_pushButton_2_clicked() {
  ui->result->setText(ui->result->text() + "2");
}
void MainWindow::on_pushButton_3_clicked() {
  ui->result->setText(ui->result->text() + "3");
}
void MainWindow::on_pushButton_4_clicked() {
  ui->result->setText(ui->result->text() + "4");
}
void MainWindow::on_pushButton_5_clicked() {
  ui->result->setText(ui->result->text() + "5");
}
void MainWindow::on_pushButton_6_clicked() {
  ui->result->setText(ui->result->text() + "6");
}
void MainWindow::on_pushButton_7_clicked() {
  ui->result->setText(ui->result->text() + "7");
}
void MainWindow::on_pushButton_8_clicked() {
  ui->result->setText(ui->result->text() + "8");
}
void MainWindow::on_pushButton_9_clicked() {
  ui->result->setText(ui->result->text() + "9");
}
void MainWindow::on_pushButton_PLUS_clicked() {
  ui->result->setText(ui->result->text() + "+");
}
void MainWindow::on_pushButton_OP_Bracket_clicked() {
  ui->result->setText(ui->result->text() + "(");
}
void MainWindow::on_pushButton_CL_Bracket_clicked() {
  ui->result->setText(ui->result->text() + ")");
}
void MainWindow::on_pushButton_Pow_clicked() {
  ui->result->setText(ui->result->text() + "^");
}
void MainWindow::on_pushButton_MINUS_clicked() {
  ui->result->setText(ui->result->text() + "-");
}
void MainWindow::on_pushButton_DIV_clicked() {
  ui->result->setText(ui->result->text() + "/");
}
void MainWindow::on_pushButton_MUL_clicked() {
  ui->result->setText(ui->result->text() + "*");
}
void MainWindow::on_pushButton_C_clicked() {
  QString currentText = ui->result->text();
  if (!currentText.isEmpty()) {
    currentText = currentText.left(currentText.length() - 1);
    ui->result->setText(currentText);
  }
}
void MainWindow::on_pushButton_AC_clicked() {
  check_calc = 0;
  ui->result->setText("");
  if (graph) {
    closeGraph();
  }
}
void MainWindow::on_pushButton_ASIN_clicked() {
  ui->result->setText(ui->result->text() + "asin(");
}
void MainWindow::on_pushButton_ACOS_clicked() {
  ui->result->setText(ui->result->text() + "acos(");
}
void MainWindow::on_pushButton_ATAN_clicked() {
  ui->result->setText(ui->result->text() + "atan(");
}
void MainWindow::on_pushButton_SIN_clicked() {
  ui->result->setText(ui->result->text() + "sin(");
}
void MainWindow::on_pushButton_COS_clicked() {
  ui->result->setText(ui->result->text() + "cos(");
}
void MainWindow::on_pushButton_TAN_clicked() {
  ui->result->setText(ui->result->text() + "tan(");
}
void MainWindow::on_pushButton_LOG_clicked() {
  ui->result->setText(ui->result->text() + "log(");
}
void MainWindow::on_pushButton_LN_clicked() {
  ui->result->setText(ui->result->text() + "ln(");
}
void MainWindow::on_pushButton_SQRT_clicked() {
  ui->result->setText(ui->result->text() + "sqrt(");
}
void MainWindow::on_pushButton_MOD_clicked() {
  ui->result->setText(ui->result->text() + " mod ");
}
void MainWindow::on_pushButton_X_clicked() {
  ui->result->setText(ui->result->text() + "x");
}
void MainWindow::on_pushButton_CREDIT_clicked() {
  openCredit();
  credit->show();
}

void MainWindow::simple_exp() {
  char out[256];
  QString input = ui->result->text();

  QByteArray byteArray = input.toUtf8();
  const char *str_c = byteArray.constData();

  int err = s21_smart_calc(str_c, out);
  Output_and_err(out, err, 0);
}
int MainWindow::calc_values() {
  double res[100] = {0};
  int j = 0;
  int err = 0;
  QString input = ui->result->text();
  double i = -5;

  while (i < 5 && !err) {
    char out[256];
    double resultValue;
    QString newInput = input;
    std::string output;
    std::ostringstream oss;
    oss << std::fixed << i;
    output = oss.str();
    newInput.replace("x", "(Q)");
    newInput.replace("Q", QString::fromStdString(output));
    QByteArray byteArray = newInput.toUtf8();
    const char *str_c = byteArray.constData();
    err = s21_smart_calc(str_c, out);
    resultValue = std::stod(out);
    res[j] = resultValue;
    j++;
    i += 0.1;
  }
  if (!err) {
    graph->drawPlot(res);
  }
  return err;
}
void MainWindow::calc_one_value(QString for_x_calc) {
  char out[256];
  int err = 0;
  QString calc_one = ui->result->text();
  calc_one.replace("X = ", "");
  for_x_calc.replace("x", "(Q)");
  for_x_calc.replace("Q", calc_one);
  QByteArray byteArray = for_x_calc.toUtf8();
  const char *str_c = byteArray.constData();
  err = s21_smart_calc(str_c, out);
  Output_and_err(out, err, 0);
}
void MainWindow::on_pushButton_EQ_clicked() {
  if (check_calc == 0) {
    QString input = ui->result->text();
    if (input.contains("x")) {
      if (ui->Calculation->isChecked()) {
        for_x_calc = ui->result->text();
        ui->result->setText("X = ");
        check_calc = 1;
      } else if (ui->Graf->isChecked()) {
        openGraph();
        int err = calc_values();
        Output_and_err(NULL, err, 1);
      }
    } else {
      simple_exp();
    }
  } else {
    check_calc = 0;
    calc_one_value(for_x_calc);
  }
}

void MainWindow::Output_and_err(char *setingtxt, int err, int check_gr){
  if (err == 1){
    ui->result->setText("INCORRECT INPUT");
  }else if (err == 2){
    ui->result->setText("DIVISION BY ZERO");
  }else if(check_gr == 1){
    graph->show();
  }else if(!check_gr){
    QString qOutput = credit->conv_str(setingtxt);
    ui->result->setText(qOutput);
  }
}