#include "encoder.h"
#include "ui_enigma.h"

encoder::encoder(QWidget *parent) 
	: QWidget(parent)
{
	qr = NULL;
}

encoder::~encoder()
{
	if (qr != NULL)
	{
		QRcode_free(qr);
	}
}

bool encoder::saveImage(QString fileName) // 保存图片名（使用完整路径），保存图片大小为size*size 像素
{
	if (!fileName.isEmpty())
	{
		int qr_width = qr->width > 0 ? qr->width : 1;
		qr_width *= 4;
		QImage image(qr_width, qr_width, QImage::Format_Mono);
		QPainter painter(&image);
		QColor background(Qt::white);
		painter.setBrush(background);
		painter.setPen(Qt::NoPen);
		painter.drawRect(0, 0, qr_width, qr_width);
		if (qr != NULL)
		{
			draw(painter, qr_width, qr_width);
		}
		return image.save(fileName);
	}
	else
	{
		return false;
	}
}

void encoder::generateString(QString str) // 生成二维码数据结构
{
	string = str;
	if (qr != NULL)
	{
		QRcode_free(qr);
	}
	qr = QRcode_encodeString(string.toStdString().c_str(),
		1,
		QR_ECLEVEL_H,
		QR_MODE_8,
		1);
	update();

}

void encoder::draw(QPainter &painter, int width, int height) // 绘制二维码图像
{
	QColor foreground(Qt::black);
	painter.setBrush(foreground);
	const int qr_width = qr->width > 0 ? qr->width : 1;
	double scale_x = width / qr_width;
	double scale_y = height / qr_width;
	for (int y = 0; y < qr_width; y++)
	{
		for (int x = 0; x < qr_width; x++)
		{
			unsigned char b = qr->data[y * qr_width + x];
			if (b & 0x01)
			{
				QRectF r(x * scale_x, y * scale_y, scale_x, scale_y);
				painter.drawRects(&r, 1);
			}
		}
	}
}

void encoder::paintEvent(QPaintEvent *) // 设置画布
{
	QPainter painter(this);
	QColor background(Qt::white);
	painter.setBrush(background);
	painter.setPen(Qt::NoPen);
	painter.drawRect(0, 0, width(), height());
	if (qr != NULL)
	{
		int qr_width = qr->width > 0 ? qr->width : 1;
		draw(painter, qr_width, qr_width);
	}
}