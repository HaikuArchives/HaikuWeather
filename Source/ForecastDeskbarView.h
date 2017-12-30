/*
 * Copyright 2017 Benjamin Amos
 * All rights reserved. Distributed under the terms of the MIT license.
 */
#ifndef FORECASTDESKBARVIEW_H
#define FORECASTDESKBARVIEW_H

#include <SupportDefs.h>
#include <View.h>
#include <Bitmap.h>
#include <MessageRunner.h>
#include <Looper.h>

#include "ForecastView.h"

class ForecastDeskbarView : public BView, private BLooper
{
public:
	ForecastDeskbarView(BRect viewSize, ForecastView* forecastView);
	ForecastDeskbarView(BMessage* archive);
	~ForecastDeskbarView();
	virtual void AttachedToWindow();
	virtual void OnMouseUp(BPoint point);
	virtual void OnMouseMove(BPoint point);
	virtual void Draw(BRect drawRect);
	virtual void MessageReceived(BMessage* message);
	virtual status_t	Archive(BMessage* into, bool deep = true) const;
	static BArchivable*	Instantiate(BMessage* archive);
private:
	ForecastView* fForecastView;
	BMessageRunner* fMessageRunner;
	bool fSendToolTip;
};


#endif // FORECASTDESKBARVIEW_H
