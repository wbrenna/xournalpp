#include "ToolPageSpinner.h"

#include "../GladeGui.h"

#include "../widgets/SpinPageAdapter.h"

#include <config.h>
#include <glib/gi18n-lib.h>

ToolPageSpinner::ToolPageSpinner(GladeGui * gui, ActionHandler * handler, String id, ActionType type) :
	AbstractToolItem(id, handler, type, NULL) {

	XOJ_INIT_TYPE(ToolPageSpinner);

	this->gui = gui;

	this->pageSpinner = new SpinPageAdapter();
	this->lbPageNo = NULL;
}

ToolPageSpinner::~ToolPageSpinner() {
	XOJ_CHECK_TYPE(ToolPageSpinner);

	delete this->pageSpinner;
	this->pageSpinner = NULL;

	XOJ_RELEASE_TYPE(ToolPageSpinner);
}

SpinPageAdapter * ToolPageSpinner::getPageSpinner() {
	XOJ_CHECK_TYPE(ToolPageSpinner);

	return pageSpinner;
}

void ToolPageSpinner::setText(String text) {
	XOJ_CHECK_TYPE(ToolPageSpinner);

	if (lbPageNo) {
		gtk_label_set_text(GTK_LABEL(lbPageNo), text.c_str());
	}
}

String ToolPageSpinner::getToolDisplayName() {
	XOJ_CHECK_TYPE(ToolPageSpinner);

	return _("Page number");
}

GtkWidget * ToolPageSpinner::getNewToolIconImpl() {
	XOJ_CHECK_TYPE(ToolPageSpinner);

	return this->gui->loadIcon("pageSpinner.png");
}

GtkToolItem * ToolPageSpinner::newItem() {
	XOJ_CHECK_TYPE(ToolPageSpinner);

	GtkToolItem * it = gtk_tool_item_new();

	GtkWidget * hbox = gtk_hbox_new(false, 1);
	gtk_box_pack_start(GTK_BOX(hbox), gtk_label_new(_("Page")), false, false, 7);

	gtk_box_pack_start(GTK_BOX(hbox), this->pageSpinner->getWidget(), false, false, 0);

	this->lbPageNo = gtk_label_new("");
	gtk_box_pack_start(GTK_BOX(hbox), this->lbPageNo, false, false, 0);

	gtk_container_add(GTK_CONTAINER(it), hbox);

	return it;
}

