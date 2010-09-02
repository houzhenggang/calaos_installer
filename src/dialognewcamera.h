#ifndef DIALOGNEWCAMERA_H
#define DIALOGNEWCAMERA_H

#include <QtGui/QDialog>
#include <iostream>

#include <ListeRoom.h>
using namespace std;
using namespace Calaos;

namespace Ui
{
        class DialogNewCamera;
}

class DialogNewCamera : public QDialog
{
                Q_OBJECT
                Q_DISABLE_COPY(DialogNewCamera)
        public:
                explicit DialogNewCamera(Room *room, QWidget *parent = 0);
                virtual ~DialogNewCamera();

                Output *getOutput() { return output; }

        protected:
                virtual void changeEvent(QEvent *e);

        private:
                Ui::DialogNewCamera *ui;
                Output *output;
                Room *room;

        private slots:
                void on_buttonBox_accepted();
};

#endif // DIALOGNEWCAMERA_H