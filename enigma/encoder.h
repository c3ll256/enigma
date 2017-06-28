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
	bool saveImage(QString fileName); // 保存图片的路径，以及大小
private:
	Ui::encoder *ui;
	void draw(QPainter &painter, int width, int height);
	QString string;
	QRcode *qr;

protected:
	void paintEvent(QPaintEvent *);

};

#endif // encoder_H