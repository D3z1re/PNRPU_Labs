#ifndef GRAPH_H
#define GRAPH_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPen>
#include <QBrush>
#include <QFont>
#include <QString>
#include <QGraphicsTextItem>
#include <vector>


QT_BEGIN_NAMESPACE
namespace Ui { class Graph; }
QT_END_NAMESPACE

//int MAX_SIZE = 20;

class Graph : public QMainWindow
{
    Q_OBJECT

private:
    Ui::Graph *ui;
    QGraphicsScene *scene;

public:
    int kol;
    std::vector<std::vector<int>> matrix;
    int result[6] = { INT_MAX, INT_MAX, INT_MAX, INT_MAX,INT_MAX, INT_MAX };
    bool visited[6] = { 0, 0, 0, 0, 0, 0 };

    Graph(QWidget *parent = nullptr);
    ~Graph();
    int GetWeight(const int vert1, const int vert2);
    void DrawLines(QGraphicsScene* scene);
    void DrawArrows(QGraphicsScene* scene);
    void DrawNodes(QGraphicsScene* scene);
    void DrawGraph(QGraphicsScene* scene);
    QString Dejkstra();
    void Draw();
private slots:
};
#endif // GRAPH_H
