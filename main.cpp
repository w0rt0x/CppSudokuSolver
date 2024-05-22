//#include <QWidget>
//#include <QApplication>
//#include <QMainWindow>
#include "field.h"
#include "solver.h"

int main(int argc, char *argv[]){
    Field f = Field();
    f.from_file("./../tests/fields/Solvable/field1.txt");
    bool solved = solver::backtrack(f, 0, 0);
    f.to_file("solved.txt");
    return 0;

    //QApplication app(argc, argv);
    //QMainWindow window;
    //window.setWindowTitle("Test");

    //window.show();
    return 0; //app.exec();
}