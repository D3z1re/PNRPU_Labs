#include "graph.h"
#include "ui_graph.h"
#include <cmath>
#include <queue>
#include <QTextStream>
using namespace std;

QTextStream cout(stdout);
QTextStream cin(stdin);

int     radiusA = 30,
        radiusB = 230;


QString Graph::Dejkstra()
{
    QString tmp = "";
    int top = 0; //вершина с номером 1
    queue<int> line;
    line.push(top);
    result[0] = 0;
    while (!line.empty()) {
        int vert = line.front();
        line.pop();
        for (int i = 0; i < matrix[vert].size(); i++) {
            if (!visited[i] && matrix[vert][i] && (matrix[vert][i] + result[vert] < result[i])) {
                result[i] = matrix[vert][i] + result[vert];
                line.push(i);
            }
        }
    }
    for (int i = 0; i < 6; i++) {
        cout << i + 1 << ": " << result[i] << endl;
        tmp += QString::number(i + 1) + ": " + QString::number(result[i]) + "\n";
    }
    return tmp;
}


int Graph::GetWeight(const int vert1, const int vert2) //получение веса ребра
{
    if (vert1 >= 0 && vert1 < matrix.size() && vert2 >=0 && vert2 < matrix.size())
        return matrix[vert1][vert2];
    else
        return 0;
}

void Graph::DrawLines(QGraphicsScene* scene) //отрисовка ребер графа
{
    QPen pen(Qt::black);
    pen.setWidth(2);
    int     centerX= scene->width() / 2,
            centerY = scene->height() / 2;
    double iter = 2 * 3.1415 / matrix.size();
    for (int i = 0; i < matrix.size(); i++){
        for (int j = 0; j < matrix.size(); j++){
            if (GetWeight(i, j) > 0){
                int     vert_1_x = centerX + cos(iter * i) * radiusB,
                        vert_1_y = centerY - sin(iter * i) * radiusB,
                        vert_2_x = centerX + cos(iter * j) * radiusB,
                        vert_2_y = centerY - sin(iter * j) * radiusB;
                scene->addLine(vert_1_x, vert_1_y, vert_2_x, vert_2_y, pen);
                QGraphicsTextItem *number = scene->addText(QString::number(GetWeight(i, j)), QFont("Times", 14));
                number->setPos((vert_2_x + vert_1_x) / 2, (vert_2_y + vert_1_y) / 2);
            }
        }
    }
}

void Graph::DrawArrows(QGraphicsScene* scene) //отрисовка стрелок
{
    QPen pen(Qt::black);
    pen.setWidth(2);
    int     centerX= scene->width() / 2,
            centerY = scene->height() / 2;
    int r1 = radiusA / 3;
    double len = 15.0;
    double ostr = 0.35;
    double arr_x, arr_y;
    double iter = 2 * 3.1415 / matrix.size();
    for (int i = 0; i < matrix.size(); i++){
        for (int j = 0; j < matrix.size(); j++){
            if (GetWeight(i, j) > 0){
                int     vert_1_x = centerX + cos(iter * i) * radiusB,
                        vert_1_y = centerY - sin(iter * i) * radiusB,
                        vert_2_x = centerX + cos(iter * j) * radiusB,
                        vert_2_y = centerY - sin(iter * j) * radiusB;
                double angle = atan2(((double)vert_2_y - vert_1_y), ((double)(vert_2_x - vert_1_x)));
                //double t = radiusA / sqrt((vert_2_x - vert_1_x) * (vert_2_x - vert_1_x) + (vert_2_y - vert_1_y) * (vert_2_y - vert_1_y));
                arr_x = (vert_2_x - (radiusA * cos(angle))) - (len * cos(angle + ostr));
                arr_y = (vert_2_y - (radiusA * sin(angle))) - (len * sin(angle + ostr));
                scene->addLine(vert_2_x - (radiusA * cos(angle)), vert_2_y - (radiusA * sin(angle)), arr_x, arr_y, pen);
                arr_x = (vert_2_x - (radiusA * cos(angle))) - (len * cos(angle - ostr));
                arr_y = (vert_2_y - (radiusA * sin(angle))) - (len * sin(angle - ostr));
                scene->addLine(vert_2_x - (radiusA * cos(angle)), vert_2_y - (radiusA * sin(angle)), arr_x, arr_y, pen);
            }
        }
    }
}

void Graph::DrawNodes(QGraphicsScene* scene) //отрисовка вершин графа
{
    QPen pen(Qt::black);
    pen.setWidth(3);
    int     centerX= scene->width() / 2,
            centerY = scene->height() / 2;
    double iter = 2 * 3.1415 / matrix.size();
    for (int i = 0; i < matrix.size(); i++){
        scene->addEllipse(centerX + cos(iter * i) * radiusB - radiusA,
                          centerY - sin(iter * i) * radiusB - radiusA, 2*radiusA, 2*radiusA,
                          pen, QBrush(QColor(193,251,227)));

        QGraphicsTextItem *number = scene->addText(QString::number(i+1), QFont("Times", 14));
        number->setPos(centerX + cos(iter * i) * radiusB - radiusA + 18,
                       centerY - sin(iter * i) * radiusB - radiusA + 10);
    }
}


void Graph::DrawGraph(QGraphicsScene* scene) //отрисовка графа
{
    DrawLines(scene);
    DrawArrows(scene);
    DrawNodes(scene);
}

void Graph::Draw() //отрисовка сцены с графом
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 700, 630);

    ui->graphicsView->setScene(scene);
    scene->clear();
    scene->setBackgroundBrush(QBrush(QColor(214,237,255), Qt::SolidPattern));
    ui->label_komi->setText(Dejkstra());
    DrawGraph(scene);
}

Graph::Graph(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Graph)
{
    ui->setupUi(this);
    kol = 6;
    matrix = { {0, 14, 0, 0, 0, 0 },
               {0, 0, 0, 0, 42, 23 },
               {19, 0, 0, 9, 0, 0 },
               {0, 0, 0, 0, 0, 31 },
               {0, 0, 18, 0, 0, 0 },
               {28, 23, 0, 0, 0, 0 } };
    Draw();
}

Graph::~Graph()
{
    delete ui;
}
