#ifndef LEVELBASE_H
#define LEVELBASE_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>

class LevelBase : public QObject
{
    Q_OBJECT

public:
    explicit LevelBase(QObject *parent = nullptr);
    virtual ~LevelBase();

    QGraphicsScene* getScene() const;
    QGraphicsView* getView() const;

public slots:
    virtual void initializeLevel() = 0;

signals:
    void levelCompleted();

protected:
    QGraphicsScene *scene;
    QGraphicsView *view;
};

#endif // LEVELBASE_H
