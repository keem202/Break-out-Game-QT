#include "levelbase.h"

LevelBase::LevelBase(QObject *parent) : QObject(parent), scene(nullptr), view(nullptr)
{
    // Initialize member variables
    scene = new QGraphicsScene(this); // Create a new QGraphicsScene
    view = new QGraphicsView(scene);  // Create a new QGraphicsView with the scene

    // Set up the view
    view->setRenderHint(QPainter::Antialiasing); // Enable antialiasing for smoother graphics
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Disable horizontal scroll bar
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   // Disable vertical scroll bar

    // Set the view's background color (optional)
    scene->setBackgroundBrush(Qt::black); // Set the background color to black
}

LevelBase::~LevelBase()
{
    // Clean up allocated resources
    delete view;
    // scene is automatically deleted because QGraphicsScene has the parent set to 'this' (LevelBase)
}

QGraphicsScene* LevelBase::getScene() const
{
    return scene;
}

QGraphicsView* LevelBase::getView() const
{
    return view;
}
