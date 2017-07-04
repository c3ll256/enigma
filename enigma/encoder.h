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
	void generateString(QString str); // �ı�����
	bool saveImage(QString fileName); // ����ͼƬ��·�����Լ���С
private:
	Ui::encoder *ui;
	void draw(QPainter &painter, int width, int height);
	QString string;
	QRcode *qr;

protected:
	void paintEvent(QPaintEvent *);

};

#endif // encoder_H