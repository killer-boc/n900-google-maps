#ifndef GOOGLEMAPWIDGET_H_
#define GOOGLEMAPWIDGET_H_

#include <QtCore>
#include <QtOpenGL>

class GoogleMapWidget : public QGLWidget
{
	Q_OBJECT

	public:
		GoogleMapWidget(QWidget *parent = 0);

		QImage tile;

		QPoint translation;
		QPoint dragStart;

		QTimer timer;

	protected slots:
		void paintGL();

		void mousePressEvent(QMouseEvent* );

		void mouseMoveEvent(QMouseEvent* );

		void initializeGL();

	private:
		GLuint shaderProgram;
		GLuint textureId;
};

#endif
