#ifndef KEYFRAMEVIEW_H
#define KEYFRAMEVIEW_H

#include <QGraphicsView>

#include "common/rational.h"
#include "core.h"
#include "keyframeviewitem.h"
#include "widget/timelinewidget/view/timelineviewbase.h"

class KeyframeView : public TimelineViewBase
{
  Q_OBJECT
public:
  KeyframeView(QWidget* parent = nullptr);

  void Clear();

public slots:
  void AddKeyframe(NodeKeyframePtr key, int y);

  void RemoveKeyframe(NodeKeyframePtr key);

protected:
  virtual void mousePressEvent(QMouseEvent *event) override;
  virtual void mouseMoveEvent(QMouseEvent *event) override;
  virtual void mouseReleaseEvent(QMouseEvent *event) override;

  virtual void ScaleChangedEvent(double scale) override;

private:
  struct KeyframeItemAndTime {
    KeyframeViewItem* key;
    qreal item_x;
    rational time;
  };

  QMap<NodeKeyframe*, KeyframeViewItem*> item_map_;

  Tool::Item active_tool_;

  QPoint drag_start_;

  QVector<KeyframeItemAndTime> selected_keys_;

private slots:
  void ShowContextMenu();

  void ApplicationToolChanged(Tool::Item tool);

};

#endif // KEYFRAMEVIEW_H