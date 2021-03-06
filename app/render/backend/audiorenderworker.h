#ifndef AUDIORENDERWORKER_H
#define AUDIORENDERWORKER_H

#include "renderworker.h"

class AudioRenderWorker : public RenderWorker
{
  Q_OBJECT
public:
  AudioRenderWorker(DecoderCache* decoder_cache, QHash<Node*, Node*>* copy_map, QObject* parent = nullptr);

  void SetParameters(const AudioRenderingParams& audio_params);

signals:
  void ConformUnavailable(StreamPtr stream, const TimeRange& range, const rational& stream_time, const AudioRenderingParams& params);

protected:
  virtual bool InitInternal() override;

  virtual void CloseInternal() override;

  virtual NodeValueTable RenderBlock(const TrackOutput *track, const TimeRange& range) override;

  const AudioRenderingParams& audio_params() const;

private:
  AudioRenderingParams audio_params_;

  QHash<Node*, Node*>* copy_map_;

};

#endif // AUDIORENDERWORKER_H
