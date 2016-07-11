#include "widgets/ClickAwareLabel.h"

#include <QMouseEvent>

ClickAwareLabel::ClickAwareLabel(QWidget* parent) : QLabel(parent) {
	//
}

ClickAwareLabel::~ClickAwareLabel() {
	//
}

void ClickAwareLabel::mousePressEvent(QMouseEvent* event) {
	if (event->buttons() == Qt::LeftButton) {
		emit clicked();
	}

	QLabel::mousePressEvent(event);
}
