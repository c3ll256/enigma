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
	void generateString(QString str); // 文本内容
	bool saveImage(QString fileName, int size = 252); // 保存图片的路径，以及大小为252*252像素
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