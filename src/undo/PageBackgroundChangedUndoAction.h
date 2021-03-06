/*
 * Xournal++
 *
 * Undo action for background change
 *
 * @author Xournal Team
 * http://xournal.sf.net
 *
 * @license GPL
 */

#ifndef __PAGEBACKGROUNDCHANGEDUNDOACTION_H__
#define __PAGEBACKGROUNDCHANGEDUNDOACTION_H__

#include "UndoAction.h"
#include "../model/PageRef.h"
#include "../model/BackgroundImage.h"

class PageBackgroundChangedUndoAction: public UndoAction {
public:
	PageBackgroundChangedUndoAction(PageRef page, BackgroundType origType, int origPdfPage,
			BackgroundImage origBackgroundImage, double origW, double origH);
	virtual ~PageBackgroundChangedUndoAction();

public:
	virtual bool undo(Control * control);
	virtual bool redo(Control * control);

	virtual String getText();

private:
	XOJ_TYPE_ATTRIB;

	BackgroundType origType;
	int origPdfPage;
	BackgroundImage origBackgroundImage;
	double origW;
	double origH;

	BackgroundType newType;
	int newPdfPage;
	BackgroundImage newBackgroundImage;
	double newW;
	double newH;
};

#endif /* __PAGEBACKGROUNDCHANGEDUNDOACTION_H__ */
