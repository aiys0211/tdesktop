/*
This file is part of Telegram Desktop,
the official desktop application for the Telegram messaging service.

For license and copyright information please follow this link:
https://github.com/telegramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

#include "history/view/media/history_view_media_unwrapped.h"
#include "history/view/media/history_view_sticker.h"

namespace HistoryView {

class Dice final : public UnwrappedMedia::Content {
public:
	Dice(not_null<Element*> parent, int value);
	~Dice();

	QSize size() override;
	void draw(Painter &p, const QRect &r, bool selected) override;

	void clearStickerLoopPlayed() override {
		_lottieOncePlayed = false;
	}
	void unloadHeavyPart() override {
		_start.unloadHeavyPart();
		if (_end) {
			_end->unloadHeavyPart();
		}
	}

private:
	const not_null<Element*> _parent;
	std::optional<Sticker> _end;
	Sticker _start;
	int _value = 0;
	mutable bool _lottieOncePlayed = false;
	mutable bool _drawingEnd = false;

};

} // namespace HistoryView