#ifndef encoder_H
#define encoder_H

#include <QWidget>
#include "qrencode.h"
#include <QPainter>

namespace Ui {
	class encoder;
}

class encoder : public QWidget
{
	Q_OBJECT

public:
	explicit encoder(QWidget *parent = 0);
	~encoder();
	void generateString(QString str);
	bool saveImage(QString fileName, int size = 250);
private:
	Ui::encoder *ui;
	void draw(QPainter &painter, int width, int height);
	QString string;
	QRcode *qr;

protected:
	void paintEvent(QPaintEvent *);
	QSize sizeHint() const;
	QSize minimumSizeHint() const;

};

#endif // encoder_H